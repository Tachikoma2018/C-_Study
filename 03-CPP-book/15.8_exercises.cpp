/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 友元类，友元函数、相互/共同友元； 异常； 类型转换运算符
        *包含头文件：
        *其定义文件：
*******************************************/
#include<iostream>

#include"friend_exception_type_cast.h"
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<typeinfo>

const int SIZE = 12;
double hmean(double a,double b);
double gmean(double a,double b);

int main(){

    using namespace std;

    // std::srand(time(0));

    /*================  自定义类类型异常  =================*/
    cout<<">>>Enter two value in pair, such as: 16 28, (q to quit): ";
    double x,y,z;
    while(cin>>x>>y){
        try{
            z=hmean(x,y);
            cout<<"Harmonic mean of "<<x<<" and "<<y<<" is "<<z<<endl;
            cout<<"Geometric mean of "<<x<<" and "<<y<<" is "<<gmean(x,y)<<endl;
        }
        catch(bad_hmean& bh){
            bh.msg();
            cout<<">>>Try again: ";
            continue;
        }
        catch(bad_gmean& bg){
            bg.msg();
            cout<<"Deadly fraw, terminate program.\n";
            break;
        }

        cout<<"\n>>>Enter another pair(q to quit): ";
    }

    /*================ 异常之 类继承  =================*/
    double vals1[SIZE] =
        {
            1220, 1100, 1122, 2212, 1232, 2334,
            2883, 2393, 3302, 2922, 3002, 3544
        };
    double vals2[SIZE] =
        {
            12, 11, 22, 21, 32, 34,
            28, 29, 33, 29, 32, 35
        };
    Sales sales1(2011,vals1,SIZE);
    LabelSales sales2("Blogstar",2012,vals2,SIZE);

    cout<<"First try block\n";
    try{
        int i;
        cout<<"Year="<<sales1.Year()<<endl;
        for(int i=0;i<SIZE;i++){
            cout<<sales1[i]<<" ";
            if(i%6==5)
                cout<<endl;
        }
        cout<<"Year="<<sales2.Year()<<endl;
        cout<<"Label="<<sales2.Label()<<endl;
        for(int i=0;i<=SIZE;i++){
            cout<<sales2[i]<<" ";
            if(i%6==5)
                cout<<endl;
        }
        cout<<"End of try block.\n";
    }

    catch(LabelSales::nbad_index& nbi){
        cout<<nbi.what();
        cout<<"Company: "<<nbi.lbl_val()<<endl;
        cout<<"bad index: "<<nbi.bi_val()<<endl;
    }
    catch(Sales::bad_index& bi){
        cout<<bi.what();
        cout<<"bad value: "<<bi.bi_val()<<endl;
    }

    /*================ RTTI: dynamic_cast<>()  &  typeid()  =================*/
    cout<<"\nNext try block: \n";
    try{
        sales2[2]=37.6;
        sales1[20]=233;
        cout<<"End of try block 2.\n";
    }
    catch(std::logic_error& lg){
        // 返回的是 经过C++函数的名称标识符
        cout<<"Now processing type: "<<typeid(lg).name()<<endl;
        // dynamic_cast<type-name>(expression)
        // 如果结果为对象的expression 不能够转为 type-name，则返回空指针
        LabelSales::nbad_index* pni = dynamic_cast<LabelSales::nbad_index*>(&lg);
        if(pni && typeid(LabelSales::nbad_index)==typeid(*pni)){
            cout<<">>> "<<pni->what();
            cout<<"Company: "<<pni->lbl_val()<<endl;
            cout<<"Bad index: "<<pni->bi_val()<<endl;
        }
        Sales::bad_index* pbi = dynamic_cast<Sales::bad_index*>(&lg);
        if(pbi && typeid(Sales::bad_index)==typeid(*pbi)){
            cout<<">>> "<<pbi->what();
            cout<<"Bad index: "<<pbi->bi_val()<<endl;
        }
        std::logic_error* plg = dynamic_cast<std::logic_error*>(&lg);
        if(plg && typeid(std::logic_error)==typeid(*plg)){
            cout<<">>> "<<plg->what();
        }
    }

    /*================  const_cast<>,   =================*/
    // const_cast<type-name>(expression),只改变const或volatile属性，
        // 所以除了const或volatile特征不同外，expression 和 type-name 类型必须相同
    int newval = 16;
    const int cntval = 46520;

    const int* pval = &newval;
    int* pval2 = const_cast<int*>(pval);//改变 const 为 volatile
    *pval2 = cntval;
    cout<<"\n newval = "<<newval<<", *pval2 is "<<*pval2<<endl;

    const int* pcval = &cntval;
    int* pcval2 = const_cast<int*>(pcval);
    *pcval2 = 227411;
    cout<<"address: cntval is "<<&cntval<<", pointer pcval is "
        <<pcval<<", pointer pcval2 is "<<pcval2<<endl;
    cout<<" cntval now is "<<cntval<<", *pcval is "<<*pcval
        <<", *pcval2 is "<<*pcval2<<endl;
    // 结果：地址都一样，指向同一内存；
    //      但是值不同，cntval 还是原来的 46520，*pvcal & *pcval2 值被修改为 227411
        //  应该是编译器优化了，将声明为 const 的 cntval 放到寄存器

    // 尝试使用 volatile 避免编译器优化
    volatile const int cnti2 = 201632;
    volatile const int* pcti = &cnti2;
    int* pcti2 = const_cast<int*>(pcti);
    *pcti2 = 965240;
    cout<<"\naddress: cnti2 is "<<&cnti2<<",pointer pcti is "
        <<pcti<<", pointer pcti2 is "<<pcti2<<endl;
    cout<<" cnti2 now is "<<cnti2<<", *pcti is "<<*pcti
        <<", *pcti2 is "<<*pcti2<<endl;
    // 结果： address: 1    1   0x61fb84; 值都一样，为 965240


    cout<<"Done!"<<endl;

    system("pause");
    return 0;
}

double hmean(double a,double b){
    if(a==-b)
        throw(bad_hmean(a,b));
    return 2*a*b/(a+b);

}
double gmean(double a,double b){
    if(a*b<0)
        throw(bad_gmean(a,b));
    return sqrt(a*b);
}