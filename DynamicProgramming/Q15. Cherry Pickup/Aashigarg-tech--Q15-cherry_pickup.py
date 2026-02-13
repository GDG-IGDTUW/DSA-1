class Solution:
    def cherryPickup(self, grid):
        n = len(grid)
        NEG = -10**9

        dp = [[NEG]*n for _ in range(n)]
        dp[0][0] = grid[0][0]

        for k in range(1, 2*n - 1):
            new = [[NEG]*n for _ in range(n)]
            for r1 in range(n):
                c1 = k - r1
                if c1 < 0 or c1 >= n or grid[r1][c1] == -1:
                    continue

                for r2 in range(n):
                    c2 = k - r2
                    if c2 < 0 or c2 >= n or grid[r2][c2] == -1:
                        continue

                    best = dp[r1][r2]

                    if r1 > 0:
                        best = max(best, dp[r1-1][r2])
                    if r2 > 0:
                        best = max(best, dp[r1][r2-1])
                    if r1 > 0 and r2 > 0:
                        best = max(best, dp[r1-1][r2-1])

                    if best < 0:
                        continue

                    cherries = grid[r1][c1]
                    if r1 != r2:
                        cherries += grid[r2][c2]

                    new[r1][r2] = best + cherries

            dp = new

        return max(0, dp[n-1][n-1])
