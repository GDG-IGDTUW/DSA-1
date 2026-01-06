# Burning Tree

Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

Note: The tree contains unique values.

---

### Example1:
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/702131/Web/Other/blobid0_1747048733.webp">

Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2

Output: 3

Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.

### Example2:
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/702131/Web/Other/blobid1_1747048769.webp">

Input: root = [1, 2, 3, 4, 5, N, 7, 8, N, N, 10], target = 10

Output: 5

Explanation: Initially 10 is set to fire at 0 sec 
At 1 sec: Node 5 catches fire.
At 2 sec: Node 2 catches fire.
At 3 sec: Nodes 1 and 4 catches fire.
At 4 sec: Node 3 and 8 catches fire.
At 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.

link to q: https://www.geeksforgeeks.org/problems/burning-tree/1
