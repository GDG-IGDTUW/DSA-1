//TC : O(m*n) as each cell is visited once in dfs, and final scanning is also once to count the enclaves.
//SC : O(m*n) to maintain the visited matrix, and recursion stack depth in the worst case goes to nxm

/*
Approach:
1. any land cell connected to the boundary cannot be an enclave.
2. run dfs from all boundary land cells and mark all reachable land as visited.
3. after marking, count all unvisited land cells inside the grid (excluding boundary).
4. these remaining land cells are enclaves.
*/

class Solution {
public:
    //grid traversal
    void dfs(pair<int,int> p, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        int i = p.first; //row index
        int j = p.second; //col index
        visited[i][j]=1; //marked visited
        
        //valid moves: up, down, left, right
        vector<pair<int,int>> dir =
        {{-1,0},{1,0},{0,-1},{0,1}};
        
        //for all the moves
        for(pair<int,int> p: dir)
        {
            int nx = i + p.first; //new row index
            int ny = j + p.second; //new col index 
            
            //if valid indexes post move
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size())
            {
                //if the land cell is not visited
                if(!visited[nx][ny] && grid[nx][ny]==1)
                {
                    //traverse
                    dfs({nx,ny},visited, grid);
                }
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
        
        //traversing from the boundaries to exclude the land cells which can NOT be enclaves: first row, first column, last row and last column
        
        //first row = 0 j
        for (int j = 0; j<grid[0].size(); j++)
        {
            if (grid[0][j]==1 && visited[0][j]!=1)
            {
                dfs({0,j},visited, grid);
            }
        }
        
        //first col = i 0
        for (int i = 0; i<grid.size(); i++)
        {
            if (grid[i][0]==1 && visited[i][0]!=1)
            {
                dfs({i,0},visited, grid);
            }
        }
        
        // last row grid.size-1 j
        for (int j = 0; j<grid[0].size(); j++)
        {
            if (grid[grid.size()-1][j]==1 && visited[grid.size()-1][j]!=1)
            {
                dfs({grid.size()-1,j},visited, grid);
            }
        }
        
        //last col = i grid[0].size()-1
        for (int i = 0; i<grid.size(); i++)
        {
            if (grid[i][grid[0].size()-1]==1 && visited[i][grid[0].size()-1]!=1)
            {
                dfs({i,grid[0].size()-1},visited, grid);
            }
        }
        
        
        //traversal inside the boundary region to find unvisted cells, which would give enclaves
        
        int count = 0; //initially no enclaves have been counted
        
        //for all rows except the first and last
        for (int i = 1; i<grid.size()-1; i++)
        {
            //for all columns except the first and last
            for (int j = 1; j<grid[0].size()-1; j++)
            {
                //if it is an unvisted piece of land
                if (grid[i][j]==1 && visited[i][j]==0)
                {
                    count++; //it is an enclave, maintain count
                }
            }
        }
        return count;
    }
};
