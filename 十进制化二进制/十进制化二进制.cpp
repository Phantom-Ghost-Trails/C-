#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    long long num;
    string zh = "";

    cout << "十进制化二进制器" << endl;
    cout << "请输入你要转换的数字: ";
    cin >> num;

    if (num == 0) {
        cout << "0" << endl;
        return 0;
    }
    while (num > 0)
    {
        int yy = num % 2;
        num /= 2;
        zh += (yy == 1 ? "1" : "0");
    }
    reverse(zh.begin(), zh.end());
    cout << "二进制表示为: "<<"("<<zh<<")2"<<endl;

    return 0;
}

