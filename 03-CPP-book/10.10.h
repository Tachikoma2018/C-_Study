/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
*******************************************/
#ifndef _10_10_H_
#define _10_10_H_

class Plorg{
private:
    enum {MAXLEN=19};
    char plorg[MAXLEN];
    int CI;
public:
    Plorg(const char* ="Plorga",int = 20);
    ~Plorg(){};
    void show() const;
    void revalue(int);
};

typedef unsigned long Item;
class Stack{
private:
    // 数据数组、动态数组、链表等
    enum {MAX=10};
    Item items[MAX];
    int top;
public:
    Stack();
    ~Stack(){};
    bool isFull() const;
    bool isEmpty() const;
    void push(const Item&);
    void pop(Item&);
};

#endif