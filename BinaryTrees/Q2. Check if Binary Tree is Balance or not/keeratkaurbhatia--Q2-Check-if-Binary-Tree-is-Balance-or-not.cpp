//TC: O(n) as each node is visited only once
//SC: O(h) from the recursion stack

/*
Approach:
1. checkHeight() computes the height of the subtree and detects imbalance using -1.
2. if any subtree is unbalanced, we propagate -1 upward.
3. no subtree height is recomputed.
*/

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
    bool isBalanced(TreeNode* root) 
    {
        // if imbalance bubbles up to the root, tree is not balanced
        if (checkHeight(root)==-1) 
            return false;
        // if no imbalance detected, then tree is balanced
        return true;
    }

private:
    int checkHeight(TreeNode* node) 
    {
        // if node is empty, it does not have any height
        if (!node) return 0;

        
        int lh = checkHeight(node->left);
        if (lh == -1) return -1; // if imbalance on left, bubble it upwards

        int rh = checkHeight(node->right); 
        // if imbalance on right, bubble it upwards
        if (rh == -1) return -1;

        // if no imbalance bubbled up from bottom, compute the balance and check
        if (abs(lh - rh) > 1) return -1;

        // return height of current subtree 
        return max(lh, rh) + 1;
    }
};
