class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int bestbuy=prices[0];   //initializing besy buy starting from 0th idx 
        int maxprofit=0;
        for (int i=0; i<n; i++) {    //running loop
            if (bestbuy<prices[i]) {       //best buy should be less than prices always
                maxprofit=max(maxprofit,prices[i]-bestbuy);  //finding max profit
            }
            bestbuy=min(bestbuy,prices[i]);  //min is the best buy
        }
        if (maxprofit==0) {
            return 0;
        }
        else {
            return maxprofit;
        }
    }
};
