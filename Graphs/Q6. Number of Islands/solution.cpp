class Solution {
public:
    void dfs(int i,int j,vector <vector<bool>>&isVis,vector<vector<char>>& grid,int n,int m){

        if(i<0||j<0||i>=n||j>=m||isVis[i][j]||grid[i][j]!='1'){
            return;
        }

        isVis[i][j]=true;

        dfs(i-1,j,isVis,grid,n,m);
        dfs(i,j-1,isVis,grid,n,m);
        dfs(i,j+1,isVis,grid,n,m);
        dfs(i+1,j,isVis,grid,n,m);
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();

        vector <vector<bool>> isVis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !isVis[i][j]){
                    dfs(i,j,isVis,grid,n,m);
                    islands++;
                }
            } 
        }
        
        return islands;
    }
};
