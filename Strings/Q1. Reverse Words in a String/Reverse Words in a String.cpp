class Solution {
public:
    string reverseWords(string s) {
        string ans = "", temp = "";    //creating empty ans and temporary strings
        for (int i = s.size() - 1; i >= 0; i--) {  
            if (s[i] != ' ') {
                temp = s[i] + temp;         //if s is not empty concatenate temp & s[i]
            } else if(!temp.empty()) {
                if (!ans.empty()) ans += ' ';
                ans += temp;                //if temp string not empty add it in ans & make temp string empty
                temp.clear();
            }
        }
         if (!temp.empty()) {
            if (!ans.empty()) ans += ' ';
            ans += temp;
        }
        return ans;
    }
};
