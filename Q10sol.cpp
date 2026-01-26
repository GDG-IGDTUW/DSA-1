class Solution {
public:
    void combination(int idx,string digits, string &s,vector<string>&ans,vector<string>&mapping) {

        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }

        for(char ch:mapping[digits[idx]-'0']){
            s.push_back(ch);
            combination(idx+1,digits,s,ans,mapping);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string>ans;
        vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s;
        combination(0,digits,s,ans,mapping);
        return ans;
        
    }
};
