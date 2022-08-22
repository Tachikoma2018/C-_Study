/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
*******************************************/
#include<iostream>

extern int x;
namespace {
    int y = 28;
}

void another(){
    std::cout<<"Another() :"<<x<<", "<<y<<std::endl;
}