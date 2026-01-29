/*
PROBLEM: Zig Zag (Spiral) Traversal of Binary Tree

Given the root of a binary tree, return the zig zag
level order traversal of its nodes' values.

Zig Zag Traversal means:
- Level 0: Left to Right
- Level 1: Right to Left
- Level 2: Left to Right
- and so on...

INTUITION

- This is a variation of level order traversal (BFS).
- We traverse the tree level by level using a queue.
- For each level, we decide the direction of traversal.
- If direction is left to right, we store values normally.
- If direction is right to left, we store values in reverse order.
- After each level, we toggle the direction.

*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;

    if (root == NULL) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level(levelSize);

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            int index;
            if (leftToRight) {
                index = i;
            } else {
                index = levelSize - 1 - i;
            }

            level[index] = node->val;

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        result.push_back(level);
        leftToRight = !leftToRight;
    }

    return result;
}

/*
APPROACH (BFS USING QUEUE)

1. Use a queue to perform level order traversal.
2. Maintain a boolean flag to track direction.
3. For each level:
   - Create a temporary array of size = number of nodes in that level.
   - Place node values at correct index based on direction.
4. Push children into the queue for next level.
5. Toggle direction after processing each level.


TIME & SPACE COMPLEXITY

TIME COMPLEXITY:
- O(n), where n is the number of nodes.
- Each node is visited exactly once.

SPACE COMPLEXITY:
- O(n) for the queue and result storage.
*/
