//Is Graph Bipartite

//TC = O(V+E) : Each node visited once, each edge visited twice (undirected)
//SC = O(V) : color array for all the nodes, and dfs recursion stack in worst case, both result in O(V)

/*
Intuition:
    a graph is bipartite if the chromatic number is 2,
    i.e., the minimum number of colors required to color the nodes
    such that no two adjacent nodes have the same color.
    so a graph coloring problem!
*/


/*
Approach:
    graph traversal. initially no node is colored -> assigning it -1.
    2 choices of colors -> 0,1.
    at the starting point we can assume an arbitary color, let's take it to be 0
    assign the opposite color to all adjacent nodes.
    if an adjacent node already has the same color -> no need to look further, and return from the function.
    if dfs succeeds for all components, the graph is bipartite.
*/

class Solution {
public:
    
    //helper function for traversal : dfs
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& colors)
    {
        //for the node's neighbours
        for(int j = 0; j<graph[node].size(); j++) 
        {
            if (colors[graph[node][j]]==-1) //if uncolored
            {
                //assign color. if node is 0, adjacent neighbour becomes 1 and vice versa
                colors[graph[node][j]]=1-colors[node]; 

                //if exploring the neighbours' adjacent nodes, if bipartite condition fails, it's not bipartite
                if(!dfs(graph[node][j],graph,colors))
                return false;
            }
            
            //if the same color found adjacent, graph is not bipartite
            else if (colors[graph[node][j]]==colors[node])
            {
                return false;
            }
        }
        return true;

    }
    
    //given function to complete
    bool isBipartite(vector<vector<int>>& graph) {
        
        //to store the colors, initially all uncolored
        vector<int> colors (graph.size(),-1);
    
        //traversals at each nodes, to cover all the components
        for (int i = 0; i < graph.size(); i++)
        {
            if (colors[i] == -1) //if not colored
            {
                colors[i] = 0; //starting arbitarily with 0
                if (!dfs(i, graph, colors)) //if bipartite condition fails
                    return false; //not bipartite
            }
        }
        return true; //passes through all the hurdles. conclusion -> bipartite
    }
};
