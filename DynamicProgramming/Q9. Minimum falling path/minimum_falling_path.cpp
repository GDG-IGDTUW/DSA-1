class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> t(n, vector<int>(n));

    // fill the first row
    for (int j=0; j<n; j++) {
        t[0][j] = matrix[0][j];
    }

    // fill the rest of t
    for (int i=1; i<n; i++) {
        for (int j=0; j<n; j++) {
            // 3 possibilities:
            // 1. t[i-1][j-1] -can go out of boundary if j=0
            // 2. t[i-1][j]
            // 3. t[i-1][j+1] -can go out of boundary if j=n-1
            int x= INT_MAX, y= INT_MAX;
            if (j-1>=0) x=t[i-1][j-1];
            if (j+1<n)  y=t[i-1][j+1];

            t[i][j] = matrix[i][j]+min({t[i-1][j], x, y});
        }
    }

    // find min value in the last row
    int result = INT_MAX;
    int last_i = n-1;
    for (int j =0; j<n; j++) {
        result = min(result, t[last_i][j]);
    }

    return result;
    }
};
