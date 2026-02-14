class Solution:
    def stoneGameII(self, piles):
        n = len(piles)

        suffix = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        dp = [[-1] * (n + 1) for _ in range(n + 1)]

        def helper(i, m):
            if i >= n:
                return 0
            if dp[i][m] != -1:
                return dp[i][m]

            if i + 2 * m >= n:
                dp[i][m] = suffix[i]
                return dp[i][m]

            best = 0
            for x in range(1, 2 * m + 1):
                opponent = helper(i + x, max(m, x))
                best = max(best, suffix[i] - opponent)

            dp[i][m] = best
            return best

        return helper(0, 1)