/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 函数模板，函数重载，函数模板重载，选择优先级，显式具体化，显式实例化，隐式实例化
*******************************************/
#include<iostream>
#include<cstring>

struct job{
    char name[16];
    double salary;
    int floor;
};

template<typename T>
void new_swap(T& c1,T& c2){
    // new_swap all members of struct
    T temp = c1;
    c1 = c2;
    c2 = temp;
}

    // explicit specialization 显式具体化,需要定义
template<> void new_swap<job>(job& c1,job& c2){
    std::cout<<">>>显式具体化函数, only swap salary and floor: "<<std::endl;
    double dtemp = c1.salary;
    c1.salary = c2.salary;
    c2.salary = dtemp;
    int itemp = c1.floor;
    c1.floor = c2.floor;
    c2.floor = itemp;
}

    // 非模板函数
void new_swap(job& j1,job& j2){
    std::cout<<">>>非模板函数, only swap job.name: "<<std::endl;
    char temp[16];
    strcpy(temp,j1.name);
    strcpy(j1.name,j2.name);
    strcpy(j2.name,temp);
}

inline void show(const job& c){
    std::cout<<">>> "<<c.name<<", salary: "<<c.salary<<", floor: "<<c.floor<<std::endl;
}

int main(){

    using namespace std;
    job choice[2] = {{"ComputerVison",28000,16},
                     {"MediaDevelop" ,20000,22}};

    new_swap(choice[0],choice[1]);
    show(choice[0]);
    show(choice[1]);

    // 显式调用 模板函数，更具体的 job& 类型，则调用 显式具体化函数
    new_swap<>(choice[0],choice[1]);
    show(choice[0]);
    show(choice[1]);

    // 显式调用 显式实例化
    string ss1 = "Lucrezia";
    string ss2 = "Leonardo";
    new_swap<string>(ss1,ss2);
    cout<<ss1<<" love "<<ss2<<endl;

    cout<<"Done!"<<endl;

    system("pause");
    return 0;
}






