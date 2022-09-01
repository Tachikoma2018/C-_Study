/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *定义程序文件：
        *执行程序文件：
*******************************************/
#ifndef _14_7_EXERCISE_H_
#define _14_7_EXERCISE_H_

#include<iostream>

using std::string;
using std::cout;
using std::endl;


/*====================P486 14.7.4=====================*/
static string COLOR_TYPES[4] = {"RED HEART","BLACK  HEART","CUBE","PULM"};
class Card{
private:
    enum ColorType{red_heart,black_heart,cube,pulm};
    ColorType color;
    int value; //[0,52]
public:
    Card(int type=0);
    ~Card(){}
    friend std::ostream& operator<<(std::ostream& os,const Card& card);
};
// 虚基类
class Person{
private:
    string fname;
    string lname;
public:
    Person(const string& s1="empty",const string& s2="empty"):fname(s1),lname(s2){}
    virtual ~Person() = 0;
    virtual void show() const{ cout<<lname<<" "<<fname; }
};

class Gunslinger : virtual public Person{
private:
    double acttime;
    int scars;
public:
    Gunslinger(const char* s1,const char* s2,double x=2.8,int y=0):Person(s1,s2),acttime(x),scars(y){}
    Gunslinger(const Person& pp, double x=2.8,int y=0):Person(pp),acttime(x),scars(y){}
    double Draw() const {return acttime;}
    void show() const {cout<<" Time of preparing a gun: "<<acttime<<"s, gun has "<<scars<<" scars.\n";}
};

class PokerPlayer : virtual public Person{
private:
    Card card;
public:
    PokerPlayer(int type=0):Person(),card(type){}
    PokerPlayer(const Person& pp,int type=0):Person(pp),card(type){}
    Card Draw() const { return card; }
};

// 多重继承，只继承一个虚基类对象
class BadDude:public Gunslinger, public PokerPlayer{
private:

public:
    BadDude(const char* s1="empty",const char* s2="empty",double x=2.8,int y=0,int t=0)
        :Person(s1,s2),Gunslinger(s1,s2,x,y),PokerPlayer(t){}
    BadDude(const Person& pp,double x=2.8,int y=0,int t=0):Person(pp),Gunslinger(pp,x,y),PokerPlayer(t){}
    BadDude(const Gunslinger& gs,int t=0):Person(gs),Gunslinger(gs),PokerPlayer(t){}
    BadDude(const PokerPlayer& pp,double x=2.8,int y=0,int t=0):Person(pp),Gunslinger(pp,x,y),PokerPlayer(t){}
    double Gdraw() const { return Gunslinger::Draw(); }
    // auto Cdraw() const -> decltype(PokerPlayer::Draw()) { return PokerPlayer::Draw(); }
    void Cdraw() const { cout<<PokerPlayer::Draw(); }

    void show() const { Person::show(); Gunslinger::show();}
};

#endif