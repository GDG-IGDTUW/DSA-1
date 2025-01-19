#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string reverseWords(string s){
    int n = s.length();

    string news = "";

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++){
        string word = "";
        while (i < n && s[i] != ' '){
            word += s[i];
            i++;
        }

        if (word.size() > 0){
            reverse(word.begin(), word.end());
            news += " " + word;
        }
    }

    return news.substr(1);
}


int main(){
    string s = "Hello, How are you?";

    cout<<reverseWords(s);
    return 0;
}