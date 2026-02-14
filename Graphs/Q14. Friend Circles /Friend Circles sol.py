class Solution:
    def allPathsSourceTarget(self, graph):
        res = []
        path = [0]
        target = len(graph) - 1

        def dfs(node):
            if node == target:
                res.append(path[:])
                return
            
            for nei in graph[node]:
                path.append(nei)
                dfs(nei)
                path.pop()   # backtrack

        dfs(0)
        return res
