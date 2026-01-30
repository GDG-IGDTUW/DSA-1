class Solution:
    def romanToInt(self, s):
        mp = {
            'I':1,'V':5,'X':10,
            'L':50,'C':100,
            'D':500,'M':1000
        }
        total = 0
        for i in range(len(s)):
            if i+1<len(s) and mp[s[i]]<mp[s[i+1]]:
                total-=mp[s[i]]
            else:
                total+=mp[s[i]]
        return total

        
