#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    long long num;
    string zh = "";

    cout << "ʮ���ƻ���������" << endl;
    cout << "��������Ҫת��������: ";
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
    cout << "�����Ʊ�ʾΪ: "<<"("<<zh<<")2"<<endl;

    return 0;
}

