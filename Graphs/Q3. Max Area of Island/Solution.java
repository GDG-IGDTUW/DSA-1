class Solution {
    public int dfs(int row, int col, int grid[][], boolean vis[][]){
        vis[row][col] = true;

        int m = grid.length;
        int n = grid[0].length;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int area = 1;
        for(int i=0; i<4; i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                area += dfs(nrow, ncol, grid, vis);
            }
        }
        return area;
    }

    public int maxAreaOfIsland(int[][] grid) {
        int max = 0;
        int m = grid.length;
        int n = grid[0].length;
        boolean vis[][] = new boolean[m][n];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area = dfs(i, j, grid, vis);
                    max = Math.max(max, area);
                }
            }
        }

        return max;
    }
}
