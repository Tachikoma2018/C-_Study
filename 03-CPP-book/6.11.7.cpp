/*******************************************
    *FileName:
    *Author: Nerisateb
    *Version:
    *Date:
    *Description: 循环读取，每次读取一个单词，直到输入 q 结束；
                  而后指出有多少个单词是元音开头，辅音开头，以及其他
*******************************************/

#include <iostream>
#include <cctype>
#include <cstring>
#define maxLen 20

int main(){
    using namespace std;

    char words[maxLen];

    int num_y = 0;
    int num_f = 0;
    int others = 0;

    cout << ">>>Enter words (q to quit): " << endl;
    cin >> words;
    while (strcmp(words, "q")){
        bool bool_ = true;
        // ensure pure english word
        char c = words[0];
        for (int i = 0; c != '\0' && i < strlen(words); i++){
            if (!isalpha(c))
            {
                bool_ = false;
                break;
            }
            c = words[i];
        }
        if (!bool_){
            others++;
        } else {
            switch (words[0]){
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    num_y++;
                    break;
                default:
                    num_f++;
                    break;
            }
        }
        cin >> words;
    }

    cout << ">>> " << num_y << " words begining with vowels\n";
    cout << ">>> " << num_f << " words begining with consonants\n";
    cout << ">>> " << others << " others\n";

    system("pause");
    return 0;
}