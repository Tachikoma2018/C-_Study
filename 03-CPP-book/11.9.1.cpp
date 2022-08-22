/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 【随机漫步问题】：制定距离，设定固定步长，开始随机漫步，直到离原点超过指定距离。
        *包含头文件：vector0.h
        *其定义文件：vector0.cpp
*******************************************/
#include<iostream>
#include<cstdlib> // rand(),srand() prototypes
#include<ctime> // time() prototype
#include<fstream>
#include"vector0.h"

int main(){

    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double target,dstep,direction;
    Vector step;
    Vector result(0.0,0.0);// default RECT mode
    unsigned long steps = 0;

    ofstream fout;
    fout.open("write_vector.txt");
    if(!fout.is_open()){
        exit(EXIT_FAILURE);
    }

    cout<<">>> Enter target distance (q to quit): ";
    if(cin>>target){
        cout<<">>> Enter step length: ";
        if(cin>>dstep){
            fout<<"Target Distance: "<<target<<", Step Size: "<<dstep<<endl;
            fout<<steps<<": "<<step;
            while(result.magval()<target){
                direction = rand() % 360; // get angle in double type
                step.reset(dstep,direction,Vector::POL);
                result = result + step;
                steps++;
                // fout<<steps<<": "<<result;
                fout<<steps<<": "<<result;
            }
            fout<<"After "<<steps<<" steps, the subject has the following location: \n"<<result<<"or"<<endl;
            step.polar_mode();
            fout<<result;
            fout<<"Avergae outward distance per step = "<<result.magval()/steps<<endl;
        }
    }


    cout<<"Bye~"<<endl;
    fout.close();
    system("pause");
    return 0;
}