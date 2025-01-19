class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Queue to perform BFS; stores the position of rotten oranges and the time elapsed
        queue<pair<pair<int, int>, int>> q;

        // Visited grid to track which cells have been processed
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Initialize the queue with all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) { // If the orange is already rotten
                    q.push({{i, j}, 0}); // Push its position and time (0) into the queue
                    vis[i][j] = 2; // Mark it as visited
                } else {
                    vis[i][j] = 0; // Mark other cells as unvisited
                }
            }
        }

        int tm = 0; // Variable to track the total time elapsed
        int drow[] = {-1, 0, +1, 0}; // Direction arrays for row movement (up, down, left, right)
        int dcol[] = {0, +1, 0, -1}; // Direction arrays for column movement

        // BFS loop
        while (!q.empty()) {
            int r = q.front().first.first; // Current row
            int c = q.front().first.second; // Current column
            int time = q.front().second; // Time elapsed for the current orange
            tm = max(tm, time); // Update the maximum time elapsed
            q.pop(); // Remove the processed element from the queue

            // Explore all 4-directionally adjacent cells
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i]; // New row
                int ncol = c + dcol[i]; // New column

                // Check if the new position is valid, contains a fresh orange, and hasn't been visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, time + 1}); // Add the new position to the queue with updated time
                    vis[nrow][ncol] = 2; // Mark the cell as visited (rotten)
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1; // If a fresh orange is found, return -1 (impossible to rot all oranges)
                }
            }
        }

        return tm; // Return the total time required to rot all oranges
    }
};
