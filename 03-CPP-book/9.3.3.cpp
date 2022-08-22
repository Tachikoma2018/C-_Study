/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 第9章节  内存模型 与 名称空间
*******************************************/
#include<iostream>

namespace {
    const std::string str{"BPMissforward"};
    int count;
}

int x = 10;
int y;
void other();
void another();

int main(){

    using namespace std;
    cout<<str<<endl;

    cout<<x<<endl;
    {
        int x=16;
        cout<<x<<endl;
        cout<<y<<endl;// static data, compiler will set to default 0
    }
    other();
    x = 46;
    // 执行方式：powershell, g++ 9.3.3.cpp, 9.3.3_2.cpp  然后 ./a.exe
    another();//输出：Another(): 46, 28
    // 说明 _2.cpp 中 extern int x 拿到的是上面修改过后的 46，等到执行再去获取

    cout<<"Done!"<<endl;

    system("pause");
    return 0;
}

void other(){
    int y=22;
    std::cout<<"Other: "<<x<<", "<<y<<std::endl;
}