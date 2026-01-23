class Solution {
public:
    int climbStairs(int n) {
        // Base case:
        // If there is only 1 step, there is only 1 way to climb it
        if (n == 1) return 1;

        // If there are 2 steps, there are 2 ways:
        // (1 + 1) or (2)
        if (n == 2) return 2;

        // dp[i] will store the number of distinct ways
        // to reach the i-th step
        vector<int> dp(n + 1);

        // Base initialization
        dp[1] = 1; // 1 way to reach step 1
        dp[2] = 2; // 2 ways to reach step 2

        // Bottom-up dynamic programming
        // To reach step i, you can come from:
        // - step (i-1) by taking 1 step
        // - step (i-2) by taking 2 steps
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The answer is the number of ways to reach step n
        return dp[n];
    }
};
