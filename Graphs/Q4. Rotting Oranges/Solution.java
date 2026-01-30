class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean vis[][] = new boolean[m][n];

        Queue<int[]> q = new LinkedList<>();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.offer(new int[]{i,j,0}); //row, col, time
                    vis[i][j] = true;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int max = 0;

        while(!q.isEmpty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int arr[] = q.poll();
                for(int j=0; j<4; j++){
                    int nrow = arr[0]+drow[j];
                    int ncol = arr[1]+dcol[j];
                    int time = arr[2]+1;
                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                        q.offer(new int[]{nrow, ncol, time});
                        max = time;
                        vis[nrow][ncol] = true;
                    }
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !vis[i][j]) //a fresh orange remain unrotten
                    return -1;
            }
        }

        return max;
    }
}
