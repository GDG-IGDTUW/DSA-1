class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room] = true;
        for (int key : rooms[room]) {
            if (!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);  // initially, no room is visited

        dfs(0, rooms, visited);  // start DFS from room 0

        // check if all rooms are visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};
