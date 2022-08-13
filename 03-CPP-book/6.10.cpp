#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#define maxSize 46
using namespace std;

void write2file(const string&);
int main(){

    string filename = "01-fstream.txt";

  /*   write2file(filename);
    cout<<">>>Writing Done."<<endl;
    cin.get(); */

    ifstream fin;
    fin.open(filename);
    if(!fin.is_open()){
        cout<<">>>Can't open file:"<<filename<<endl;
        cout<<">>>Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    char ppls[maxSize];
    fin.getline(ppls,maxSize);
    cout<<ppls<<endl;

    int sp_num{0};
    int i = 0;
    fin>>sp_num;//get first value
    while(fin.good()){//wihle input good and not at EOF
        ++i;
        cout<<"Read special number "<<i<<": "<<sp_num<<endl;
        fin>>sp_num;
    }

    if(fin.eof())
        cout<<">>>End of file reached."<<endl;
    else if(fin.fail())
        cout<<">>>Input terminated by data mismatch"<<endl;
    else
        cout<<">>>Input terminated for unknown reason"<<endl;

    fin.close();

    system("pause");
    return 0;
}

void write2file(const string& filename){
    ofstream fout;
    fout.open(filename);
    if(!fout.is_open()){
        cout<<">>>Can't open file:"<<filename<<endl;
        cout<<">>>Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    fout<<"Lucrezia Donati "
            "Leonardo Da Vinci "
            "Nerisateb"<<endl;
    fout<<16<<"\t"<<28<<"\t"<<46<<"\t"<<520<<endl;
    fout.close();
}