#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int maxi;

    // Helper function to calculate the maximum path sum for a given node.
    int maxPathDown(TreeNode* node) {
        if (node == NULL) return 0; // Base case: null nodes contribute 0 to the path sum.

        // Recursively find the maximum path sums from left and right subtrees.
        // Use `max(0, ...)` to ignore negative contributions.
        int left = max(0, maxPathDown(node->left));
        int right = max(0, maxPathDown(node->right));

        // Update the global maximum path sum (`maxi`) including the current node.
        maxi = max(maxi, left + right + node->val);

        // Return the maximum path sum rooted at the current node, considering only one child.
        return max(left, right) + node->val;
    }

public:
    // Main function to calculate the maximum path sum in the binary tree.
    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;           // Initialize the maximum path sum to the smallest possible value.
        maxPathDown(root);        // Call the helper function to compute the result.
        return maxi;              // Return the computed maximum path sum.
    }
};

int main() {
    // Constructing the binary tree [1, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Creating the Solution object and calling maxPathSum
    Solution sol;
    int result = sol.maxPathSum(root);

    // Output the result
    cout << "Maximum Path Sum: " << result << endl;  // Output should be 6

    return 0;
}
