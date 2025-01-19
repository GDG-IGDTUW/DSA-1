class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // Start with the leftmost node of the tree
        Node* leftmost = root;

        while (leftmost->left) { // Since it's a perfect binary tree
            Node* current = leftmost;

            // Connect the nodes in the current level
            while (current) {
                // Connect the left and right child
                current->left->next = current->right;

                // Connect the right child to the next node's left child
                if (current->next) {
                    current->right->next = current->next->left;
                }

                // Move to the next node in the same level
                current = current->next;
            }

            // Move to the next level
            leftmost = leftmost->left;
        }

        return root;
    }
};