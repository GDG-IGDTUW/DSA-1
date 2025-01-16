import java.util.Stack;
import java.util.ArrayList;
import java.util.Arrays;

public class solution{

    public static ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> adjacencyList){
        Stack<Integer> st = new Stack<>();
        boolean[] vis = new boolean[adjacencyList.size()];
        ArrayList<Integer> dfs = new ArrayList<>();

        st.push(0);

        while(!st.isEmpty()){
            int node = st.pop();
            
            if(vis[node]){
                continue;
            }

            vis[node] = true;
            dfs.add(node);

            for(int i=adjacencyList.get(node).size()-1; i>=0; i--){
                int neighbour = adjacencyList.get(node).get(i);

                if(!vis[neighbour]){
                    st.push(neighbour);
                }
            }
        }
        return dfs;
    }

    public static void main(String[] args) {
        // Create an adjacency list for the graph
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        adj.add(new ArrayList<>(Arrays.asList(2, 3, 1)));  // Neighbors of vertex 0
        adj.add(new ArrayList<>(Arrays.asList(0)));        // Neighbors of vertex 1
        adj.add(new ArrayList<>(Arrays.asList(0, 4)));     // Neighbors of vertex 2
        adj.add(new ArrayList<>(Arrays.asList(0)));        // Neighbors of vertex 3
        adj.add(new ArrayList<>(Arrays.asList(2)));        // Neighbors of vertex 4

        // Call DFS function
        ArrayList<Integer> result = dfs(adj);
        System.out.println(result); 
        
        // Output should be [0, 2, 4, 3, 1]
    }
}