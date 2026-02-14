class Solution(object):
    def minFallingPathSum(self, matrix):
        n = len(matrix)
        dp = matrix[0][:]

        for i in range(1, n):
            new = [0] * n
            for j in range(n):
                best = dp[j]
                if j > 0:
                    best = min(best, dp[j - 1])
                if j + 1 < n:
                    best = min(best, dp[j + 1])
                new[j] = matrix[i][j] + best
            dp = new

        return min(dp)
