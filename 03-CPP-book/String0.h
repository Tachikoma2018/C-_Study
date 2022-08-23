/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *定义程序文件：String0.cpp
        *执行程序文件：12.10.2.cpp
*******************************************/
#ifndef _STRING0_H_
#define _STRING0_H_
#include<iostream>

using std::ostream;
using std::istream;
class String{
private:
    char* st;
    int len;
    static int num_strings; // numbers of objects
    static const int CINLIM = 80;
public:
    String();
    String(const char*);
    String(const String&);
    ~String();

    int has(const char c);
    int length() const{return len;};
    void stringup(); // convert to upper case
    void stringlow();// convert to lower case

    String& operator=(const char*);
    String& operator=(const String& st);
    char& operator[](int i);// read and modify
    const char& operator[](int i) const; // read only


    friend bool operator<(const String& st1,const String& st2);
    friend bool operator>(const String& st1,const String& st2);
    friend bool operator==(const String& st1,const String& st2);
    friend String operator+(const String& st1,const String& st2);

    friend ostream& operator<<(ostream& os, const String& st);
    friend istream& operator>>(istream& is,  String& st);

    // static function, can only use static member data
    static int howmany(){return num_strings;};

};


#endif