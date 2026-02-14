class Solution:
    def myPow(self, x, n):
        if n < 0:
            x = 1 / x
            n = -n

        result = 1.0

        while n > 0:
            if n % 2 == 1:
                result *= x
            x *= x
            n //= 2

        return result
