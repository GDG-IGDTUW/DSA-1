import java.util.*;
/*
In this qsn, we have to reach right bottom point from top left point in a grid. We can only move right or down. We have to find the minimum path sum.
We can use recursion for this -> by picking right & down everytime and then taking the minimum of all two. But this will be very time consuming.
For this we use Dynamic Programming. We can use two approaches for this -> Memoization and Tabulation.

Memoization:

A 2D dp array is used to store the calculated minimum path sums for visited states.
If the dp value for a given row and column is not -1, it means the result has already been calculated, and it's returned directly.
Otherwise, the recursive calls are made, and the result is stored in the dp array for future reference.

Tabulation:

A 2D dp array is initialized with the value of the top-left corner.
The dp array is filled bottom-up, starting from the second row and column.
For each cell, the minimum path sum from the previous cell (either above or to the left) is calculated and added to the current cell's value.
The final result is the value in the bottom-right corner of the dp array
 */

public class TannuRawatQ4MinimumPathSum {

    // Memoization Approach -> Time complexity: O(n*m), Space complexity: O(n*m) +
    // O(n) for recursion stack
    public static int minPathSumMemo(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] memo = new int[n + 1][m + 1];
        for (int[] num : memo)
            Arrays.fill(num, -1);
        return minPathSumMemo(0, 0, n, m, grid, memo);
    }

    public static int minPathSumMemo(int i, int j, int n, int m, int[][] grid, int[][] memo) {
        if (i >= n || j >= m)
            return Integer.MAX_VALUE;

        if (i == n - 1 && j == m - 1)
            return grid[i][j];
        if (memo[i][j] != -1)
            return memo[i][j];
        return memo[i][j] = grid[i][j]
                + Math.min(minPathSumMemo(i + 1, j, n, m, grid, memo), minPathSumMemo(i, j + 1, n, m, grid, memo));
    }

    // Tabulation Approach -> Time complexity: O(n*m), Space complexity: O(n*m)
    public static int minPathSumTab(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int dp[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int w1 = grid[i][j];
                int w2 = grid[i][j];
                if (i > 0) {
                    w1 += dp[i - 1][j];
                } else {
                    w1 += 1e7;
                }
                if (j > 0) {
                    w2 += dp[i][j - 1];
                } else {
                    w2 += 1e7;
                }
                dp[i][j] = Math.min(w1, w2);
            }
        }
        return dp[m - 1][n - 1];
    }

    // Main function
    public static void main(String[] args) {
        int[][] grid = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
        System.out.println("Minimum Path Sum using Memoization: " + minPathSumMemo(grid));
        System.out.println("Minimum Path Sum using Tabulation: " + minPathSumTab(grid));
    }
}
