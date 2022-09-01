/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 1、构造函数使用定位new时需要显式调用析构
                  2、构造函数没使用new，但成员函数使用new，且delete不在同一函数中，需要定义 显示析构函数释放所有内存
                  3、链表结构
        *定义程序文件：Queue0.cpp
        *执行程序文件：
*******************************************/
#include<iostream>
#include<cstring>
#include"Queue0.h"

Custom::Custom(){
    name = new char[1];
    name[0]='\0';
    position=0;
    std::cout<<">Default Constructor called.\n";
}
Custom::Custom(const char* ss):position(strlen(ss)){
    name = new char[position+1];
    strcpy(name,ss);
    std::cout<<">Constructed "<<name<<" object.\n";
}
Custom::Custom(const Custom& cus):position(cus.position){
    int len = strlen(cus.name);
    name = new char[len+1];
    strcpy(name,cus.name);
    std::cout<<">Constructed "<<name<<" object.\n";
}
Custom::~Custom(){
    std::cout<<">Deconstructed "<<name<<" object.\n";
    delete [] name;
}
Custom& Custom::operator=(const Custom& cus){
    if(this == &cus)
        return *this;
    delete [] name;
    position = cus.position;
    name = new char[position+1];
    strcpy(name,cus.name);
    return *this;
}
Custom& Custom::operator=(const char* ss){
    delete [] name;
    position = strlen(ss);
    name = new char[position+1];
    strcpy(name,ss);
    return *this;
}


// 3、链表
Queue::Queue(int qs):front(nullptr),rear(nullptr),qsize(qs),items(0){
    // 创建空链表，并初始化
}

bool Queue::enque(const Item& item){
    if(isfull())
        return false;
    // temp Node obj -> add
    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if(front==nullptr)
        front = add;
    else
        rear->next = add;// old rear
    rear = add;// new rear
    return true;
}
bool Queue::deque(Item& item){
    if(isempty())
        return false;

    item = front->item;
    --items;
    // 释放列首前，先拷贝一份
    Node* temp = front;
    front = front->next;
    delete temp;
    if(items==0)
        rear = nullptr;
    return true;
}
// 显式析构函数，不同成员函数使用 new & delete，不能保证一一对应，故须在此释放全部(如果存在剩余)
Queue::~Queue(){
    Node* temp;
    while(front!=nullptr){
        // 存储 front 先
        temp = front;
        front = front->next;
        delete temp;
    }
}