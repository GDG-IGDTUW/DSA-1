#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    //function which returns the dfs traversal of the graph
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        //number of nodes in graph
        int n = adj.size();
        
        //using an array to keep the track of visisted nodes
        int vis[n] = {0};
        
        // vectory to resturn the dfs traversal
        vector<int> ls;
        dfs(ls, 0, vis, adj); //helper function 
        
        
        return ls; //final traversal list
    }
    
  private:
    
    void dfs(vector<int>& ls, int node, int vis[], vector<vector<int>>& adj) {
        // marking the current node as visited
        vis[node] = 1;
        
        //adding to the result
        ls.push_back(node);
        
        //traversing the neighbors 
        for (auto it : adj[node]) {
            // if neighbor is not visited,performing the dfs on it
            if (!vis[it]) {
                dfs(ls, it, vis, adj);
            }
        }
    }
};

int main() {
    
    vector<vector<int>> adj = {
        {1, 2},      // Node 0 is connected to nodes 1 and 2
        {0, 3, 4},   // Node 1 is connected to nodes 0, 3, and 4
        {0, 4},      // Node 2 is connected to nodes 0 and 4
        {1},         // Node 3 is connected to node 1
        {1, 2}       // Node 4 is connected to nodes 1 and 2
    };
    
    // object of Solution class
    Solution obj;
    
    // dfs traversal of the graph
    vector<int> result = obj.dfsOfGraph(adj);
    
    // printing the dfs traversal
    for (int node : result) {
        cout << node << " ";
    }
    
    return 0;
}
