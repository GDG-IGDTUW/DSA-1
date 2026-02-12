class Solution {
public:
    int func(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
         //we can follow any order 
        //hum directly kisi ek ko select krke and uske left ko alg se solve and right ko alg solve asaaa nahinnn kar skte because... left wale ka end walaa element must be dependant to right waaale ka shuruat ke elements se
        //to avoid complicstions humm... brackets htake dono side 1,1 lga denge..
        //basecase
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = 0;

        //try bursting balloon k at last
        for(int k=i;k<=j;k++){
            int cost = nums[i-1] * nums[k] * nums[j+1]
                       + func(i, k-1, nums, dp)
                       + func(k+1, j, nums, dp);

            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        //addinnnn 1 at both ends
        nums.insert(nums.begin(), 1); //front
        nums.push_back(1);            //back

        //dp size (n+2 because of added boundaries)
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

        return func(1, n, nums, dp);  // range of real balloons
    }
};
