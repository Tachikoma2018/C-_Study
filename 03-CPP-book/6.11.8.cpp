/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version: 0.0.1
    *Date:
    *Description: 读取文件中每个字符，并计算总字符数
*******************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>

int main(){

    using namespace std;
    ifstream fin;
    string filename {"02-fstream.txt"};
    fin.open(filename);
    if(!fin.is_open()){
        cout<<">>>Open file "<<filename<<" failed. Exit program."<<endl;
        exit(EXIT_FAILURE);
    }
    char ch;
    int count = 0;
    while(fin.get(ch) && fin.good()){
        count++;
    }
    cout<<"File have "<<count<<" characters."<<endl;

    if(fin.eof())
        cout<<">>>Reach end of file"<<endl;
    else if(fin.fail())
        cout<<">>>Type error"<<endl;
    else
        cout<<">>>Unknown error"<<endl;

    fin.close();
    system("pause");
    return 0;
}