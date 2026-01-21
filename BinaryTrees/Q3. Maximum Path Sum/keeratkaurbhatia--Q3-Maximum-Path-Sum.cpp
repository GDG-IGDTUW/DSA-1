//TC: O(n) each node is visited once
//SC: O(h) recursion stack at the worst case can go up till the height of the tree

/*
Approach:
1. traverse the tree using DFS.
2. for every node, calculate the max path sum starting from that node and going downwards (either left or right).
3. if a subtree gives a negative sum, we ignore it because it will only reduce the total path sum.
4. at each node, we also check the path that passes through the node (including both left and right subtrees) and update the answer if it is larger.
5. return the maximum path sum that can be extended to the parent.
*/


class Solution {
public:
    // stores the maximum path sum found so far
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        // null node contributes nothing
        if (!root) return 0;

        // get max sum from left subtree (ignore if negative)
        int left = max(0, dfs(root->left));

        // get max sum from right subtree (ignore if negative)
        int right = max(0, dfs(root->right));

        // update answer considering path through this node
        ans = max(ans, root->val + left + right);

        // return max path that bubbles up
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
