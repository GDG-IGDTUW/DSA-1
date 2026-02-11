class Solution:
    def combinationSum(self, candidates, target):
        res = []
        
        def backtrack(start, curr, total):
            if total == target:
                res.append(curr[:])
                return
            if total > target:
                return
            
            for i in range(start, len(candidates)):
                curr.append(candidates[i])
                backtrack(i, curr, total + candidates[i])  # reuse same element
                curr.pop()
        
        backtrack(0, [], 0)
        return res
