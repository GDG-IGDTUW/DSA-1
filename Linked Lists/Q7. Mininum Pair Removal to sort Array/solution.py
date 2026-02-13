class Solution(object):
    def minimumPairRemoval(self, nums):
        def is_non_decreasing(arr):
            for i in range(1, len(arr)):
                if arr[i] < arr[i - 1]:
                    return False
            return True
        
        operations = 0
        
        while not is_non_decreasing(nums):
            min_sum = float('inf')
            index = -1
            
            # Find adjacent pair with minimum sum
            for i in range(len(nums) - 1):
                pair_sum = nums[i] + nums[i + 1]
                if pair_sum < min_sum:
                    min_sum = pair_sum
                    index = i
            
            # Replace the pair with their sum
            nums = nums[:index] + [min_sum] + nums[index + 2:]
            operations += 1
        
        return operations
