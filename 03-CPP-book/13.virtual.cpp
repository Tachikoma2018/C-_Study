/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *包含头文件：
        *其定义文件：
*******************************************/
#include<iostream>
#include<string>
#include"AcctABC.h"

const int CLIENTS = 4;

int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    // 虚基类没有对象
    AccABC* p_clients[CLIENTS];
    string init_str;
    long init_num;
    double init_bal;
    char flag;
    unsigned i;
    for(i=0;i<CLIENTS;i++){
        cout<<">>>Enter client's name: ";
        getline(cin,init_str);
        cout<<"Enter client's account number: ";
        cin>>init_num;
        cout<<"Enter client's balance: $";
        cin>>init_bal;
        cout<<"Enter 1 for normal Brass account, 2 for BrassPlus account, q/Q to quit: ";
        if(cin>>flag){
            if(flag=='q' || flag=='Q')
                break;
            else if(flag=='1')
                p_clients[i] = new Brass(init_str,init_num,init_bal);
            else if(flag=='2') {
                double tmax, trate;
                cout<<"Enter the overdraft limit: ";
                cin>>tmax;
                cout<<"Enter the interest rate(as a decimal fraction): ";
                cin>>trate;
                p_clients[i] = new BrassPlus(init_str,init_num,init_bal,tmax,trate);
            }
            else{
                cout<<">>>Invalid choice, please enter 1 or 2."<<endl;
                i--;
            }
        }
        cout<<endl;
        while(cin.get()!='\n')
            continue;
    }

    if(i==0)
        cout<<">>>No client.\n";
    else{
        for(int k=0;k<i;k++){
            p_clients[k]->AcctView();
        }

        // withdraw operation


        for(int j=0;j<i;j++){
            delete p_clients[j];
        }
    }

    cout<<"Done!"<<endl;

    system("pause");
    return 0;
}