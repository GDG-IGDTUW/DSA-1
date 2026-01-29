class Solution {
    public int helper(int ind, String s, int dp[]){
        if(ind == s.length())
            return 1;
        if(dp[ind]!=-1)
            return dp[ind];
        int ans = 0;
        for(int i=ind; i<ind+2 && i<s.length(); i++){
            String num = s.substring(ind, i+1);
            if(num.startsWith("0"))
                continue;
            int val = Integer.parseInt(num);
            if(val>=1 && val<=26){
                ans += helper(i+1, s, dp);
            }
        }
        return dp[ind] = ans;
    }

    public int numDecodings(String s) {
        int dp[] = new int[s.length()+1];
        Arrays.fill(dp, -1);
        return helper(0, s, dp);
    }
}
