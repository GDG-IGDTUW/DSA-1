class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] visited = new boolean[n];

        dfs(0, rooms, visited);

        // Check if all rooms are visited
        for (boolean v : visited) {
            if (!v) return false;
        }
        return true;
    }

    private void dfs(int room, List<List<Integer>> rooms, boolean[] visited) {
        if (visited[room]) return;

        visited[room] = true;

        for (int key : rooms.get(room)) {
            dfs(key, rooms, visited);
        }
    }
}
