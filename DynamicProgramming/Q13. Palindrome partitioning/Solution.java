class Solution {
    public int minCut(String s) {
        int n = s.length();
        
        // isPal[i][j] = true if s[i..j] is palindrome
        boolean[][] isPal = new boolean[n][n];
        
        // dp[i] = min cuts needed for s[0..i]
        int[] dp = new int[n];
        
        for (int i = 0; i < n; i++) {
            dp[i] = i; // worst case: cut at every character
            
            for (int j = 0; j <= i; j++) {
                if (s.charAt(i) == s.charAt(j) &&
                    (i - j <= 2 || isPal[j + 1][i - 1])) {
                    
                    isPal[j][i] = true;
                    
                    // If palindrome starts from 0, no cut needed
                    if (j == 0) {
                        dp[i] = 0;
                    } else {
                        dp[i] = Math.min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
}
