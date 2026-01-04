# Top View of Binary Tree

## Problem Statement
You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 

---

### Example1:


```bash
Input Tree:
        1
       / \
      2   3
```
Input: root = [1, 2, 3]

Output: [2, 1, 3]

### Example 2:
```bash
Input Tree:
         10
       /   \
      20    30
     / \   / \
    40 60 90  100

```
Input: root = [10, 20, 30, 40, 60, 90, 100]

Output: [40, 20, 10, 30, 100]

Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
