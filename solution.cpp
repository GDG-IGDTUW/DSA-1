class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=true;
                    q.push({{i,j},0});
                }
            }
        }

        int ans=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();

            ans=max(ans,time);

            if(row-1>=0 && !vis[row-1][col] && grid[row-1][col]==1){
                grid[row-1][col]=2;
                vis[row-1][col]=true;
                q.push({{row-1,col},time+1});

            }
            if(row+1<m && !vis[row+1][col] && grid[row+1][col]==1){
                grid[row+1][col]=2;
                vis[row+1][col]=true;
                q.push({{row+1,col},time+1});

            }
            if(col-1>=0 && !vis[row][col-1] && grid[row][col-1]==1){
                grid[row][col-1]=2;
                vis[row][col-1]=true;
                q.push({{row,col-1},time+1});

            }
            if(col+1<n && !vis[row][col+1] && grid[row][col+1]==1){
                grid[row][col+1]=2;
                vis[row][col+1]=true;
                q.push({{row,col+1},time+1});

            }

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};
