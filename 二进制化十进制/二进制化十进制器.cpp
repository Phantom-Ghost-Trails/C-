#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string binaryStr;
    long long decimalValue = 0;

    cout << "二进制化十进制器" << endl;
    cout << "请输入你要转换的二进制数字: ";
    cin >> binaryStr;
    int length = binaryStr.length();
    for (int i = 0; i < length; ++i)
    {
        if (binaryStr[length - i - 1] == '1')
        {
            decimalValue += pow(2, i);
        }
    }
    cout << "十进制表示为: " << decimalValue << endl;

    return 0;
}

