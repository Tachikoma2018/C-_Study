#include<iostream>
#include<array>
#include<sstream>//for istringstream
#define maxSize 10

//模板函数 string 转换为 Type 类型
template<class Type>
Type string2num(const std::string& str){
    std::istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

int main(){
    using namespace std;
    string scanin[maxSize];
    array<double, maxSize> donation{0};

    int i = 0;
    cout<<">>>Enter double value. Type mismatch will terminate.\n";
    bool bool_=true;
    while(i<maxSize && cin>>scanin[i] && cin.good()){
        int count=0;
        for(char c:scanin[i]){

            if(c=='.'){
                count++;
                if(count==2){
                    cout<<">>>donation["<<i<<"] type error_.,abandon,terminating.";
                    bool_=false;
                    break;
                }
                continue;
            }
            if(!isdigit(c)){
                cout<<">>>donation["<<i<<"] type error_!digit,abandon,terminating.";
                bool_=false;
                break;
            }
        }
        if(!bool_)
            break;
        donation[i] = string2num<double>(scanin[i]);
        i++;

    }

    //calc average
    double sum=0;
    int cnt=0;
    for(int j=0;j<i;j++){
        sum+=donation[j];
    }
    double aver=sum/i;
    for(int k=0;k<i;k++){
        if(donation[k]>aver)
            cnt++;
    }

    cout<<"aver is "<<aver<<endl;
    cout<<"There are "<<cnt<<" numbers larger then aver"<<endl;

    system("pause");
    return 0;
}