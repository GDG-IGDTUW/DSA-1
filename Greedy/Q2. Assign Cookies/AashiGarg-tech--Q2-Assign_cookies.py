class Solution:
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        child_idx=0
        for cookie_size in s:
            if child_idx<len(g) and cookie_size>=g[child_idx]:
                child_idx+=1
        return child_idx