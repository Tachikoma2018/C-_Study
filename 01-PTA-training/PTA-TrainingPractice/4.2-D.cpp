#include <iostream>
// This parctice original from website: https://pintia.cn/
int main(){

    using namespace std;
    cout << ">>> Please enter 3 positive integer for n(<100), k(<n), x(<100): ";
    unsigned n,k,x;
    cin >> n >> k >> x;
    while( !((n>0 && n<100)&&(k>0 && k<n)&&(x>0 && x<100)) ){
        cout << ">>> Value unavailable, check requirements above, enter again: ";
        cin >> n >> k >> x;
    }
    cout << ">>> Value available." << endl;

    // matrix n*n
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }

    // move step k, replace vlaue x, and need to decide step s
    // 【【【for循环内两个变量时，注意中间判断条件，要同时满足】】】
    // 【【【','分开时两个变量的条件只要满足一个都会继续运行  】】】
    for(int c=1,s=1; (c<n)&&(s<k || s==k); c+=2,s++){
        for(int r=n-1; r>0 || r==0; r--){
            if(!(r<s))
                matrix[r][c] = matrix[r-s][c];
            else
                matrix[r][c] = x;
        }
        // loop
        if((c/2+1)%k == 0) // 当s=k时将下一次的s重置为1
            s=0;
    }

    for(int a=0;a<n;a++){
        int sum_row = 0;
        for(int b=0;b<n;b++){
            sum_row += matrix[a][b];
        }
        if(a!=n-1)
            cout << sum_row << " ";
        else
            cout << sum_row;
    }
    cout << endl;

    cin.get();
    cin.get();
    return 0;

}