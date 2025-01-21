#include <iostream>
#include <set>
#include <vector>
using namespace std;

void helper(vector<int>& cand, int tar, vector<vector<int>>& ans, int sum, vector<int>& vec, int i) {
    if (sum > tar || i >= cand.size()) {
        return;
    }

    if (sum == tar) {
        ans.push_back(vec);
        return;
    }

    // Include the current element (Single Inclusion)
    vec.push_back(cand[i]);
    helper(cand, tar, ans, sum + cand[i], vec, i); // Allow repeated inclusion of the same element
    vec.pop_back(); // Backtracking step

    // Exclude the current element
    helper(cand, tar, ans, sum, vec, i + 1); // Move to the next element
}

vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
    vector<vector<int>> ans;
    vector<int> vec;
    helper(cand, tar, ans, 0, vec, 0);
    return ans;
}

int main() {
    vector<int> cand = {2, 3, 6, 7};
    int tar = 8;

    vector<vector<int>> result = combinationSum(cand, tar);

    // Print the result
    cout << "[";
    for (auto& combination : result) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;

    return 0;
}
