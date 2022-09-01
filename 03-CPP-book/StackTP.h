/*******************************************
 *FileName:
 *Author: Nerisateb
 *Version: 0.0.1
 *Date:
 *Description:
 *定义程序文件：
 *执行程序文件：StackTP.cpp
 *******************************************/
#ifndef _STACKTP_H_
#define _STACKTP_H_

#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
/*==========================================================*/
// 指针栈 模板
template<typename Type>
class StackTP{
private:
    enum { SIZE = 10 };
    Type* items;
    int top;
    int stacksize;
public:
    explicit StackTP(int ss = SIZE);
    StackTP(const StackTP& st);
    ~StackTP(){ delete [] items; }
    bool isempty() const { return top == 0; }
    bool isfull() const { return top == stacksize; }
    bool push(const Type& item);
    bool pop(Type& item);
    StackTP& operator=(const StackTP& st);
};

template<class Type>
StackTP<Type>::StackTP(int ss):top(0),stacksize(ss){
    items = new Type[stacksize];
}

template<class Type>
StackTP<Type>::StackTP(const StackTP& st):top(st.top),stacksize(st.stacksize){
    items = new Type[stacksize];
    for(int i=0;i<top;i++)
        items[i] = st.items[i];
}

template<class Type>
bool StackTP<Type>::push(const Type& item){
    if(top<stacksize){
        items[top++] = item;
        return true;
    } else{
        cout<<">StackTP: stack is full."<<endl;
        return false;
    }
}

template<class Type>
bool StackTP<Type>::pop(Type& item){
    if(top>0){
        item = items[--top];
        return true;
    } else {
        cout<<">StackTP: stack is empty."<<endl;
        return false;
    }
}

template<class Type>
StackTP<Type>& StackTP<Type>::operator=(const StackTP<Type>& st){
    if(this==&st)
        return *this;
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i=0;i<top;i++)
        items[i]=st.items[i];
    return *this;
}
/*==========================================================*/
// 栈 模板
template <class Type>
class Stack{
private:
    enum {MAX=10};
    Type items[MAX];
    int top;
public:
    Stack();
    bool isempty() const { return top == 0; }
    bool isfull() const { return top == MAX; }
    bool push(const Type& item);
    bool pop(Type& item);
};

template<class Type>
Stack<Type>::Stack():top(0){}

template<class Type>
bool Stack<Type>::push(const Type& item){
    if(top<MAX){
        items[top++] = item;
        return true;
    } else {
        cout<<"Stack is full."<<endl;
        return false;
    }
}

template<class Type>
bool Stack<Type>::pop(Type& item){
    if(top>0){
        item = items[--top];
        return true;
    } else {
        cout<<"Stack is empty, nothing to pop."<<endl;
        return false;
    }
}
/*==========================================================*/
// Worker 类
class Worker{
private:
    string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker():fullname("no one"),id(0L){}
    Worker(const string& s,long n):fullname(s),id(n){}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};
/*==========================================================*/


/*==========================================================*/
class Waiter : virtual public Worker{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(),panache(0){}
    Waiter(const string& s,long n,int p=0) : Worker(s,n),panache(p){}
    Waiter(const Worker& wk,int p=0) : Worker(wk),panache(p){}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker{

protected:
    enum {other,alto,contralto,soprano,bass,baritone,tenor};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    int range;
    static char *pv[Vtypes];
public:
    Singer() : Worker(),range(0){}
    Singer(const string& s,long n,int r=0) : Worker(s,n),range(r){}
    Singer(const Worker& wk,int r=0) : Worker(wk),range(r){}
    void Set();
    void Show() const;
};

class SingerWaiter : public Waiter, public Singer{
protected:
    void Data() const;
    void Get();
public:
    SingerWaiter():Worker(),Waiter(),Singer(){}

    SingerWaiter(const string& s,long n, int p=0, int r=other)
        : Worker(s,n),Waiter(s,n,p),Singer(s,n,r){}

    SingerWaiter(const Worker& wk,int p=0,int r=other)
        : Worker(wk),Waiter(wk,p),Singer(wk,r){}

    SingerWaiter(const Waiter& wt,int r=other)
        : Worker(wt),Waiter(wt),Singer(wt,r){}

    SingerWaiter(const Singer& sg,int p=0)
        : Worker(sg),Waiter(sg,p),Singer(sg){}

    void Set();
    void Show() const;
};


/*==========================================================*/

// 普通调用，包含
class Frab{
private:
    char fab[20];
public:
    Frab(const char* s = "C++"){std::strncpy(fab,s,20);}
    virtual void tell() const {std::cout<<fab;}
};
class Gloam{
private:
    int glip;
    Frab fb;
public:
    Gloam(int g=0, const char* s = "C++"):glip(g),fb(s){}
    Gloam(int g, const Frab& f):glip(g),fb(f){}
    void tell() const {
        fb.tell();
        std::cout<<glip<<std::endl;
    }
};

// 私有继承
class Frab2{
private:
    char fab[20];

public:
    Frab2(const char *s = "C++");
    virtual void tell2() const { std::cout << fab << std::endl; }
};
class Gloam2 : private Frab2{
private:
    int glip;

public:
    Gloam2(int g = 0, const char *s = "C++");
    Gloam2(int g, const Frab2 &fb);
    void tell2() const;
};



#endif