# Insert into a Binary Search Tree

## Problem Statement
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

---

### Example1:

<img src="https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg">

Input: root = [4,2,7,1,3], val = 5

Output: [4,2,7,1,3,5]

Explanation: Another accepted tree is:
<img src="https://assets.leetcode.com/uploads/2020/10/05/bst.jpg">


### Example 2:
Input: root = [40,20,60,10,30,50,70], val = 25

link to q: https://leetcode.com/problems/insert-into-a-binary-search-tree/
Output: [40,20,60,10,30,50,70,null,null,25]

### Eample 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5

Output: [4,2,7,1,3,5]
