/*******************************************
    *FileName: 7.11.cpp
    *Author: Nerisateb
    *Version: 0.0.1
    *Date: 2022/08/15
    *Description: 函数原型，参数传递(数组，二维数组, struct,char*,array,，递归，函数指针，函数指针数组)
*******************************************/
#include<iostream>
#include<array>
#define SIZE 3

//函数指针作为函数参数, 使用不同的 处理函数 处理数据
double calc_data(const double*, unsigned len, double (*pfct)(const double*, unsigned));
double algo_1(const double*, unsigned);
double algo_2(const double*, unsigned);

//一维数组 作为函数参数, 使用数组指针，且还需传递数组长度
int sum_d1(const int*,int);
//二维数组 作为函数参数
int sum_d2(const int (*arr)[SIZE],int);
int sum_d22(const int arr[][SIZE],int);
// array 作为函数参数
int sum_arr(const std::array<int,SIZE>);

//递归 Recursion
void recur(int n);

//函数指针
const double* f1(const double*, int);
const double* f2(const double[], int);
const double* f3(const double arr[], int);
typedef const double* (*pfunc) (const double*, int);

int main(){

    using namespace std;

    //函数指针作为函数参数
    double darr[SIZE] = {11.11, 22.22, 33.33};
    cout<<">Algo_1 result: "<<calc_data(darr,SIZE,algo_1)<<endl;
    cout<<">Algo_2 result: "<<calc_data(darr,SIZE,algo_2)<<endl;


    cout<<"========================== 数组作为函数参数 ========================"<<endl;
    int arr1[3] = {16,28,46};
    int arr2[2][SIZE] = {{11,22,33},{16,28,46}};
    cout<<"sum_d1: "<<sum_d1(arr1,3)<<endl;
    cout<<"sum_d2: "<<sum_d2(arr2,2)<<endl;
    cout<<"sum_d22: "<<sum_d22(arr2,2)<<endl;
    array<int,SIZE> arr{16,28,46};
    cout<<"sum_arr: "<<sum_arr(arr)<<endl;


    recur(SIZE);

    // 函数指针，原型定义，调用，函数指针数组, typedef 简化， auto只能用于单值，不能用于列表
    cout<<"========================== 函数指针 ========================"<<endl;
    double ddb[SIZE] = {11.11, 22.22, 33.33};
    // 1: normal method
    const double* (*pf1)(const double*,int) = f1;
    const double* (*arr_pf[SIZE])(const double*,int) = {f1,f2,f3};
    const double* (*(*p_arr_pf)[SIZE])(const double*,int) = &arr_pf;
    cout<<">>> Using normal method, Address : Value";
    {
        cout<<"[pf1]"<<pf1(ddb,1)<<":"<<*pf1(ddb,1)<<endl;
        cout<<"[pf1]"<<(*pf1)(ddb,1)<<":"<<*(*pf1)(ddb,1)<<endl;
        for(int i=0;i<SIZE;i++){
            cout<<"[arr_pf]"<< arr_pf[i](ddb,1)<<" : "<<*arr_pf[i](ddb,1)<<endl;
            //or
            cout<<"[arr_pf]"<< (*arr_pf[i])(ddb,1)<<" : "<<*(*arr_pf[i])(ddb,1)<<endl;
        }
        for(int j=0;j<SIZE;j++){
            cout<<"[p_arr_pf]"<< (*p_arr_pf)[j](ddb,1) <<":"<<*(*p_arr_pf)[j](ddb,1)<<endl;
            //or
            cout<<"[p_arr_pf]"<< (*(*p_arr_pf)[j])(ddb,1) <<":"<<*(*(*p_arr_pf)[j])(ddb,1)<<endl;
        }
    }


    // 2: using typedef to simplify
    pfunc p1 = f1;
    pfunc p_arr[SIZE] = {f1,f2,f3};
    auto ppt = &p_arr;
    cout<<">>> Using typedef method, Address : Value";
    {
        cout<<"[p1]"<<(*p1)(ddb,1)<<":"<<*(*p1)(ddb,1)<<endl;
        for(int i=0;i<SIZE;i++){
            cout<<"[p_arr]"<<p_arr[i](ddb,1)<<":"<<*(*p_arr[i])(ddb,1)<<endl;
        }
        for(int j=0;j<SIZE;j++){
            cout<<"[ppt]"<<(*ppt)[j](ddb,1)<<":"<<*(*ppt)[j](ddb,1)<<endl;
        }
    }


    cout<<"========================== Done ========================"<<endl;
    system("pause");
    return 0;
}

double calc_data(const double* pd, unsigned len, double (*pfct)(const double*, unsigned)){
    return pfct(pd,len);
}

double algo_1(const double* pd, unsigned len){
    double ret = 0;
    for(int i=0;i<len;i++){
        ret += pd[i]/(i+1);
    }
    return ret;
}
double algo_2(const double* pd, unsigned len){
    double ret = 0;
    for(int i=0;i<len;i++){
        ret += pd[i]*(i+1);
    }
    return ret;
}

int sum_d1(const int* p_arr,int n){
    int sum{0};
    for(int i=0;i<n;i++){
        sum += p_arr[i];
    }
    return sum;
}
int sum_d2(const int (*arr) [SIZE],int n){
    int sum{0};
    for(int i=0;i<n;i++){
        for(int j=0;j<SIZE;j++){
            sum += (*(arr+i))[j];
        }
    }
    return sum;
}
int sum_d22(const int arr[][SIZE],int n){
    int sum{0};
    for(int i=0;i<n;i++){
        for(int j=0;j<SIZE;j++){
            sum += arr[i][j];
        }
    }
    return sum;
}
int sum_arr(const std::array<int,SIZE> arr){
    int sum{0};
    for(int i=0;i<SIZE;i++){
        sum += arr[i];
    }
    return sum;
}


void recur(int n){
    std::cout<<">> stage"<< n << std::endl;
    if(n>0){
        recur(n-1);//不要使用 --n，会改变 回流（逆链）中 n 的值
    }
    std::cout<<">> stage"<< n << std::endl;
    return;
}


const double* f1(const double* arr, int n){
    return arr;
}
const double* f2(const double arr[], int n){
    return arr+1;
}
const double* f3(const double arr[], int n){
    return arr+2;
}