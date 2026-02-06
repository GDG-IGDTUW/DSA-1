class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        // dp[i] = min total cost to reach step i
        int[] dp = new int[n];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
        }

        // You can finish from the last step or the second-last step
        return Math.min(dp[n - 1], dp[n - 2]);
    }
}
