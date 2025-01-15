#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        // Mark the current city as visited
        visited[city] = true;
        
        // Explore all the neighboring cities
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();  // number of cities
        vector<bool> visited(n, false);  // to keep track of visited cities
        int provinces = 0;  // to count the number of provinces
        
        // Iterate through each city
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {  // If this city has not been visited
                dfs(i, isConnected, visited);  // Perform DFS to mark all connected cities
                provinces++;  // We found a new province
            }
        }
        
        return provinces;
    }
};
//Main Section
int main() {
    Solution solution;
    //Testing with example {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << "Number of Provinces: " << solution.findCircleNum(isConnected) << endl;
    return 0;
}
