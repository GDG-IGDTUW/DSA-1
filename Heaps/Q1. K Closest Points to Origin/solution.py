"""
INTUITION
We are given a list of points on a 2D plane and need to return the k closest points
to the origin (0, 0).

-----------------------------------

Distance from origin is:

 d = sqrt(x^2 + y^2)

But sqrt is unnecessary for comparison.

So we compare using:

    d^2 = x^2 + y^2

Key Idea:
Instead of sorting all points (which would take O(n log n)),
we can maintain only the k closest points using a heap.

Python provides a Min Heap by default.
But we need to remove the farthest point whenever heap size exceeds k.

So we simulate a Max Heap using negative distances.

Steps:
1. Iterate through each point
2. Compute squared distance
3. Push (-distance, x, y) into heap
4. If heap size > k → pop()
   This removes the farthest point

At the end, heap contains k closest points.

-----------------------------------

APPROACH
Use a Max Heap of size k:

For each point:
    compute distance
    push into heap
    if heap size exceeds k:
        remove the point with largest distance

Return remaining points from heap.
-----------------------------------

TIME COMPLEXITY
Let n = number of points

Each heap operation costs log(k)

We do this for all n points.

Total = O(n log k)

Better than sorting → O(n log n)

-----------------------------------
SPACE COMPLEXITY
Heap stores only k elements

Space = O(k)
"""

import heapq
from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        max_heap = []
        
        for x, y in points:
            dist = x*x + y*y
            
            heapq.heappush(max_heap, (-dist, x, y))
            
            if len(max_heap) > k:
                heapq.heappop(max_heap)
        
        return [[x, y] for (_, x, y) in max_heap]
