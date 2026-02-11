# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def flatten(self, root):
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        
        # Flatten left and right subtrees
        self.flatten(root.left)
        self.flatten(root.right)
        
        # Store the right subtree
        right_subtree = root.right
        
        # Move left subtree to the right
        root.right = root.left
        root.left = None
        
        # Find the tail of the new right subtree
        curr = root
        while curr.right:
            curr = curr.right
        
        # Attach the original right subtree
        curr.right = right_subtree
