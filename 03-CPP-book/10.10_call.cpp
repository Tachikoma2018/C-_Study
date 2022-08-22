/*******************************************
 *FileName:
 *Author: Nerisateb
 *Version: 0.0.1
 *Date:
 *Description:
 *******************************************/
#include <iostream>
#include <cctype>
#include "10.10.h"

int main()
{

    using namespace std;

    Plorg pp1 = Plorg();
    pp1.show();
    Plorg pp2("Lucrezia", 28);
    pp2.show();
    Plorg pp3{"Leonardo", 16};
    Plorg pp4 = pp3;
    pp4.revalue(46);
    pp4.show();

    //===========================================

    Item temp;
    Stack stk;
    cout << "A to push a value into stack, P to pop a value out stack, Q to quit: ";
    char c;
    while (cin >> c && toupper(c)!='Q'){
        while(cin.get()!='\n')
            continue;
        if(!isalpha(c)){
            cout<<"Invalid input, type again: ";
            continue;
        }

        switch(c){
            case 'A':
            case 'a':   cout<<"\t"<<"enter the value: ";
                        cin>>temp;
                        stk.push(temp);
                        break;
            case 'P':
            case 'p':   stk.pop(temp);
                        break;
        }
        cout << "A to push a value into stack, P to pop a value out stack, Q to quit: ";
    }

    cout << "Done!" << endl;

    system("pause");
    return 0;
}