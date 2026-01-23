class Solution {
    public int maxCoins(int[] nums) {

        int n = nums.length;
        int[] a = new int[n + 2];
        a[0] = 1;
        a[n + 1] = 1;

        for (int i = 0; i < n; i++)
            a[i + 1] = nums[i];

        int[][] dp = new int[n + 2][n + 2];

        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = Math.max(
                        dp[i][j],
                        dp[i][k - 1] + a[i - 1] * a[k] * a[j + 1] + dp[k + 1][j]
                    );
                }
            }
        }

        return dp[1][n];
    }
}
