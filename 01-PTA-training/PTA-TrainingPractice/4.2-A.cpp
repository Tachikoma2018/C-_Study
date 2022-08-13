#include <iostream>
#include <string>
#include <limits>
// This parctice original from website: https://pintia.cn/
using namespace std;
#define MAX_LEN 2000000

bool inRange(const string &ans);
bool validate(const string &str);

int main()
{
    unsigned n;

    cout << ">>>Enter an positive integer no more than 100: ";
    while (!(cin >> n && n > 0 && n < 101))
    {
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << ">>>invalid value, enter again!" << endl;
    }
    cout << ">>>Value " << n << " accepted, now please fill in answers(pure english)." << endl;

    // answer test case:
    //      zZzZYXWwxyYX    Y
    //      wVUuvUTsR       N
    string answers[n];
    int k = 0;
    cout << ">>> " << k + 1 << ": ";
    while (k < n && cin >> answers[k] && answers[k].size() < MAX_LEN)
    {
        if (inRange(answers[k]))
            k++;
        else
        {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << ">>>Invalid answer, please enter pure english answer." << endl;
        }
        if (k != n)
            cout << ">>> " << k + 1 << ": ";
    }
    cout << ">>>Scan in finished" << endl;

    for (string s : answers)
    {
        if (validate(s))
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }

    system("pause");
    return 0;
}

bool inRange(const string &ans)
{
    for (int j = 0; j < ans.size(); j++)
    {
        if (int(ans[j]) < 65 || int(ans[j]) > 122 || (int(ans[j]) > 90 && int(ans[j]) < 97))
            return false;
    }
    return true;
}

// str should be checked before as pure english words
// [to-fix]: 如果字符串中间有字符是边界字符呢？
// 如 A/z，大写字母：next是 字母表中前一个字母的大写；  小写字母：next是 字母表中下一个字母的小写
bool validate(const string &str)
{

    for (int i = 0; i < str.size(); i++)
    {
        if (i != str.size() - 2)
        {
            if (int(str[i]) > 64 && int(str[i]) < 91)
            { // upper case, 65~90 A~Z
                if (!(int(str[i + 1]) == int(str[i]) + 32 || int(str[i + 1]) == int(str[i]) - 1))
                    return false;
            }
            else if (int(str[i]) > 96 && int(str[i]) < 123)
            { // lower case, 97~122 a~z
                if (!(int(str[i + 1]) == int(str[i]) - 32 || int(str[i + 1]) == int(str[i]) + 1))
                    return false;
            }
        }
        else
            break;
    }
    return true;
}