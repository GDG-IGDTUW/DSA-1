public class knapsack {
    public static long knapsack(int[] weights, int[] values, int n, int capacity) {
        long[] dp = new long[capacity + 1];
        for (int i = 0; i < n; i++) {
            for (int j = capacity; j >= weights[i]; j--) {
                dp[j] = Math.max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
        return dp[capacity];
    }

    public static void main(String[] args) {
        int n = 5;
        int capacity = 5;

        int[] weights = {1,1,1,1,1};
        int[] values = {1000000000,1000000000,1000000000,1000000000,1000000000};

        long result = knapsack(weights, values, n, capacity);
        System.out.println(result);
    }
}
