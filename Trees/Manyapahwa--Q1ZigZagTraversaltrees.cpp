#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val; // Node value
    TreeNode* left; // Pointer to the left child
    TreeNode* right; // Pointer to the right child

    // Constructor to initialize the TreeNode
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform zigzag level order traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Vector to store the final result
        vector<vector<int>> result;

        // If the tree is empty, return an empty result
        if (root == nullptr)
            return result;

        // Queue to perform level-order traversal
        queue<TreeNode*> q;

        // Flag to determine the direction of traversal (left-to-right or right-to-left)
        bool leftToRight = true;

        // Start the traversal with the root node
        q.push(root);

        // Continue until all nodes in the tree are processed
        while (!q.empty()) {
            // Number of nodes at the current level
            int count = q.size();

            // Vector to store the current level's values
            vector<int> row(count);

            // Process all nodes at the current level
            for (int i = 0; i < count; i++) {
                // Get the front node in the queue
                TreeNode* curr = q.front();
                q.pop();

                // Determine the correct index for inserting the value based on the traversal direction
                int index = leftToRight ? i : count - i - 1;
                row[index] = curr->val;

                // Add the left child to the queue if it exists
                if (curr->left) {
                    q.push(curr->left);
                }

                // Add the right child to the queue if it exists
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            // After processing the current level, flip the direction for the next level
            leftToRight = !leftToRight;

            // Add the current level's values to the result
            result.push_back(row);
        }

        // Return the final zigzag level order traversal
        return result;
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Sample main function to test the code
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create an instance of Solution and perform the zigzag level order traversal
    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    // Print the result
    cout << "Zigzag Level Order Traversal:" << endl;
    printResult(result);

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
