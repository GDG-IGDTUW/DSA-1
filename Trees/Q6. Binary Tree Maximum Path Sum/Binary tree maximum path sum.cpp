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
    int findMaxPath(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0; // No node, no sum! ⛔

        // Explore left and right subtrees, ignoring negative sums (because negative paths reduce our max sum!)
        int leftPathSum = max(0, findMaxPath(node->left, maxSum));
        int rightPathSum = max(0, findMaxPath(node->right, maxSum));

        // Current node's best contribution (either take left, right, or both)
        maxSum = max(maxSum, leftPathSum + rightPathSum + node->val);

        // Return the max path that can be extended upwards 🚀
        return node->val + max(leftPathSum, rightPathSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Start with the smallest possible sum
        findMaxPath(root, maxSum); // Kick off recursion from root
        return maxSum; // Return the best sum found! 🏆
    }
};