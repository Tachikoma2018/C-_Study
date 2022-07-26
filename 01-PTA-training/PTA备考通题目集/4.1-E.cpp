#include <iostream>

int main(){

    using namespace std;
    cout << ">>> Please enter an positive integer for students number(<=10000): ";
    unsigned wholesome, temp;
    cin >> wholesome;

    temp = wholesome;
    int scores[wholesome][2];
    int boys = 0;
    int girls = 0;
    double ttl_stds = 0;
    double ttl_boys = 0;
    double ttl_girls = 0;
    double aver_class, aver_boys, aver_girls;

    while(temp){
        cout << "The " << temp << " student (gendre)(score) is: " ;
        cin >> scores[temp-1][0] >> scores[temp-1][1];
        if(scores[temp-1][0]==0){
            girls += 1;
            ttl_girls += scores[temp-1][1];
        } else if (scores[temp-1][0]==1){
            boys += 1;
            ttl_boys += scores[temp-1][1];
        }
        ttl_stds += scores[temp-1][1];
        temp--;
    }
    cout << ">>> Scan finished!" <<endl;

    aver_class = ttl_stds/wholesome;
    if (!boys) {
        aver_girls = ttl_girls/girls;
        cout << aver_class << " " << aver_girls << " X" << endl;
    } else if (!girls) {
        aver_boys = ttl_boys/boys;
        cout << aver_class << " X " << aver_boys << endl;
    } else{
        aver_boys = ttl_boys/boys;
        aver_girls = ttl_girls/girls;
        cout << aver_class << " " << aver_girls << " " << aver_boys << endl;
    }


    cin.get();
    cin.get();
    return 0;

}