/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 函数模板，函数重载，函数模板重载，选择优先级，显式具体化，显式实例化，隐式实例化
*******************************************/
#include<iostream>
#define MaxLen 5

template<typename T, int lower = 0, int upper = MaxLen>
T Max(T arr[]){
    T temp = arr[0];
    for(int i=0;i<upper;i++){
        if(temp < arr[i])
            temp = arr[i];
    }
    return temp;
}

template<typename T1, typename T2>
auto Max(T1 t1,T2 t2) -> decltype(t1<t2?t1:t2){
    return t1 > t2 ? t1 : t2;
}

int main(){

    using namespace std;

    double darr[MaxLen] = {16.28, 28.46, 11.23, 46.52, 52.26};
    cout<<"Max is "<<Max(darr)<<endl;

    int x{16},y{28};
    cout<<"Max is "<<Max<int,int>(x,y)<<endl;


    cout<<"Done!"<<endl;

    system("pause");
    return 0;
}
