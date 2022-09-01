/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 模板作为参数
        *包含头文件：StackTP.h
        *其定义文件：
*******************************************/
#include<iostream>
#include"StackTP.h"

template< template<typename T> class Thing>
class Crab{
private:
    Thing<int> s1;// 告诉编译器 使用 template<int>
    Thing<double> s2;// template<double>
public:
    ~Crab(){}
    bool push(int a,double b) { return s1.push(a) && s2.push(b); }
    bool pop(int& a,double& b) { return s1.pop(a) && s2.pop(b); }
};

int main(){

    using namespace std;

    Crab<Stack> nebula; // Stack must match "template<typename T> class"
    int ni;
    double nb;
    cout<<"Enter (int,double) pairs, such as 4 3.5 (0 0 to terminate):\n";
    while(cin>>ni>>nb && ni!=0 && nb!=0.0){
        if(!nebula.push(ni,nb))
            break;
    }

    while (nebula.pop(ni,nb)) {
        cout<<ni<<" "<<nb<<endl;
    }

    cout<<"Done!"<<endl;

    system("pause");
    return 0;
}