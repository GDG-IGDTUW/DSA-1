#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<vector<int>> &adj) {
    vector<int> bfs;         // Stores BFS traversal result
    vector<bool> visited(V, false); // Track visited nodes
    queue<int> q;            // Queue for BFS
    
    // Start BFS from node 0
    q.push(0);
    visited[0] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        // Traverse neighbors in the given order
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return bfs;
}

int main() {
    vector<vector<int>> adj1 = {{2,3,1}, {0}, {0,4}, {0}, {2}};
    vector<vector<int>> adj2 = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    
    vector<int> result1 = bfsOfGraph(5, adj1);
    vector<int> result2 = bfsOfGraph(5, adj2);

    // Print BFS traversal results
    for (int node : result1) cout << node << " ";
    cout << endl;

    for (int node : result2) cout << node << " ";
    cout << endl;

    return 0;
}
