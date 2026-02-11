"""
Intuition:
This problem is essentially asking for the number of connected components
in an undirected graph represented as an adjacency matrix.

If a city is directly or indirectly connected to another city,
they belong to the same province.

So the task reduces to:
Count how many connected components exist in the graph.

We can use DFS (or BFS) to traverse each component fully,
marking visited cities to avoid recounting them.
Each time we start a DFS from an unvisited city,
we have found a new province.

Algorithm:
1. Maintain a visited array of size n initialized to False.
2. Iterate through each city:
   - If not visited:
       - Perform DFS starting from that city.
       - Mark all reachable cities as visited.
       - Increment province count.
3. Return province count.

Complexity:
Time Complexity: O(n^2)
- We potentially visit every cell in the adjacency matrix once.

Space Complexity: O(n)
- Visited array takes O(n)
- DFS recursion stack worst case O(n)
"""

class Solution:
    def findCircleNum(self, isConnected):
        n = len(isConnected)
        visited = [False] * n
        provinces = 0

        def dfs(city):
            for neighbor in range(n):
                if isConnected[city][neighbor] == 1 and not visited[neighbor]:
                    visited[neighbor] = True
                    dfs(neighbor)

        for city in range(n):
            if not visited[city]:
                visited[city] = True
                dfs(city)
                provinces += 1

        return provinces
