#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;
void helper(vector<int> &cand, int tar, vector<vector<int>> &ans, int sum, vector<int> &vec, int i)
{
    if (i == cand.size() || sum > tar)
    {
        return;
    }

    if (sum == tar)
    {
        if (s.find(vec) == s.end())
        {
            ans.push_back({vec});
            s.insert(vec);
        }
        return;
    }

    sum += cand[i];
    vec.push_back(cand[i]);

    // Single Inclusion
    helper(cand, tar, ans, sum, vec, i + 1);

    // Multiple Inclusion
    helper(cand, tar, ans, sum, vec, i);

    // Exclusion
    sum -= cand[i]; // Backtracking Step
    vec.pop_back(); // Backtracking Step
    helper(cand, tar, ans, sum, vec, i + 1);
}

vector<vector<int>> combinationSum(vector<int> &cand, int tar)
{
    vector<vector<int>> ans;
    vector<int> vec;
    helper(cand, tar, ans, 0, vec, 0);
    return ans;
}

int main(){
    vector<int> cand;
    cand.push_back(2);
    cand.push_back(3);
    cand.push_back(6);
    cand.push_back(7);
    int tar = 7;

    vector<vector<int>> result = combinationSum(cand, tar);
    cout<<"Printing combinations:\n";
    for(auto i:result){
        for(int j:i) cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}