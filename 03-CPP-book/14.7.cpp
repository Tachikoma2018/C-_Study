/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date: P486, Charpter 14, exercises
    *Description: 公有继承、私有继承（包含）、保护继承、多重继承、虚基类
        模板与友元函数：非模板友元函数，约束模板友元，非约束模板友元

        *包含头文件：
        *其定义文件：
*******************************************/
#include"14.7_exercise.h"
#include<cstdlib> // srand() rang()
#include<ctime> // time()

/* using std::cout;
using std::endl;
using std::string; */

Card::Card(int type){
    srand(time(0));
    color = ColorType(type);
    value = rand()%51 +1;
}
std::ostream& operator<<(std::ostream& os,const Card& card){
    os<<"Got poker card "<<card.value<<" , "<<COLOR_TYPES[card.color]<<endl;
    return os;
}

Person::~Person(){}


int main(){

    using namespace std;

    /*==========14.7.4===========*/
    BadDude hacker("Davinci","Leonardo",1.6,5);
    hacker.show();
    hacker.Cdraw();





    cout<<"Done!"<<endl;

    system("pause");
    return 0;
}