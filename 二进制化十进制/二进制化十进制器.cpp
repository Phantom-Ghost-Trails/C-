#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string binaryStr;
    long long decimalValue = 0;

    cout << "�����ƻ�ʮ������" << endl;
    cout << "��������Ҫת���Ķ���������: ";
    cin >> binaryStr;
    int length = binaryStr.length();
    for (int i = 0; i < length; ++i)
    {
        if (binaryStr[length - i - 1] == '1')
        {
            decimalValue += pow(2, i);
        }
    }
    cout << "ʮ���Ʊ�ʾΪ: " << decimalValue << endl;

    return 0;
}

