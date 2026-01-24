#include<iostream>
#include<string>
#include<queue>
#include<sstream>
#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



 // Note: This problem can also be solved using DFS (preorder traversal).
// However, BFS (level-order traversal) is generally more optimized here:
// - It avoids deep recursion (better memory usage).
// - It is faster for balanced trees since we process nodes iteratively.

class Codec {
public:
    // -------------------------------
    // SERIALIZE: Convert tree -> string
    // -------------------------------
    string serialize(TreeNode* root) {
        // If tree is empty, return "[]"
        if (!root) return "[]";

        // Use BFS (level-order traversal) with a queue
        queue<TreeNode*> q;
        q.push(root);

        string result = "["; // start with opening bracket

        while (!q.empty()) {
            TreeNode* node = q.front(); 
            q.pop();

            if (node) {
                // Append node value to result
                result += to_string(node->val) + ",";
                // Push children (may be NULL) to queue
                q.push(node->left);
                q.push(node->right);
            } else {
                // Append "null" for missing child
                result += "null,";
            }
        }

        // Replace last comma with closing bracket
        result.back() = ']';
        return result;
    }

    // -------------------------------
    // DESERIALIZE: Convert string -> tree
    // -------------------------------
    TreeNode* deserialize(string data) {
        // Handle empty tree case
        if (data == "[]") return NULL;

        // Remove outer brackets
        data = data.substr(1, data.size() - 2);

        // Split string by commas into tokens
        //token is a piece of string between commas
        stringstream ss(data);
        string item;
        vector<string> vals;
        while (getline(ss, item, ',')) {
            vals.push_back(item);
        }

        // First value is the root
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1; // index for child nodes
        while (!q.empty() && i < vals.size()) {
            TreeNode* node = q.front(); 
            q.pop();

            // Process left child
            if (vals[i] != "null") {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;

            // Process right child (check bounds)
            if (i < vals.size() && vals[i] != "null") {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};

// Example usage:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));