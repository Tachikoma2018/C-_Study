/*******************************************
 *FileName:
 *Author: Nerisateb
 *Version: 0.0.1
 *Date:
 *Description: 定义一个复数类，重载 加法、减法、乘法（复数相乘 & 复数x实数）、共轭
    包含头文件：complex0.h
    其定义文件：complex0.cpp
*******************************************/
#include <iostream>
#include "complex0.h"

int main()
{

    using namespace std;
    Complex a(3.0, 4.0);
    Complex c;
    cout << ">>>Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is " << c << endl;
        cout << "complex conjugate is " << ~c << endl;
        cout << "a is " << a << endl;
        cout << "a+c is " << a + c << endl;
        cout << "a-c is " << a - c << endl;
        cout << "a*c is " << a * c << endl;
        cout << "2*c is " << 2 * c << endl;
        cout << ">>>Enter a complex number (q to quit):\n";
    }

    cout << "Done!" << endl;

    system("pause");
    return 0;
}