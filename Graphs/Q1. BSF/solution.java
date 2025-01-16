import java.util.*;

public class solution {

    public static ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adjacencyList){
        Queue<Integer> q = new LinkedList<>();
        boolean[] vis = new boolean[adjacencyList.size()];
        ArrayList<Integer> bfs = new ArrayList<>();

        q.add(0);
        vis[0] = true;

        while(!q.isEmpty()){
            int node = q.remove();
            bfs.add(node);

            for(int i=0; i<adjacencyList.get(node).size(); i++){
                int neighbour = adjacencyList.get(node).get(i);
                if(!vis[neighbour]){
                    vis[neighbour] = true;
                    q.add(neighbour);
                }
            }
        }
        return bfs;
    }

    public static void main(String[] args) {
        // Input graph represented as an adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        
        // Example 1: Graph [[2, 3, 1], [0], [0, 4], [0], [2]]
        adj.add(new ArrayList<>(Arrays.asList(2, 3, 1))); // 0's neighbors
        adj.add(new ArrayList<>(Arrays.asList(0)));       // 1's neighbors
        adj.add(new ArrayList<>(Arrays.asList(0, 4)));    // 2's neighbors
        adj.add(new ArrayList<>(Arrays.asList(0)));       // 3's neighbors
        adj.add(new ArrayList<>(Arrays.asList(2)));       // 4's neighbors

        // Get BFS traversal starting from node 0
        ArrayList<Integer> bfsResult = bfs(adj);

        // Output the result of BFS traversal
        System.out.println("BFS Traversal: " + bfsResult);  // Expected Output: [0, 2, 3, 1, 4]
    }
}