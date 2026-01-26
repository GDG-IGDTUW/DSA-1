class Solution {
bool dfs(int src,int dest,vector<vector<int>> &adj,vector<bool> &visited){
if (src == dest) return true;

        visited[src] = true;

        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, dest, adj, visited)) return true;
            }
        }

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(source,destination,adj,visited);
    }   
};
