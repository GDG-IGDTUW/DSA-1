#include <iostream>
using namespace std;

// Definition for a Node in the binary tree
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Function to populate the next right pointers
Node* connect(Node* root) {
    if (!root) return root; // Base case: empty tree

    // Start at the first level
    Node* levelStart = root;

    while (levelStart->left) { // Iterate until there are no more levels
        Node* curr = levelStart;

        while (curr) { // Connect nodes at the current level
            // Connect the left child to the right child
            curr->left->next = curr->right;

            // Connect the right child to the next node's left child (if exists)
            if (curr->next)
                curr->right->next = curr->next->left;

            // Move to the next node in the current level
            curr = curr->next;
        }

        // Move to the next level
        levelStart = levelStart->left;
    }

    return root;
}

// Helper function to print the tree level by level using the next pointers
void printTreeWithNextPointers(Node* root) {
    Node* levelStart = root;

    while (levelStart) {
        Node* curr = levelStart;

        // Traverse the current level
        while (curr) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }

        cout << "NULL" << endl; // End of the current level
        levelStart = levelStart->left; // Move to the next level
    }
}

// Example usage
int main() {
    // Create a perfect binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Connect next right pointers
    connect(root);

    // Print the tree with next pointers
    cout << "Tree levels with next pointers:" << endl;
    printTreeWithNextPointers(root);

    return 0;
}
