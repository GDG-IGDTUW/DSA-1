class Solution {
    public int climbStairs(int n) {

        int[] dp=new int[n+1];
        Arrays.fill(dp,-1);

        return countWays(n,dp);
    }

    private int countWays(int idx,int[] dp){

        // base condition
        if(idx==0) return 1;

        // dp chk
        if(dp[idx]!=-1) return dp[idx];

        // move 1 step
        int step1=countWays(idx-1,dp);

        // move 2 step
        int step2=0;
        if(idx>1) step2=countWays(idx-2,dp);

        // add total no of ways
        return dp[idx]=step1+step2;


    }
}