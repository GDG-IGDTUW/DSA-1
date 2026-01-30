class Solution(object):
    def moveZeroes(self, nums):
        j = 0
        for i in range(len(nums)) :
            if nums[i] != 0 :
                nums[j], nums[i] = nums[i], nums[j]
                j += 1
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
