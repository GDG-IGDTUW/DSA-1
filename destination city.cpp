class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>mpp;
        for(auto & path:paths){
            mpp[path[0]]++;
        }
        for(auto & path:paths){
            if(mpp.find(path[1])==mpp.end()){
                return path[1];
            }
        }
        return "";
    }
};
