class Solution {
    public int func(int[] dp,int n){
        if(n==0 || n==1) dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        int left =func(dp,n-1);
        int right=func(dp,n-2);
        dp[n]=left+right;
        return dp[n];
        
    }
    
    public int climbStairs(int n) {
        int [] dp=new int[n+1];
        Arrays.fill(dp, -1);
        return func(dp,n);
        
    }
}