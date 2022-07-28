#include <iostream>
using namespace std;

struct Teacher{

    int index;
    int age;
};

// C++对于const常量，会存放在符号表中，如果对其取地址时，编辑器会为其单独开辟一个空间
// 而后通过指针间接改变值 并不能修改到原来的常量，而是新开辟的空间的值

int main01(){

    cout<<"Hello World!"<<endl;
    const int a = 20;
    int* p = NULL;
    p = (int*)&a;
    *p = 28;

    cout<<"a:"<<a<<"\n*P:"<<*p<<endl;

    system("pause");
    return 0;
}

// 引用其实就相当于 常量指针，(int& a) == (int* const a)，名称不可变
// 函数返回引用
int add(int& n){
    n++;
    int a = n;
    return a;
}

int add02(){
    static int a = 28;
    return a;
}

int& add03(){
    static int a = 28;
    return a;
}

int main(){

    int n = 16;
    int m = add(n);
    cout << "n:" << n << ", m:" << m << endl;

    int c = add02();
    cout << "c:" << c << endl;

    int& d = add03();
    cout << "d:" << d << endl;
    //引用当左值
    add03() = 16;
    cout << "d:" << d << endl;

    system("pause");
    return 0;
}