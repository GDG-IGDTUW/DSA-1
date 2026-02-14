class Solution:
    def subsets(self, nums):
        res = []
        
        def backtrack(index, curr):
            # add current subset
            res.append(curr[:])
            
            for i in range(index, len(nums)):
                curr.append(nums[i])
                backtrack(i + 1, curr)
                curr.pop()
        
        backtrack(0, [])
        return res
