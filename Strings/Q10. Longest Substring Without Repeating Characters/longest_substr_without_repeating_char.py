class Solution(object):
    def lengthOfLongestSubstring(self, s):
        hash = [-1] * 256 
        l = 0
        maxLen = 0
        for r in range(len(s)):
            if hash[ord(s[r])] != -1:
                if hash[ord(s[r])] >= l:
                    l = hash[ord(s[r])] + 1 
            hash[ord(s[r])] = r
            length = r - l + 1
            maxLen = max(maxLen, length)
        return maxLen
