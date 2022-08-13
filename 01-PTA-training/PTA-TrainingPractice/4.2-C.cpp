#include <iostream>
// This parctice original from website: https://pintia.cn/

struct Sample{
    unsigned n; // from 1 to 10
    int* label = new int[n];
};

int main(){

    using namespace std;
    cout << ">>> Please enter an positive integer for analyze data(<=1000): ";
    unsigned blogs;
    cin >> blogs;
    Sample sample[blogs];

    for(int i=0;i<blogs;i++){
        cout << ">>> Enter blog value(1~10): ";
        cin >> sample[i].n;
        for(int j=0;j<sample[i].n;j++){
            cin >> sample[i].label[j];
        }
    }
    cout << ">>> Scan finished!" << endl;

    int lut[1000] = {0}; // characters look-up table, assume value 1 to 1000
    int count = 0;
    for(int k=0; k<blogs;k++){
        for(int h=0;h<sample[k].n;h++){
            lut[ sample[k].label[h] -1 ] +=1;
        }
    }

    //
    int max = 0;
    int index;
    for(int f=0;f<1000;f++){
        if(lut[f]>max){
            max = lut[f];
            index = f+1;
        }
    }

    cout << "Most frank label: " << index << ", occured: " << max << " times." << endl;

    // remember to release memory!
    for(int r=0;r<blogs;r++){
        delete[] sample[r].label;
    }

    cin.get();
    cin.get();
    return 0;

}