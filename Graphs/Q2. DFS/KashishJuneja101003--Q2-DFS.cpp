#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    // Mark the node as visited
    visited[node] = true;
    cout << node << " ";

    // Visit all adjacent nodes
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int V = 5;  // Number of vertices
    vector<int> adj[V];

    // Adding edges (Undirected Graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> visited(V, false);
    
    cout << "DFS Traversal: ";
    dfs(0, adj, visited);  // Start DFS from node 0

    return 0;
}
