class Solution {
public:
    int amountOfTime(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* targetNode = nullptr;

        //BFS to map parents and find target
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == target)
                targetNode = curr;

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        // BFS to burn the tree
        unordered_map<TreeNode*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // left child
                if (curr->left && !visited[curr->left]) {
                    burned = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                // right child
                if (curr->right && !visited[curr->right]) {
                    burned = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                // parent
                if (parent[curr] && !visited[parent[curr]]) {
                    burned = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            if (burned) time++;
        }

        return time;
    }
};
