'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def topView(self, root):
        if not root:
            return []

        q = deque([(root, 0)])
        top = {}

        while q:
            node, hd = q.popleft()

            if hd not in top:
                top[hd] = node.data

            if node.left:
                q.append((node.left, hd - 1))
            if node.right:
                q.append((node.right, hd + 1))

        return [top[x] for x in sorted(top)]

        