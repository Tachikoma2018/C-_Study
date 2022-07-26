#include <iostream>

using namespace std;

int main(){

    int score;
    cout << "What's your score in this exam(0~100)?" << endl;
    cin >> score;
    // 需要对输入进行类型判断
    
    if( !(score < 90) ){
        cout << "gong xi ni kao le " << score << " fen! " << endl;
    } else {
        cout << "mei you hen gao o, yao ji xu nu li ha~ " << endl;
    }

    cin.get();
    return 0;
}