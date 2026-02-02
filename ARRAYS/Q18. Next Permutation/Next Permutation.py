from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        index = -1

        # Step 1: Find the first decreasing element from the right
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                index = i
                break

        # If no such index exists, reverse the array
        if index == -1:
            nums.reverse()
            return

        # Step 2: Find element just larger than nums[index]
        for i in range(n - 1, index, -1):
            if nums[i] > nums[index]:
                nums[i], nums[index] = nums[index], nums[i]
                break

        # Step 3: Reverse the suffix
        nums[index + 1:] = reversed(nums[index + 1:])
        
