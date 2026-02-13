class Solution:
    def maxProfit(self, k, prices):
        n = len(prices)
        if n == 0:
            return 0

        if k >= n // 2:
            profit = 0
            for i in range(1, n):
                if prices[i] > prices[i-1]:
                    profit += prices[i] - prices[i-1]
            return profit

        dp = [0] * n

        for t in range(1, k + 1):
            new_dp = [0] * n
            bestBuy = -prices[0]

            for i in range(1, n):
                new_dp[i] = max(new_dp[i-1], prices[i] + bestBuy)
                bestBuy = max(bestBuy, dp[i] - prices[i])

            dp = new_dp

        return dp[-1]
