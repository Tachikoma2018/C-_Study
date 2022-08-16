/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
*******************************************/
#include<iostream>
#include<limits>

// 7.13.1
void q_1_call();
double result(double,double);

// 13.5 递归 阶乘
int& recur(unsigned n,int&);

int main(){

    using namespace std;

    // q_1_call();

    // recursion
    unsigned n;
    int rst =1;
    cout<<">>>Enter a positive integer: ";
    while(cin>>n){
        cout<<n<<"!"<<" = "<<recur(n,rst)<<endl;
        cout<<">>>Enter another positive integer(q to quit): ";
        rst = 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Done!"<<endl;

    system("pause");
    return 0;
}

// 7.13.1
void q_1_call(){
    using namespace std;
    cout<<"Enter two number, using white space to separate. While anyone equals to 0, program will quit."<<endl;
    double a,b;
    while(cin>>a>>b && a!=0 && b!=0){
        cout<<result(a,b)<<endl;
        cout<<"Another pair: "<<endl;
    }

    cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
}

double result(double x,double y){
    return 2.0*x*y/(x+y);
}

// 7.13.5
int& recur(unsigned n, int& ret){
    if(n<=1){
        return ret;
    }
    ret *= n;
    recur(n-1,ret);
}
