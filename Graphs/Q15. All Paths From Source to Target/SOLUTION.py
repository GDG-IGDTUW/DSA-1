from collections import defaultdict, deque

class Solution:
    def possibleBipartition(self, n: int, dislikes: list[list[int]]) -> bool:
        graph = defaultdict(list)
        for a, b in dislikes:
            graph[a].append(b)
            graph[b].append(a)
        
     
        color = [0] * (n + 1)
       
        for person in range(1, n + 1):
            if color[person] != 0:
                continue
            
            queue = deque([person])
            color[person] = 1
            
            while queue:
                current = queue.popleft()
                
                for neighbor in graph[current]:
                    if color[neighbor] == 0:
                        color[neighbor] = -color[current]
                        queue.append(neighbor)
                    elif color[neighbor] == color[current]:
                        return False
        
        return True
