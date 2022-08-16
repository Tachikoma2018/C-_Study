#include <iostream>
using namespace std;

template<typename W> // template 是定义模板 <typename T> 模板类型可以自定义 T就是别名
W Max(W a, W b){ //和普通函数一样可以重载  T 是返回类型  (T a,T b)函数参数  下面的参数类型都可以自定义
	return a > b ? a : b;
}

template<> // <>没东西就是模板专门化
int* Max(int *a, int *b){  // 模板专门化的优先级高于模板函数
	cout << "模板专门化优先级高于模板函数低于普通函数" << endl;	//普通函数>模板专门化>模板函数
	return *a > *b ? a : b;
}


int* Max(int *a, int *b){	// 普通函数调用优先级比模板函数高
	cout << "普通函数优先级高于模板函数还有模板专门化" << endl;
	return *a > *b ? a : b;
}


template<typename T>
T* Max(T *a, T *b){	//和普通函数一样可以重载
	return *a > *b ? a : b;
}

template<> // <>没东西就是模板专门化
int* Max<int>(int *a, int *b){  // 模板专门化的优先级高于模板函数
	cout << "模板专门化优先级高于模板函数低于普通函数" << endl;	//普通函数>模板专门化>模板函数
	return *a > *b ? a : b;
}

template<typename T>
T Max(T arr[],int n){ // 模板类参数 以及返回类型都可以自己定义
	T ret{ 0.0 };
	for (int i = 0; i < n; i++){ // int i = begin(arr); i < end(arr); i++ 这个循环要专门化模板才能用
		if (arr[i] > ret)
			ret = arr[i];
	}
	return ret;
}

template<typename T,int lower=0,int upper=4> // 别名参数 别名参数也可以带默认值传参方式<> T也可以默认类型=int
T Max(T arr[]){
	T ret{ arr[lower] };
	for (auto i = lower; i < upper; i++)
		ret += arr[i];
	return ret;
}

template<typename T,typename T1>// auto 返回类型函数+后面+ ->decltype(参数)是自己推断返回类型
auto Max(T a, T1 b)->decltype(a > b ? a : b){// 也可以写成 decltype(auto) Max(T *a,T *b){}
	return a > b ? a : b;
}	// c++17中还允许 推断别名参数 template<auto value> void f《10》{} 推断别名参数

int main(){
	int x{ 10 }, y{ 20 };			// 如果编译器已经生成了一种类型下次就不会再生成了是直接调用之前实例化的模板函数
	double a{ 3.1 }, b{ 2.1 };
	cout << Max<int>(x, y) << endl;	//编译器会自动匹配模板函数对应的类型 也可以在调用模板函数后面<type>(x,y) 丢类型给模板
	cout << *Max(&x, &y) << endl;	// 如果不丢编译器会自动匹配函数在匹配模板函数，因为普通函数优先级高于模板函数
	cout << Max(a, b) << endl;		// 又生成一个double类型的模板函数
	cout << *Max(&a, &b) << endl;   // 又生成一个double*类型的模板函数 这个取地址那边释放就是一堆地址的比较
	double ds[]{3.1, 0.2, 4.6, 7.8};
	cout << Max(ds, 4) << endl;
	cout << Max(ds) << endl; // <double,0, 4>里面就是调用的别名参数 函数参数(ds) 也可以让编译器自己推断
	cout << Max<int, int>(x, y) << endl; // 有两个别名 如果不加<int，int> 调用的还是自动匹配的模板函数因为推断优先级没不推断高

    system("pause");
	return 0;
}
