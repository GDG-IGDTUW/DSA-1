from collections import defaultdict, deque

class Solution:
    def findOrder(self, numCourses, prerequisites):
        
        # Step 1: Build graph
        graph = defaultdict(list)
        indegree = [0] * numCourses
        
        for a, b in prerequisites:
            graph[b].append(a)   # edge b → a
            indegree[a] += 1
        
        # Step 2: Add nodes with indegree 0
        queue = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
        
        order = []
        
        # Step 3: Process queue
        while queue:
            node = queue.popleft()
            order.append(node)
            
            for neighbor in graph[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        
        # Step 4: Check if valid
        if len(order) == numCourses:
            return order
        else:
            return []
