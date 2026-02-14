class Solution(object):
    def deleteAndEarn(self, nums):
        if not nums: return 0

        max_num= max(nums)
        values = [0]*(max_num +1)
        for num in nums:
            values[num] += num
        
        prev_max = 0
        curr_max = 0
        for val in values:
            temp = max(curr_max, prev_max+val)
            prev_max = curr_max
            curr_max = temp
        
        return curr_max