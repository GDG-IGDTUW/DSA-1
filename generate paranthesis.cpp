class Solution {
public:
    void f(int left,int right, string &s, vector<string>&ans){
        if(left==0 && right==0){
            ans.push_back(s);
            return;
        }
        if(left>0){
            s.push_back('(');
            f(left-1,right,s,ans);
            s.pop_back();

        }
        if(right>left){
            s.push_back(')');
            f(left,right-1,s,ans);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        int l=n,r=n;
        f(l,r,s,ans);
        return ans;

        
    }
};
