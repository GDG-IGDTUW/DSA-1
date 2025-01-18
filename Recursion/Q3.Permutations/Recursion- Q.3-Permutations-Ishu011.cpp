//OPTIMAL-SOLUTION:
//step1 Backtracking is used to recursively generate all permutations by swapping elements in the array.
//step2 At each step, we explore all possible element placements, and once a valid permutation is found, it is added to the result.
//step3 Backtracking ensures we explore all combinations by undoing the swaps after each recursive call.
//Time Complexity: O(n!)

//CODE:
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
        // If we've reached the end of the array, add the current permutation to the result
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Try each element at the current 'start' position
        for (int i = start; i < nums.size(); ++i) {
            // Swap the current element with the start element
            swap(nums[start], nums[i]);
            
            // Recursively generate permutations for the rest of the elements
            backtrack(nums, result, start + 1);
            
            // Backtrack: restore the array to its original state
            swap(nums[start], nums[i]);
        }
    }
    
    // Main function to generate all permutations
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; 
        backtrack(nums, result, 0);   // Start backtracking from index 0
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.permute(nums);
    for (const auto& perm : result) {
        for (int num : perm) cout << num << " ";
        cout << endl;
    }

    return 0;
}
