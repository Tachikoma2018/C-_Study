/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *包含头文件：
        *其定义文件：
*******************************************/
#include"AcctABC.h"
#include<iostream>

using std::cout;
using std::endl;

AccABC::AccABC(const std::string& str,long account, double bal){
    fullName = str;
    acctNum = account;
    balance = bal;
}
void AccABC::deposit(double amt){
    if(amt<0)
        cout<<">>>Negative amount to deposit, terminate transanction."<<endl;
    else
        balance += amt;
}
void AccABC::withdraw(double amt){
    if(amt<0)
        cout<<">>>Negative amount to withdraw, terminate transanction."<<endl;
    else
        balance -= amt;
}


void Brass::withdraw(double amt){
    if(amt <= Balance())
        AccABC::withdraw(amt);
    else
        cout<<">>>Balance < withdraw amount, terminate transanction."<<endl;
}
void Brass::AcctView() const{
    cout<<">>>Brass Client: "<<Fullname()<<endl;
    cout<<"Acctount Number: "<<AcctNum()<<endl;
    cout<<"Balance: "<<Balance()<<endl;
    cout<<endl;
}


BrassPlus::BrassPlus(const std::string &str, long account,double bal, double ml, double r):AccABC(str,account,bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}
BrassPlus::BrassPlus(const AccABC &abc, double ml, double r) : AccABC(abc)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}
void BrassPlus::withdraw(double amt){
    double bal = Balance();
    if(amt<=bal)
        AccABC::withdraw(amt);
    else if(amt <= bal+maxLoan-owesBank){ // notice here
        double margin = amt - bal;
        owesBank += margin*(1.0+rate);
        cout<<"Bank advance: $"<<margin<<endl;
        cout<<"Finance charge: $"<<margin*rate<<endl;
        deposit(margin);
        AccABC::withdraw(amt);
    }
    else
        cout<<">>>Balance < withdraw amount, terminate transanction."<<endl;
}
void BrassPlus::AcctView() const{
    cout<<">>>BrassPlus Client: "<<Fullname()<<endl;
    cout<<"Acctount: "<<AcctNum()<<endl;
    cout<<"Balance: $"<<Balance()<<endl;
    cout<<"Maximum Loan: $"<<maxLoan<<endl;
    cout<<"Owes to bank: $"<<owesBank<<endl;
    cout<<"Loan Rate: "<<100*rate<<"%"<<endl;
    cout<<endl;
}