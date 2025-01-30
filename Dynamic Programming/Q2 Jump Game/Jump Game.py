class Solution(object):
    def canJump(self, nums):
        n = len(nums)
        f = n-1
        for i in range(n-2,-1,-1):
            if(i+nums[i]>=f):
                f=i
        return f==0
