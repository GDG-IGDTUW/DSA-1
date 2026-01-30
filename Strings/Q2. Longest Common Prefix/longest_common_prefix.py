class Solution(object):
    def longestCommonPrefix(self, strs):
        strs.sort()
        
        first = strs[0]
        last = strs[-1]
        ans = ""
        
        for i in range(len(first)):
            if first[i] == last[i]:
                ans += first[i]
            else:
                break
        
        return ans
        
