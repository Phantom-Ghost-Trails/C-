#include <SFML/Graphics.hpp>
using namespace sf;

const int WinWidth = 1024;
const int WinHeight = 768;
const int roadWidth = 1800;
const int roadSeglength = 180;
const int roadCount = 1884;

struct Road {
    float x, y, z;
    float X, Y, W;
    float scale,curve;

    Road(int _x, int _y, int _z,float _c) : x(_x), y(_y), z(_z), curve(_c) {}

    void project(int camX, int camY, int camZ) {
        scale = 1.0 / (z - camZ);
        X = (1 + (x - camX) * scale) * WinWidth / 2;
        Y = (1 - (y - camY) * scale) * WinHeight / 2;
        W = scale * roadWidth * WinWidth / 2;
    }
};

void DrawTrape(RenderWindow& window, Color c, int x1, int y1, int w1, int x2, int y2, int w2) {
    ConvexShape polygon(4);
    polygon.setFillColor(c);
    polygon.setPoint(0, Vector2f(x1 - w1, y1));
    polygon.setPoint(1, Vector2f(x2 - w2, y2));
    polygon.setPoint(2, Vector2f(x2 + w2, y2));
    polygon.setPoint(3, Vector2f(x1 + w1, y1));
    window.draw(polygon);
}

int main() {
    RenderWindow window(VideoMode(WinWidth, WinHeight), "Racing");
    window.setFramerateLimit(60);
    Texture bg;
    bg.loadFromFile("cloud.png");
    Sprite s(bg, IntRect(0, 0, WinWidth, WinHeight / 2));
    std::vector<Road> roads;
    for (int i = 0; i < roadCount; i++) {
        float curve = (i > 0 && i < 300) ? 0.5 : -0.5;
        Road r(0, 1600 * sin(i / 30.0), (i + 1) * roadSeglength, curve);
        roads.push_back(r);
    }
    int camearaX = 0;
    int camearaY = 1600;
    int camearaZ  = 0;
    int speed = 100;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)){
            speed += 2;
            if (speed > 1000) speed = 1000;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)){
            speed -= 2;
            if (speed < 100) speed = 100;
        }
        camearaZ += speed;
        if (Keyboard::isKeyPressed(Keyboard::Left)) camearaX -= 100;
        if (Keyboard::isKeyPressed(Keyboard::Right)) camearaX += 100;
        int totalLenght = roadCount * roadSeglength;
        if(camearaZ >= totalLenght) camearaZ -= totalLenght;
        if(camearaZ < 0) camearaZ += totalLenght;
        window.clear();
        int roadIndex = camearaZ / roadSeglength;
        float x = 0, dx = 0;
        camearaY = 1600 + roads[roadIndex].y;
        int minY = WinHeight;
        for (int i = roadIndex; i < roadIndex + 300; i++) {
            Road& now = roads[i % roadCount];
            now.project(camearaX - x, camearaY, camearaZ - (i >=roadCount ? totalLenght : 0));
            x += dx;
            dx += now.curve;
            if (!i) {
                continue;
            }
            if (now.Y < minY) {
                minY = now.Y;
            }
            else {
                continue;
            }
            s.setTextureRect(IntRect(0, 0, WinWidth, minY));
            window.draw(s);
            Road& pre = roads[(i - 1) % roadCount];
            Color edge = (i  / 3) % 2 ? Color(0, 0, 0) : Color(255, 255, 255);
            Color grass = (i / 3) % 2 ? Color(16,210,16) : Color(0,199,0);
            Color road = i % 2 ? Color(105, 105, 105) : Color(101, 101, 101);
            DrawTrape(window, grass, pre.X, pre.Y, WinWidth*10, now.X, now.Y, WinWidth*10);
            DrawTrape(window, edge, pre.X, pre.Y, pre.W * 1.3, now.X, now.Y, now.W * 1.3);
            DrawTrape(window, road, pre.X, pre.Y, pre.W, now.X, now.Y, now.W);

        }
        window.display();
    }

    return 0;
}