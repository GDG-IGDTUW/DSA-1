// Binary Tree Level Order Traversal : Intuition

/**

What Is Level Order Traversal?
Level order traversal visits a binary tree **level by level**, from **top to bottom** and **left to right**.
It is also known as **Breadth-First Search (BFS)** for trees.

Core Intuition

Think of a queue as a waiting line:

1. Start by putting the **root** into the queue.
2. Remove the front node from the queue and **visit it**.
3. Add its **left child**, then **right child** to the queue.
4. Repeat until the queue is empty.

This guarantees:
- Parent nodes are processed before children
- All nodes in one level are visited before moving to the next

Why Use a Queue?

A queue follows First In, First Out (FIFO) order.

- The root is processed first
- Its children are processed next
- Their children follow after

This natural order enforces **level-by-level traversal**.
**/


//Code
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        result.push_back(level);
    }

    return result;
}

