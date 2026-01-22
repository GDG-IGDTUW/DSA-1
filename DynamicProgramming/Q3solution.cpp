class Solution {
public:
    int hr(int idx, vector<int>& nums, vector<int>&dp) {
        if(idx<0){
            return 0;
        }
        if(idx==0){
            return nums[0];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=nums[idx]+hr(idx-2,nums,dp);

        int notTake=hr(idx-1,nums,dp);

        return dp[idx]=max(take,notTake);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);

        return hr(n-1,nums,dp);
        
    }
};
