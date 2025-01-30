#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &arr) {
    vector<vector<string>> ans;
    if(arr.size()==0) return ans;

    unordered_map<string, vector<string>> mpp;
    for(auto x:arr) {
        string word=x;
        sort(word.begin(), word.end());
        mpp[word].push_back(x);
    }

    for(auto x:mpp) ans.push_back(x.second);
    return ans;
}

int main() {
    vector<string> arr={"eat", "tan", "nat", "ate", "tea", "bat"};
    vector<vector<string>> ans=groupAnagrams(arr);
    for(auto row:ans) {
        for(auto col:row) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}