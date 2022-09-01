/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description:
        *包含头文件：
        *其定义文件：
*******************************************/
#include"friend_exception_type_cast.h"


bool Television::voldown() {
    if(voice>VOLMIN)
        voice--;
    return true;
}

bool Television::volup() {
    if(voice<VOLMAX)
        voice++;
    return true;
}

bool Television::chndown() {
    if(channel>CHNMIN)
        channel--;
    else
        channel = CHNMAX;
    return true;
}

bool Television::chnup() {
    if(channel<CHNMAX)
        channel++;
    else
        channel = CHNMIN;
    return true;
}

Sales::bad_index::bad_index(int i,const string& s)
    : std::logic_error(s),bi(i)
{

}

Sales::Sales(int yy){
    year = yy;
    for(int i=0;i<MONTHS;i++)
        gross[i]=0;
}

Sales::Sales(int yy,const double* gr, int n){
    year = yy;
    int limit = (MONTHS<n) ? MONTHS:n;
    int i;
    for(i=0;i<limit;i++)
        gross[i]=gr[i];

    for(;i<MONTHS;i++)
        gross[i]=0;

}

double Sales::operator[](int i) const {
    if(i<0 || i>MONTHS)
        throw bad_index(i);
    return gross[i];
}

double& Sales::operator[](int i) {
    if(i<0 || i>MONTHS)
        throw bad_index(i);
    return gross[i];
}

LabelSales::nbad_index::nbad_index(const string& lb,int i,const string& s)
    : Sales::bad_index(i,s),lbl(lb)
{

}

double LabelSales::operator[](int i) const {
    if(i<0 || i>=MONTHS)
        throw nbad_index(Label(),i);
    return Sales::operator[](i);
}

double& LabelSales::operator[](int i) {
    if(i<0 || i>=MONTHS)
        throw nbad_index(Label(),i);
    return Sales::operator[](i);
}
