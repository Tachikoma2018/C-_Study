#include <iostream>

int main(){

    using namespace std;
    cout << ">>> Please enter(positive integer): path(<=1000m), speed(<=10m/s), time(<=100s)" << endl;
    unsigned path, speed, time;
    cin >> path >> speed >> time;
    int flag = speed*time-path;

    while(flag >0){
        cout << ">>> Error, speed*time should be less than path!" << endl;
        cout << ">>> Please enter correct value again: ";
        cin >> path >> speed >> time;
        flag = speed*time-path;
    }            
    cout << ">>> value available." << endl;

    unsigned unfinished = path - speed*time;
    cout << ">>> Left " << unfinished << "m to finish." << endl;
    if(!(unfinished > (path/2)))
        cout << ">>> Chong ya!" << endl;
    
        
    cin.get();
    cin.get();
    return 0;
    
}