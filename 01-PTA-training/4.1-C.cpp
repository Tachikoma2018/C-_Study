#include <iostream>

int main(){

    using namespace std;
    unsigned wallet;
    int pork = 15;
    int chicken = 20;
    int bull = 90;
    cout << "Please enter an positive integer(no more than 1000):" << endl;
    cin >> wallet;
    cout << wallet / pork << endl;
    cout << wallet / chicken << endl;
    cout << wallet * bull << endl;

    cin.get();
    cin.get();
    return 0;
    
}