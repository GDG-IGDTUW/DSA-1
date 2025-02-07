class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:        
        stck = [['$', 0]]     # a placeholder to mark stack is empty. This eliminates the need to do an empty check later
        
        for c in s:
            if stck[-1][0] == c:
                stck[-1][1]+=1 # update occurences count of top element if it matches current character
                if stck[-1][1] == k:
                    stck.pop()
            else:
                stck.append([c, 1])            
        
        return ''.join(c * cnt for c, cnt in stck)
            
