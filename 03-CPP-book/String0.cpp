/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *包含头文件：String0.h
        *执行程序文件：12.10.2.cpp
*******************************************/
#include"String0.h"
#include<cstring>
#include<cctype>

int String::num_strings = 0;
// constructors
String::String(){
    st = new char[1];
    st[0]='\0';
    len = 0;
    num_strings++;
}
String::String(const char* ss){
    len = strlen(ss);
    st = new char[len+1];
    strcpy(st,ss);
    num_strings++;
}
String::String(const String& ss){
    len = ss.len;
    st = new char[len+1];
    strcpy(st,ss.st);
    num_strings++;
}
String::~String(){
    --num_strings;
    delete [] st;
}

// member functions, oprerator overload
String& String::operator=(const char* ss){
    delete [] st;
    len = strlen(ss);
    st = new char[len+1];
    strcpy(st,ss);
    return *this;
}
String& String::operator=(const String& ss){
    if(this == &ss)
        return *this;
    delete [] st;
    len = ss.len;
    st = new char[len+1];
    strcpy(st,ss.st);
    return *this;
}
char& String::operator[](int i){// read and modify
    return st[i];
    // return *(st+i);
}
const char& String::operator[](int i) const{
    return *(st+i);
} // read only

// normal member functions
void String::stringup(){// convert to upper case
    for(int i=0;i<len;i++){
        if(isalpha(st[i]))
            st[i] = toupper(st[i]);
    }
}
void String::stringlow(){// convert to lower case
    for(int i=0;i<len;i++){
        if(isalpha(st[i]))
            st[i] = tolower(st[i]);
    }
}
int String::has(const char c){
    int count=0;
    for(int i=0;i<len;i++){
        if(st[i]==c)
            count++;
    }
    return count;
}

// friend functions, operator overload
bool operator<(const String& st1,const String& st2){
    return (strcmp(st1.st,st2.st)<0);
}
bool operator>(const String& st1,const String& st2){
    return st2<st1;
}
bool operator==(const String& st1,const String& st2){
    return (strcmp(st1.st,st2.st)==0);
}

String operator+(const String& st1,const String& st2){
    String ss = st1;
    ss.len += st2.len;
    delete [] ss.st;
    ss.st = new char[ss.len+1];
    strcpy(ss.st,st1.st);
    strcat(ss.st,st2.st);
    return ss;
}


ostream& operator<<(ostream& os, const String& ss){
    os<<ss.st;
    return os;
}
istream& operator>>(istream& is,  String& ss){
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if(is)
        ss = temp;
    while(is && is.get()!='\n')
        continue;
    return is;
}