# Q2. Best Time to Buy and Sell Stock

LeetCode: [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

## Sample Test Cases

- Input: `prices = [7,1,5,3,6,4]`
  Output: `5`
  Explanation: Buy on day 2 (`price = 1`) and sell on day 5 (`price = 6`), profit is `6 - 1 = 5`.

- Input: `prices = [7,6,4,3,1]`
  Output: `0`
  Explanation: No transaction yields a positive profit.

## Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

## NOTE
Provide a screenshot of the accepted solution on LeetCode, including the left pane in description of Pull request and push the solution.

##this a  solution for the best time to buy and sell problem in cpp:
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buyprice = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) 
        {
            if (prices[i] < buyprice)
             {
                buyprice = prices[i];
             } 
             else
             {
                profit = max(profit, prices[i] - buyprice);
             }
        }

        return profit;
    }
};

