#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
  public:
     //function for the adjacency list of each node .
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(V); //initialising the adj list with v vertices

        //populating the list based on given edges
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;  
            int v = edges[i].second; 
            
            adj[u].push_back(v);    // add v to the adjacency list of u
            adj[v].push_back(u);    // Add u to the adjacency list of v 
        }
        
        return adj; // return the adjacency list
    }
};

int main() {
    // number of vertices in the graph
    int V = 5;

    // list of edges where each pair represents an edge between two vertices
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}
    };

    // object of the Solution class
    Solution obj;

    //adjacency list of the graph
    vector<vector<int>> adjList = obj.printGraph(V, edges);

    // printing  the adjacency list
    cout << "Adjacency List of the Graph:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
