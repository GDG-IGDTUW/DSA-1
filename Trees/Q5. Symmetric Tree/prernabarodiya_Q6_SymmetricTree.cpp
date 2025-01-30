#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool mirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL || left->val != right->val) return false;
        return mirror(left->left, right->right) && mirror(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return mirror(root->left, root->right);
    }
};

// Helper function to create the binary tree from the input array
TreeNode* createTree(vector<int> nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (nodes[i] != -1) {  // Assuming -1 represents NULL
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    vector<int> nodes = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root = createTree(nodes);

    Solution solution;
    bool result = solution.isSymmetric(root);

    cout << (result ? "true" : "false") << endl;

    return 0;
}