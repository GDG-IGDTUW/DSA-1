import heapq
from typing import List

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        
        k = len(nums)
        heap = []
        current_max = float('-inf')
        
        # Initialize heap
        for i in range(k):
            value = nums[i][0]
            heapq.heappush(heap, (value, i, 0))  # (value, list_index, element_index)
            current_max = max(current_max, value)
        
        best_range = [-10**5, 10**5]
        
        while True:
            min_val, list_idx, elem_idx = heapq.heappop(heap)
            
            # Update best range
            if current_max - min_val < best_range[1] - best_range[0]:
                best_range = [min_val, current_max]
            
            # Move to next element in that list
            if elem_idx + 1 == len(nums[list_idx]):
                break  # One list exhausted
            
            next_val = nums[list_idx][elem_idx + 1]
            heapq.heappush(heap, (next_val, list_idx, elem_idx + 1))
            
            current_max = max(current_max, next_val)
        
        return best_range
