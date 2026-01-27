#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Find function with path compression
    // It returns the root of the set that x belongs to
    int find(int x, vector<int> &parent) {
        if (parent[x] != x) {
            // Path compression: make x directly point to its root
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    // If they are in different sets, merge them into one set.
    // Union function with union by rank
    // It merges the sets containing x and y
    void unite(int x, int y, vector<int> &parent, vector<int> &rank) {
        int px = find(x, parent); // Find root of x
        int py = find(y, parent); // Find root of y

        if (px == py) return; // Already in the same set

        // Attach smaller rank tree under larger rank tree
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            // If ranks are equal, choose one as root and increase its rank
            parent[py] = px;
            rank[px]++;
        }
    }

    // Main function to determine minimum operations to connect all computers
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();

        // Rule: To connect n computers, we need at least (n - 1) cables.
        // If we have fewer, it's impossible → return -1.
        if (m < n - 1) return -1;

        // Initialize parent and rank arrays
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }
        vector<int> rank(n, 1); // Initial rank (or size) of each set is 1

        // Apply union operation for each connection
        for (auto &it : connections) {
            int i = it[0];
            int j = it[1];
            unite(i, j, parent, rank); // connect computers i and j

        }

        // Count number of connected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            // If i is its own root, it's a separate component
            if (find(i, parent) == i) components++;
        }

        // To connect all components into one network, we need (components - 1) operations
        return components - 1;
    }
};