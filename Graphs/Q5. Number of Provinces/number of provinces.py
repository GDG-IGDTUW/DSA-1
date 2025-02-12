class Solution(object):
    def findCircleNum(self, isConnected):
        
        visited = set()
        n = len(isConnected)
        def dfs(j, n):
            visited.add(j)
            for i in range(n):
                if isConnected[j][i] and i not in visited:
                    dfs(i, n)
        c = 0
        for i in range(n):
            if i not in visited:
                c+=1
                dfs(i,n)
        return c