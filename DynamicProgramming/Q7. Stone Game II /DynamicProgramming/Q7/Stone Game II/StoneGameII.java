// Stone Game II
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

import java.util.*;

class Solution {
    private int[][] dp;
    private int[] suffixSum;
    private int n;

    public int stoneGameII(int[] piles) {
        n = piles.length;
        dp = new int[n][n + 1];
        suffixSum = new int[n];

        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return helper(0, 1);
    }

    private int helper(int i, int m) {
        if (i >= n) return 0;

        if (2 * m >= n - i) {
            return suffixSum[i];
        }

        if (dp[i][m] != 0) return dp[i][m];

        int maxStones = 0;

        for (int x = 1; x <= 2 * m; x++) {
            int opponent = helper(i + x, Math.max(m, x));
            maxStones = Math.max(maxStones, suffixSum[i] - opponent);
        }

        dp[i][m] = maxStones;
        return maxStones;
    }
}
