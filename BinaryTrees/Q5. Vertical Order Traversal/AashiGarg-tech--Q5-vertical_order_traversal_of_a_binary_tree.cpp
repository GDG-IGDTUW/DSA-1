/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            map<int, vector<pair<int,int>>> mp;
            dfs(root, 0, 0, mp);
    
            vector<vector<int>> ans;
            for (auto &col : mp) {
                auto v = col.second;
                sort(v.begin(), v.end());
                vector<int> temp;
                for (auto &p : v) temp.push_back(p.second);
                ans.push_back(temp);
            }
            return ans;
        }
    
        void dfs(TreeNode* node, int row, int col, map<int, vector<pair<int,int>>> &mp) {
            if (!node) return;
            mp[col].push_back({row, node->val});
            dfs(node->left, row + 1, col - 1, mp);
            dfs(node->right, row + 1, col + 1, mp);
        }
    };