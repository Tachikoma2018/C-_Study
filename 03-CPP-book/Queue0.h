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
#ifndef _QUEUE0_H_
#define _QUEUE0_H_


class Custom{
private:
    char* name;
    int position;
public:
    Custom();
    Custom(const char* ss);
    Custom(const Custom& cus);
    ~Custom();
    Custom& operator=(const Custom& cus);
    Custom& operator=(const char* ss);
};

typedef Custom Item;


class Queue{
private:
    struct Node{
        Item item;
        struct Node* next;
    };
    enum {Q_SIZE = 10};
    Node* front;
    Node* rear;
    const int qsize;
    int items;
    // 预防性定义，将 拷贝构造函数 & 赋值运算符重载 设为 private，这样 对象就不可以被 复制 & 赋值 了。
    Queue(const Queue& qline);
    Queue& operator=(const Queue& qline);
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const { return qsize==0; };
    bool isfull() const { return qsize==Q_SIZE; };

    bool enque(const Item& item);
    bool deque(Item& item);

};

#endif