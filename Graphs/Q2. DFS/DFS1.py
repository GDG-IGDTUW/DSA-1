def dfs_of_graph(adj):
    def dfs(node):
        visited.add(node)
        traversal.append(node)
        for neighbor in adj[node]:
            if neighbor not in visited:
                dfs(neighbor)
    
    visited = set()
    traversal = []
    dfs(0)  # Start DFS from vertex 0
    return traversal

# Example usage:
adj1 = [[2, 3, 1], [0], [0, 4], [0], [2]]
print(dfs_of_graph(adj1))  # Output: [0, 2, 4, 3, 1]

adj2 = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
print(dfs_of_graph(adj2))  # Output: [0, 1, 2, 3, 4]
