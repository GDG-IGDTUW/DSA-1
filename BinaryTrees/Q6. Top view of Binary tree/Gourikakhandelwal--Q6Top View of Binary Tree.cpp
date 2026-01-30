/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // Result vector to store top view nodes
        vector<int> v;

        // If tree is empty, return empty vector
        if (!root) return v;

        // Map to store the first node at each horizontal distance (HD)
        // Key: HD, Value: Node's data
        map<int, int> hdMap;

        // Queue for level-order traversal (BFS)
        // Each element is a pair of (Node pointer, HD)
        queue<pair<Node*, int>> q;
        q.push({root, 0});  // Root has HD = 0

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            Node* node = p.first;
            int hd = p.second;

            // If this HD is not yet in the map, add it
            // This ensures only the topmost node at each HD is stored
            if (hdMap.find(hd) == hdMap.end()) {
                hdMap[hd] = node->data;
            }

            // Add left child with HD - 1
            if (node->left) {
                q.push({node->left, hd - 1});
            }

            // Add right child with HD + 1
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // Extract values from map in order of increasing HD
        for (auto it : hdMap) {
            v.push_back(it.second);
        }

        return v;
    }
};