/*******************************************
 *FileName:
 *Author: Nerisateb
 *Version: 0.0.1
 *Date:
 *Description: 类
 *******************************************/
#include <iostream>
#include <cstring>
#include "10.10.h"

Plorg::Plorg(const char *d_name, int d_value)
{
    if (d_name[0] != '\0')
    {
        char c = d_name[0];
        for (int i = 0; i < MAXLEN && c != '\0'; i++)
            plorg[i] = d_name[i];
    }
    CI = d_value;
}

void Plorg::show() const
{
    std::cout << plorg << " " << CI << std::endl;
}

void Plorg::revalue(int r_value)
{
    CI = r_value;
}

//===========================================

Stack::Stack(){
    // create an empty stack
    top = 0;
}
bool Stack::isFull() const{
    return top==MAX;
}
bool Stack::isEmpty() const{
    return top==0;
}
void Stack::push(const Item& item){
    if(isFull()){
        std::cout<<"\tStack if full, can not push anymore."<<std::endl;
        return;
    } else {
        items[top++] = item;
        std::cout<<"\t"<<item<<" pushed into stack."<<std::endl;
    }

}
void Stack::pop(Item& item){
    if(isEmpty()){
        std::cout<<"Stack if empty, can not pop anymore."<<std::endl;
        return;
    } else {
        item = items[--top];
        std::cout<<"\t"<<item<<" poped from stack."<<std::endl;
    }
}