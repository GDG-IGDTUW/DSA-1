class Solution(object):
    def canJump(self, nums):

        goal = 1 
        for i in range(len(nums)-2 , -1 ,-1 ):
            if nums[i] >= goal :
                goal = 1
            else:
                goal += 1 
    
        
        return goal == 1