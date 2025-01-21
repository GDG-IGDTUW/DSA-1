#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string reverseWords(string s)
{
    int n = s.length();

    vector<string> vec;

    string word = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (word != "")
            {
                vec.push_back(word);
            }
            word = "";
            continue;
        }
        word += s[i];
    }

    if (word != "")
        vec.push_back(word);

    reverse(vec.begin(), vec.end());

    string news = "";
    for (int i = 0; i < vec.size(); i++)
    {
        news += vec[i];
        if (i != vec.size() - 1)
            news += " ";
    }

    return news;
}

int main()
{
    string s = "Hello, How are you?";

    cout << "Reversed String: "<<reverseWords(s);
    return 0;
}