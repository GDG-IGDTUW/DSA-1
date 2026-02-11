class Solution(object):
    def rob(self, nums):
        if len(nums) == 1:
            return nums[0]

        prev2 = 0 
        prev1 = 0 

        for money in nums:
            curr = max(prev1, prev2 + money)
            prev2 = prev1
            prev1 = curr

        return prev1
