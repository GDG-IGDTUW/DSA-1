#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();  
        // length of the input string

        unordered_set<string> dict(wordDict.begin(), wordDict.end());  
        // put all words from wordDict into a set for quick checking

        vector<vector<string>> dp(n + 1);  
        // dp[i] will store all sentences we can make using the first i characters of s

        dp[0] = {""};  
        // base case: empty string can be split into an empty sentence

        // go through each position in the string
        for (int i = 1; i <= n; i++) {
            // try all possible word lengths ending at position i
            for (int len = 1; len <= i; len++) {
                // take substring from (i-len) to (i-1)
                string word = s.substr(i - len, len);

                // check if this substring is a word in the dictionary
                if (dict.count(word)) {
                    // if yes, add it to all sentences formed up to (i-len)
                    for (string prev : dp[i - len]) {
                        if (prev.empty()) {
                            // if previous sentence is empty, just add the word
                            dp[i].push_back(word);
                        } else {
                            // otherwise, add the word after a space
                            dp[i].push_back(prev + " " + word);
                        }
                    }
                }
            }
        }

        // return all sentences that use the whole string
        return dp[n];
    }
};