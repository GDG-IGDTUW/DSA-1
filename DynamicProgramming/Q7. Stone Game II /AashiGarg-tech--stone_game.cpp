class Solution {
    public:
        int n;
        vector<int> suffix;
        int dp[105][105];
    
        int solve(int i, int M) {
            if (i >= n) return 0;
            if (dp[i][M] != -1) return dp[i][M];
    
            int best = 0;
    
            for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                best = max(best, suffix[i] - solve(i + X, max(M, X)));
            }
    
            return dp[i][M] = best;
        }
    
        int stoneGameII(vector<int>& piles) {
            n = piles.size();
            suffix.resize(n + 1, 0);
    
            for (int i = n - 1; i >= 0; i--)
                suffix[i] = suffix[i + 1] + piles[i];
    
            memset(dp, -1, sizeof(dp));
    
            return solve(0, 1);
        }
    };