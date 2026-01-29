class Solution(object):
    def myAtoi(self, s):
        
        i=0
        n=len(s)
        while i<n and s[i]==' ':
            i=i+1
        s=s[i:]
        if len(s)==0:
            return 0
        sign=1
        ans=0
        if s[0]=='-':
            sign=-1
        if (s[0]=='+' or s[0]=='-'):
            i=1
        else:
            i=0

        while i<len(s):
            if s[i]==' ' or not s[i].isdigit():
                break

            ans=ans*10+(ord(s[i])-ord('0'))
            if sign == -1 and -ans < -2**31:
                return -2**31
            if sign == 1 and ans > 2**31-1:
                return 2**31-1

            i=i+1

        return sign*ans
