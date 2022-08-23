/*******************************************
 *FileName:
 *Author: Nerisateb
 *Version: 0.0.1
 *Date:
 *Description:
 *包含头文件：String0.h
 *其定义文件：String0.cpp
 *******************************************/
#include <iostream>
#include "String0.h"

int main()
{

    using namespace std;
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string \"" << s2 << "\" contains " << s2.has('A') << " 'A' characters in it.\n";
    s1 = "red";

    String rgb[3] = { String(s1), String("green"), String("blue") };
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow();
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout<<">>>Totally created "<<String::howmany()<<" objects.\n";
    cout << "Done!" << endl;

    system("pause");
    return 0;
}