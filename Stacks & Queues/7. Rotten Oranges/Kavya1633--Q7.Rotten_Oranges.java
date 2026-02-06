class Solution {
    public class tuple{
        int row;
        int col;
        int time;
        tuple(int r,int c,int t){
            this.row=r;
            this.col=c;
            this.time=t;
        }
    }
    public int orangesRotting(int[][] grid) {

        int m=grid.length;
        int n=grid[0].length;

        // queue
        Queue<tuple> q=new LinkedList<>();
        // visited array
        int[][] vis=new int[m][n];


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // add all rotten oranges in queue at time 0
                if(grid[i][j]==2){
                    q.add(new tuple(i,j,0));
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
            }
        }

        int[] nrow={0,-1,0,1};
        int[] ncol={-1,0,1,0};

        int maxtime=0;
        while(!q.isEmpty()){
            int r=q.peek().row;
            int c=q.peek().col;
            int t=q.peek().time;
            q.remove();

            // maxTime to rotten all oranges
            maxtime=Math.max(maxtime,t);

            for(int i=0;i<4;i++){
                // 4 - direction movement
                int row=r+nrow[i];
                int col=c+ncol[i];
                if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==1 && vis[row][col]==0){
                    vis[row][col]=2;
                    q.add(new tuple(row,col,t+1));
                }
            }
        }

        // chk there still exist fresh Orange
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }

        return maxtime;

    }
}