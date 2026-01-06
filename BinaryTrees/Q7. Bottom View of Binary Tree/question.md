# Bottom View of Binary Tree

## Problem Statement
You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

---

### Example1:


```bash
Input Tree:
        1
       / \
      2   3
     / \   \
    4   5   6
```
Input: root = [1, 2, 3, 4, 5, N, 6]

Output: [4, 2, 5, 3, 6]

### Example 2:
```bash
Input Tree:
         1
       /   \
      2     3
     / \   / \
    4   5 6   7

```

link to q: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
Input: root = [1,2,3,4,5,6,7]

Output: [4,2,5,7]

Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
