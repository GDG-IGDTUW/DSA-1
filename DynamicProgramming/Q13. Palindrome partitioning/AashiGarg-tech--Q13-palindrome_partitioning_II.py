class Solution:
    def minCut(self, s):
        n = len(s)
        dp = [0] * (n + 1)

        for i in range(n + 1):
            dp[i] = i - 1

        for center in range(n):
            left = right = center
            while left >= 0 and right < n and s[left] == s[right]:
                dp[right + 1] = min(dp[right + 1], dp[left] + 1)
                left -= 1
                right += 1

            left = center
            right = center + 1
            while left >= 0 and right < n and s[left] == s[right]:
                dp[right + 1] = min(dp[right + 1], dp[left] + 1)
                left -= 1
                right += 1

        return dp[n]