/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 指针栈模板，普通栈模板，包含&私有继承 has-a 关系
        *包含头文件：StackTP.h
        *其定义文件：
*******************************************/
#include<cstdlib>
#include<ctime>
#include"StackTP.h"

/*==========================================================*/
// 纯虚 析构函数，即使没做什么，也要定义出来
Worker::~Worker(){}

void Worker::Data() const{
    cout<<"fullname: "<<fullname<<endl;
    cout<<"id number: "<<id<<endl;
}

void Worker::Get(){
    cout<<"Enter worker's fullname: ";
    getline(cin,fullname);
    cout<<"Enter worker's id number: ";
    cin>>id;
    while(cin.get()!='\n')
        continue;
}



/*==========================================================*/

// 私有继承
Frab2::Frab2(const char* s){
    std::strncpy(fab,s,20);
}

Gloam2::Gloam2(int g, const char* s):Frab2(s),glip(g){}

Gloam2::Gloam2(int g, const Frab2& fb):Frab2(fb),glip(g){}

void Gloam2::tell2() const {
    Frab2::tell2();
    std::cout<<"glip: "<<glip<<std::endl;
}
/*==========================================================*/
const int NUM = 10;

int main(){

    cout<<"=========stack of pointers=========="<<endl;
    // 注：在头文件打断点没用
    std::srand(std::time(0));
    cout<<">>>Enter StackTP size: ";
    unsigned int stksize;
    if(cin>>stksize){
        StackTP<const char*> stp(stksize);

        // in basket
        const char* in[NUM] = {
                                " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
                                " 3: Betty Rocker",   " 4: Ian Flagranti",
                                " 5: Wolfgang Kibble"," 6: Portia Koop",
                                " 7: Joy Almondo",    " 8: Xaverie Paprika",
                                " 9: Juan Moore",     " 10: Misha Mache"
                            };
        // out basket
        const char* out[NUM];

        int processed = 0;
        int nextin = 0;
        int runs_counts = 0;
        // 存满 out 为止
        while(processed<NUM){
            ++runs_counts;
            if(stp.isempty())
                stp.push(in[nextin++]);
            else if(stp.isfull())
                stp.pop(out[processed++]);
            /* 如果是这种， nextin到了10之后这句就不会再执行了，后面都是pop到out满为止*/
            else if(std::rand()%2 && nextin < NUM)//50%几率 从 in 中 push 一个到 stp
                stp.push(in[nextin++]);
            else//50%几率 从 stp pop 一个到 out
                stp.pop(out[processed++]);
        }
        // 那么运行次数就与 stp 的 size 没有关系，会固定为 20 次
        cout<<">>>Totally runs "<<runs_counts<<" turns until out box is full.\n";
        for(int i=0;i<NUM;i++){
            cout<<out[i]<<endl;
        }
    } else
        exit(EXIT_FAILURE);
    cout<<"======================="<<endl;

    // Stack<Worker*> sw

    /*=======================*/
    Gloam2 gm;
    Frab2 fb("woyaonongsini");
    Gloam2 gm2(10,fb);
    gm.tell2();
    gm2.tell2();

    system("pause");
    return 0;
}
