/*******************************************
 *FileName:
 *Author: Nerisateb
 *Version: 0.0.1
 *Date:
 *Description:
 *定义程序文件：
 *执行程序文件：
 *******************************************/
#ifndef _FRIEND_EXCEPTION_TYPE_CAST_H_
#define _FRIEND_EXCEPTION_TYPE_CAST_H_
#include<iostream>
#include<exception>
#include<stdexcept>

using std::string;
using std::cout;
using std::endl;
/*================  友元  =================*/
class Remote;
class Television{
private:
    // friend class Remote;
    enum { VOLMIN,OFF=0,ON,CHNMIN=0,CHNMAX=52,VOLMAX=100 };// volumn[0,100],channel[1,52]
    int channel;
    int voice;
    int state;
    string brand;
public:
    Television(int chn = CHNMIN,int vol = 28):channel(chn),voice(vol),state(0){}
    bool ison() const {return state==ON;}
    bool volup();
    bool voldown();
    bool chnup();
    bool chndown();
    void buzz(Remote& r);
    friend void show(Television& t,Remote& r);
};

class Remote{
private:
    string brand;
public:
    bool volup(Television& t) { return t.volup();}
    bool voldown(Television& t) { return t.voldown();}
    bool chnup(Television& t) { return t.chnup();}
    bool chndown(Television& t) { return t.chndown();}
    friend void show(Television& t,Remote& r);
};
// 共有的友元函数
inline void show(Television& t,Remote& r){
    cout<<"TV brand: "<<t.brand<<",Remoter brand: "<<r.brand<<endl;
}


/*================  嵌套类（链表）  =================*/
template<typename Item>
class Queuee{
private:
    class Nodee{
    private:
        Item item;
        Nodee* next;
    public:
        Nodee(const Item& i):item(i),next(nullptr){}
    };
    enum{QSIZE=10};
    Nodee* front;
    Nodee* rear;
    const int qsize;
    int items;
    Queuee(const Queuee& que):qsize(0){}
    Queuee& operator=(const Queuee& que){return *this;}
public:
    Queuee(int qs=QSIZE):qsize(qs),front(nullptr),rear(nullptr),items(0){}
    ~Queuee();
    bool isempty() const { return items==0;}
    bool isfull() const { return items==qsize;}
    int queuecount() const { return items;}
    bool enque(const Item& item);
    bool deque(Item& item);
};

template<typename Item>
bool Queuee<Item>::enque(const Item& item){
    if(isfull())
        return false;
    items++;
    Nodee* add = new Nodee(item);
    if(front==nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;// front & rear 是指针，第一个元素时 front 和 rear 指向同一个 Nodee
    return true;
}

template<typename Item>
bool Queuee<Item>::deque(Item& item){
    if(isempty())
        return false;
    items--;
    item = front->item;
    Nodee* temp = front;
    front = front->next;
    delete temp;
    if(items==0)
        rear = nullptr;
    return true;
}

template<typename Item>
Queuee<Item>::~Queuee(){
    Nodee* temp;
    while(front!=nullptr){
        temp=front;
        front=front->next;
        delete temp;
    }
}

/*================  异常  =================*/
// 2xy/(x+y)
class bad_hmean{
private:
    double val1;
    double val2;
public:
    bad_hmean(double x=0,double y=0):val1(x),val2(y){}
    void msg() const;

};
inline void bad_hmean::msg() const {
    cout<<"hmean("<<val1<<","<<val2<<"): invalid arguments: a=-b\n";
}

class bad_gmean{
private:
    double val1;
    double val2;
public:
    bad_gmean(double x=0,double y=0):val1(x),val2(y){}
    void msg() const;

};
inline void bad_gmean::msg() const {
    cout<<"gmean("<<val1<<","<<val2<<"): invalid arguments: a*b<0\n";
}

// 嵌套异常类继承
class Sales{
public:
    enum{MONTHS=12};

    class bad_index : public std::logic_error{
    private:
        int bi;
    public:
        explicit bad_index(int i,const string& s="Index error in Sales object\n");
        int bi_val() const { return bi; }
        virtual ~bad_index() throw() {}
    };

private:
    double gross[MONTHS];
    int year;
public:// member functions
    explicit Sales(int yy=0);
    Sales(int yy,const double* gr,int n);
    virtual ~Sales(){}
    int Year() const { return year; }
    virtual double operator[](int i) const;
    virtual double& operator[](int i);

};

// 派生类可以访问基类常量成员，如 MONTHS
class LabelSales : public Sales{
private:
    string label;
public:

    class nbad_index : public Sales::bad_index{
    private:
        string lbl;
    public:
        explicit nbad_index(const string& lb, int i,
            const string& s="Index error in LabelSales object\n");
        const string& lbl_val() const { return lbl; }
        virtual ~nbad_index() throw() {}
    };

    // member functions
    explicit LabelSales(const string& lb="none",int yy=0):Sales(yy),label(lb){}
    LabelSales(const string& lb, int yy,const double* gr,int n):Sales(yy,gr,n),label(lb){}
    virtual ~LabelSales() noexcept{} // noexcept 指出此函数没有异常，一种承诺
    const string& Label() const { return label; }
    virtual double& operator[](int i);
    virtual double operator[](int i) const;
};


/*==========  dynamic_cast<>()  &  typeid() ============*/
class Grand
{
private:
    /* data */
public:
    Grand(/* args */);
    ~Grand();
    virtual void Speak() const {}
    virtual void Say() const {}
};

class Superb : public Grand
{
private:
    /* data */
public:
    Superb(/* args */);
    ~Superb();
};

class Magnificent : public Superb
{
private:
    /* data */
public:
    Magnificent(/* args */);
    ~Magnificent();
};

#endif