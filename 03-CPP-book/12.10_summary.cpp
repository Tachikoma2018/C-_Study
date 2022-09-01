/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 1、构造函数使用定位new时需要显式调用析构
                  2、构造函数没使用new，但成员函数使用new，且delete不在同一函数中，需要定义 显示析构函数释放所有内存
                  3、链表结构
        *包含头文件：Queue0.h
        *其定义文件：Queue0.cpp
*******************************************/
#include<iostream>
#include"Queue0.h"

#define MAXLEN 80

int main(){

    using namespace std;
    char* buffer = new char [MAXLEN];
// 1、
    {
        Custom cus1("Lucrezia Donati");
        Custom cus2("Leonardo Da Vinci");
        Custom* pcus1 = new(buffer) Custom;
        *pcus1 = cus2;
        Custom* pcus2 = new(buffer+sizeof(Custom)) Custom("Nerisateb");
        // 使用完后，使用定位new创建的对象进行析构，需要显式地调用才行
        pcus2->~Custom();
        pcus1->~Custom();
    }
    delete [] buffer;

// 2、



// 3、链表

    cout<<"Done!"<<endl;


    system("pause");
    return 0;
}