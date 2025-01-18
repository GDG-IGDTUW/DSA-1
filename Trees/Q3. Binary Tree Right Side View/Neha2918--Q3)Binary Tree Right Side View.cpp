class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // Initialize a vector to store the right side view
        vector<int> res;
        
        // Call the helper function to perform the recursion
        recursionRight(root, 0, res);
        
        // Return the final result
        return res;
    }
    
private:
    // Helper function to recursively traverse the tree
    void recursionRight(TreeNode* root, int level, vector<int> &res) {
        // Base case: if the current node is NULL, return
        if (root == NULL)
            return;
        
        // If the current level equals the size of the result vector,
        // it means we are visiting this level for the first time,
        // so add the current node's value to the result
        if (res.size() == level)
            res.push_back(root->val);
        
        // Recur for the right subtree first (to get the rightmost node at each level)
        recursionRight(root->right, level + 1, res);
        
        // Then recur for the left subtree
        recursionRight(root->left, level + 1, res);
    }
};
