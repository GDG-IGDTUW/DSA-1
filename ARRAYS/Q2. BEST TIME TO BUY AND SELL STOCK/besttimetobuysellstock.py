class Solution(object):
    def maxProfit(self, prices):
        profit=0
        buy=prices[0]
        i=1
        for i in range(1,len(prices)):
            sell=prices[i]
            profit=max(profit,sell-buy)
            buy= min(buy,sell)

        return profit
