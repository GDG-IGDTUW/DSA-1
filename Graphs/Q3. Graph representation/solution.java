import java.util.ArrayList;
import java.util.Scanner;

public class solution{
    public static ArrayList<ArrayList<Integer>> graphRepresentation(int V, int E, int[][] edges){
        ArrayList<ArrayList<Integer>> adjacencyList = new ArrayList<>();

        for(int i=0; i<V; i++){
            adjacencyList.add(new ArrayList<>());
        }

        for(int[] edge : edges){
            int i = edge[0];
            int j = edge[1];

            adjacencyList.get(i).add(j);
            adjacencyList.get(j).add(i);
        }

        return adjacencyList;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number of vertices and edges
        System.out.print("Enter the number of vertices: ");
        int V = sc.nextInt();

        System.out.print("Enter the number of edges: ");
        int E = sc.nextInt();

        // Input the edges
        int[][] edges = new int[E][2];
        System.out.println("Enter the edges (u v):");
        for (int i = 0; i < E; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
        }

        // Generate the adjacency list
        ArrayList<ArrayList<Integer>> adjacencyList = graphRepresentation(V, E, edges);

        // Print the adjacency list
        System.out.println("Adjacency List Representation:");
        for (int i = 0; i < V; i++) {
            System.out.print(i + ": ");
            for (int neighbor : adjacencyList.get(i)) {
                System.out.print(neighbor + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}