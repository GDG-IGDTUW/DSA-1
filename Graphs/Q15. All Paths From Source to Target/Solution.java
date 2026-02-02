class Solution {
    public void dfs(int node, List<Integer> currPath, List<List<Integer>> paths, int[][] adj, boolean vis[]){
        currPath.add(node);
        if(node == adj.length-1){ // we have reached the last node
            paths.add(new ArrayList<>(currPath));
            return;
        }

        vis[node] = true;
        for(int neighbour : adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour, currPath, paths, adj, vis);
                currPath.remove(currPath.size()-1);
            }
        }
        vis[node] = false; //backtrack
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] adj) {
        List<List<Integer>> paths = new ArrayList<>();
        boolean vis[] = new boolean[adj.length];
        List<Integer> currPath = new ArrayList<>();
        dfs(0, currPath, paths, adj, vis);
        return paths;
    }
}
