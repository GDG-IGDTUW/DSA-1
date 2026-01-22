class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector <int> v1(128,-1);
        vector <int> v2(128,-1);

        if(s.size()!=t.size()){
            return false;
        }

        for(int i=0;i<s.size();i++){
            if(v1[s[i]]!=v2[t[i]]){
                return false;
            }
            v1[s[i]]=v2[t[i]]=i;

        }
        return true;
        
    }
};
