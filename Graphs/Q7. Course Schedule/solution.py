# Course Schedule I

"""
PROBLEM SUMMARY:
You are given numCourses labeled from 0 to numCourses - 1 and a list of
prerequisites, where prerequisites[i] = [a, b] means you must complete
course b before taking course a.

Return True if it is possible to finish all courses.
Return False if it is impossible due to a cycle.

------------------------------------------------------------
INTUITION:
This problem can be modeled as a directed graph.

- Each course is a node
- Each prerequisite (b -> a) is a directed edge

If the graph contains a cycle, no valid way exists to complete all courses.
If the graph is acyclic, all courses can be completed.

We detect cycles using topological sorting (Kahn’s Algorithm) - BFS Approach

------------------------------------------------------------
ALGORITHM:
1. Create an adjacency list and an indegree array
2. Add all courses with indegree 0 to a queue
3. While the queue is not empty:
   - Remove a course from the queue
   - Decrease indegree of all dependent courses
   - If any course’s indegree becomes 0, add it to the queue
4. Count how many courses are processed
5. If processed count equals numCourses, return True
   Otherwise, return False

------------------------------------------------------------
TIME COMPLEXITY:
O(V + E)
V = number of courses
E = number of prerequisites

SPACE COMPLEXITY:
O(V + E)
"""

from collections import deque
from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses

        for course, prereq in prerequisites:
            graph[prereq].append(course)
            indegree[course] += 1

        queue = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)

        processed = 0

        while queue:
            curr = queue.popleft()
            processed += 1

            for nxt in graph[curr]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    queue.append(nxt)

        return processed == numCourses
