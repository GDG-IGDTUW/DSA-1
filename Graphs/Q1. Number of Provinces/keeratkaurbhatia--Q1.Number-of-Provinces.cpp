//TC = O(n^2) : scanning the entire adjacency matrix of nxn entries
//SC = O(n) : visited array maintains status for n nodes, also recursive stack in the worst case can go to n depth

/*
Approach:
no. of provinces correspond to the no. of components.
to find the no. of components, we have to find the no. of traversals required to cover the entire graph. 
so that in each single traversal, the relevant connected nodes are covered before exploring the other component.
*/


class Solution {
public:
    //for graph traversal
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjMat) 
    {
        visited[node] = 1; //node is now marked visited
        for (int j = 0; j < adjMat.size(); j++) 
        {
            //for the remaining nodes which are valid neighbours and not visited
            if (j != node && 
            adjMat[node][j] == 1 && 
            !visited[j]) 
            {
                dfs(j, visited, adjMat); //recursively traverse
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0); 
        int count = 0; //initially no component count

        //for all the nodes
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i]) //if unvisted
            {
                count++; //marks the start of another component
                dfs(i, visited, isConnected); //visit all of its neighbours before moving further
            }
        }

        return count; //total no. of components = provinces
    }
};
