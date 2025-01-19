class Solution {
private:
    // Depth First Search (DFS) helper function
    // This function traverses the graph and marks all connected nodes as visited
    void dfs(vector<vector<int>> &adjls, vector<int> &vis, int node) {
        vis[node] = 1; // Mark the current node as visited
        for (auto it : adjls[node]) { // Iterate through all adjacent nodes
            if (!vis[it]) { // If the adjacent node is not visited
                dfs(adjls, vis, it); // Recursively call DFS for the adjacent node
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Number of nodes (cities)
        int V = isConnected.size();

        // Create an adjacency list to represent the graph
        vector<vector<int>> adjls(V);

        // Convert the adjacency matrix into an adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) { // If there's a direct connection between i and j
                    adjls[i].push_back(j); // Add j to i's adjacency list
                    adjls[j].push_back(i); // Add i to j's adjacency list (for undirected graph)
                }
            }
        }

        // Initialize a visited array to keep track of visited nodes
        vector<int> vis(V, 0);

        int count = 0; // Count of connected components (provinces)

        // Iterate through all nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) { // If the node is not visited
                count++; // Increment the province count
                dfs(adjls, vis, i); // Perform DFS to mark all nodes in this province
            }
        }

        return count; // Return the total number of provinces
    }
};
