class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid,vector<vector<bool>>&vis ){
        int m=grid.size();
        int n=grid[0].size();

        if(row<0 || col<0 || row>=m || col>=n || vis[row][col]||grid[row][col]!=1){
            return 0;
        }

        vis[row][col]=true;

        int left=dfs(row,col-1,grid,vis);
        int right=dfs(row,col+1,grid,vis);
        int up=dfs(row-1,col,grid,vis);
        int down=dfs(row+1,col,grid,vis);

        return 1+ left+right+up+down;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int size=dfs(i,j,grid,vis);
                    ans=max(ans,size);
                }

            }
        }
        return ans;
        
    }
};
