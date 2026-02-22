"""
INTUITION

We want to pick exactly one number from each of the K sorted lists.

These picked numbers form a window:

    [minimum picked , maximum picked]

Our goal is to make this window as small as possible while still
covering at least one element from every list.

Key observation:

At any moment,
the minimum element is what is limiting the range.

To shrink the range, we must try to increase the minimum.
And the only way to do that is to move forward in the list
from which the minimum came.

So strategy becomes:

1. Always track:
    - Current minimum
    - Current maximum

2. Move forward ONLY in the list which currently
   has the minimum element.

To do this efficiently:

We use a Min Heap to always know the smallest element
among our current selections.

Heap stores:

    (value, list_index, element_index)

Algorithm Steps:

1. Insert first element of every list into heap.
2. Track the current maximum separately.
3. Repeat:
    - Pop the minimum
    - Update best range
    - Move to next element in the same list
    - Push it into heap
    - Update max
4. Stop when any list gets exhausted
"""

 def smallestRange(self, nums: List[List[int]]) -> List[int]:
         
        k = len(nums)
        
        min_heap = []
        current_max = float('-inf')
        
        # Step 1: Initialize heap
        for i in range(k):
            heapq.heappush(min_heap, (nums[i][0], i, 0))
            current_max = max(current_max, nums[i][0])
        
        best_start = 0
        best_end = float('inf')
        
        while True:
            current_min, list_idx, elem_idx = heapq.heappop(min_heap)
            
            # Update best range
            if current_max - current_min < best_end - best_start:
                best_start = current_min
                best_end = current_max
            
            # Stop if any list ends
            if elem_idx + 1 == len(nums[list_idx]):
                break
            
            next_val = nums[list_idx][elem_idx + 1]
            heapq.heappush(min_heap, (next_val, list_idx, elem_idx + 1))
            
            current_max = max(current_max, next_val)
        
        return [best_start, best_end]
        
