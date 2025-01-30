#include <iostream>
#include <vector>
using namespace std;

    void getSubs(vector<int>& nums, vector<vector<int>>& result, vector<int>& ans, int i){
        // Base Case
        if(nums.size() == i){
            result.push_back({ans});
            return;
        }

        // Include
        ans.push_back(nums[i]);
        getSubs(nums, result, ans, i+1);

        // Backtracking
        ans.pop_back();

        // Exclude
        getSubs(nums, result, ans, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        getSubs(nums, result, ans, 0);
        return result;
    }
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    vector<vector<int>> result = subsets(nums);

    cout<<"Subsets:\n";
    for(auto i:result){
        cout<<"[ ";
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<"]\n";

    }
    return 0;
    
}