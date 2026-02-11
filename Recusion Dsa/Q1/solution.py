class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        n = len(s)
        sign = 1
        num = 0

        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        # 1. Ignore leading whitespaces
        while i < n and s[i] == ' ':
            i += 1

        # 2. Check sign
        if i < n and (s[i] == '+' or s[i] == '-'):
            if s[i] == '-':
                sign = -1
            i += 1

        # 3. Convert digits
        while i < n and s[i].isdigit():
            num = num * 10 + (ord(s[i]) - ord('0'))

            # 4. Handle overflow
            if sign * num <= INT_MIN:
                return INT_MIN
            if sign * num >= INT_MAX:
                return INT_MAX

            i += 1

        return sign * num
