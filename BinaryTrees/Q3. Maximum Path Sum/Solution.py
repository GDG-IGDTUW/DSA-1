# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.max = float('-inf')

    def helper(self, root):
        if root is None:
            return 0
        
        left = max(0, self.helper(root.left))
        right = max(0, self.helper(root.right))
        
        sum_val = root.val + left + right
        self.max = max(self.max, sum_val)
        
        return max(left, right) + root.val

    def maxPathSum(self, root: Optional['TreeNode']) -> int:
        if root.left is None and root.right is None:
            return root.val
        
        self.helper(root)
        return self.max
