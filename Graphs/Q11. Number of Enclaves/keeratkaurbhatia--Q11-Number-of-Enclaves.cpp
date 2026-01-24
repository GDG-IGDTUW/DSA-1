// TC : O(m*n) — each cell processed once
// SC : O(m*n) due to DFS stack, O(1) additional data structures


/*
Approach:
1. any land cell connected to the boundary cannot be an enclave.
2. perform DFS from all boundary land cells and mark them as water (flooding).
3. count remaining land cells inside the grid.
*/

class Solution {
public:
    void dfs(int si, int sj, vector<vector<int>>& grid) 
    {
        int m = grid.size(); //no. of rows
        int n = grid[0].size(); //no. of cols

        stack<pair<int,int>> st;
        st.push({si, sj});
        grid[si][sj] = 0; //mark visited

        //possible moves (up, down, left, and right)
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!st.empty()) 
        {
            auto [i, j] = st.top();
            st.pop();

            //for all 4 possible moves
            for (int d = 0; d < 4; d++) 
            {
                //new indexes
                int ni = i + dx[d];
                int nj = j + dy[d];

                //if new indexes are valid and the new cell is land
                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    grid[ni][nj] == 1) {
                    
                    grid[ni][nj] = 0; //mark immediately
                    st.push({ni, nj}); //further exploration
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // boundary traversal: first and last row
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) dfs(0, j, grid);
            if (grid[m-1][j] == 1) dfs(m-1, j, grid);
        }

        //boundary traversal: first and last col
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) dfs(i, 0, grid);
            if (grid[i][n-1] == 1) dfs(i, n-1, grid);
        }

        // count enclaves inside the boundary region
        int count = 0;
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (grid[i][j] == 1) 
                    count++;
            }
        }
        return count;
    }
};
