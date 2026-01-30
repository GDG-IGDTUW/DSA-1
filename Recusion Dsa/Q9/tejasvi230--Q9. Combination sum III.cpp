class Solution {

    void solve(int ind, int k, int target,
               vector<vector<int>>& ans,
               vector<int>& ds) {

        // if k numbers chosen and sum becomes 0 → valid
        if (ds.size() == k && target == 0) {
            ans.push_back(ds);
            return;
        }

        // stop if sum becomes negative or size exceeds k
        if (target < 0 || ds.size() > k) return;

        for (int elt = ind; elt <= 9; elt++) {

            // pruning: no need to continue if number > target
            if (elt > target) break;

            ds.push_back(elt);                 // choose
            solve(elt + 1, k, target - elt, ans, ds); // recurse
            ds.pop_back();                     // backtrack
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, k, n, ans, ds);
        return ans;
    }
};
