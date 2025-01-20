class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        result = [[float("inf")] * (COLS + 1) for r in range(ROWS + 1)]
        result[ROWS][COLS - 1] = 0
        
        for r in range(ROWS - 1, -1, -1):
            for c in range(COLS - 1, -1, -1):
                if c == COLS - 1:
                    result[r][c] = grid[r][c] + result[r + 1][c]
                elif r == ROWS - 1:
                    result[r][c] = grid[r][c] + result[r][c + 1]
                else:
                    result[r][c] = grid[r][c] + min(result[r + 1][c], result[r][c + 1])
        
        return result[0][0]

sol = Solution()
grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
print(sol.minPathSum(grid)) 
