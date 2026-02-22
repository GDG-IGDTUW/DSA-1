"""
INTUITION

We want to pick two lines that form the container storing
maximum water.

Water stored depends on:

    width * min(height[left], height[right])

Brute force checks all pairs → O(n²)

Better approach:

Start with the widest possible container:

    left = 0
    right = n-1

At every step, the shorter line limits the water height.

Moving the taller line inward only reduces width
without improving height → useless.

So we always move the shorter line inward,
hoping to find a taller one.

This greedy decision leads to optimal solution.
"""

"""
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""


class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        left = 0
        right = len(height) - 1
        max_water = 0
        
        while left < right:
            
            width = right - left
            h = min(height[left], height[right])
            max_water = max(max_water, width * h)
            
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return max_water

