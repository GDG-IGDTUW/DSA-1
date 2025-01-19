#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    //function for the bfs traversal of the graph
    vector<int> bfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();          //no of nides
        int vis[n] = {0};            //array to keep track of visisted nodes
        vis[0] = 1;                  

        queue<int> q;                //using the queue for the bfs traversal
        q.push(0);                  //starting from the node 0

        vector<int> bfs;             //vector used to store the bfs traversal

        while (!q.empty()) {
            int node = q.front();    //get the front element from the queue
            q.pop();                 // remove it from the queue

            bfs.push_back(node);     // add the curr node to bfs result

            // traversing all the neighbors of the current node
            for (auto it : adj[node]) {
                if (!vis[it]) {      // if neighbor is not visited
                    vis[it] = 1;     // mark it as visited
                    q.push(it);      // push in the queue
                }
            }
        }

        return bfs;                  // returning the result in form of vector
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

    //object of Solution class
    Solution obj;

    // calling the bfs function 
    vector<int> result = obj.bfsOfGraph(adj);

    //printing the bfs traversal
    cout << "BFS Traversal of the graph: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
