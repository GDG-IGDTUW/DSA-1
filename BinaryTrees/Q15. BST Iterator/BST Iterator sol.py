# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class BSTIterator:

    def __init__(self, root):
        self.stack = []
        self._push_left(root)

    # Push all left nodes into stack
    def _push_left(self, node):
        while node:
            self.stack.append(node)
            node = node.left

    def next(self):
        # Pop the top node (next smallest)
        node = self.stack.pop()
        
        # If right child exists, push its left subtree
        if node.right:
            self._push_left(node.right)
            
        return node.val

    def hasNext(self):
        return len(self.stack) > 0
