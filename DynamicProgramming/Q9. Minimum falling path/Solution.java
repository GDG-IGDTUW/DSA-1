class Solution {
    public int minFallingPathSum(int[][] m) {

        int n = m.length;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int a = m[i - 1][j];

                if (j > 0)
                    a = Math.min(a, m[i - 1][j - 1]);

                if (j < n - 1)
                    a = Math.min(a, m[i - 1][j + 1]);

                m[i][j] += a;
            }
        }

        int ans = m[n - 1][0];
        for (int j = 1; j < n; j++)
            ans = Math.min(ans, m[n - 1][j]);

        return ans;
    }
}
