//OPTIMAL SOLUTION:
//The problem asks for the K weakest rows in a matrix, where each row represents soldiers (1's) and civilians (0's).
//The rows should be ranked by their "weakness," which is determined by the number of soldiers (1's) in the row. If two rows have the same number of soldiers, 
//the row that appears earlier in the matrix is considered weaker.
//Time Complexity: O(m * n + m log m),  Space Complexity: O(m) for storing the pairs of soldier counts and row indices.

//CODE:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Helper function to count the number of soldiers (1's) in a row
int countSoldiers(const vector<int>& row) {
    return count(row.begin(), row.end(), 1); // Count the number of 1's in the row
}
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int>> rowStrengths; // Pair of (number of soldiers, row index)

    // Step 1: Count the soldiers in each row and store (soldier count, row index)
    for (int i = 0; i < mat.size(); ++i) {
        int soldierCount = countSoldiers(mat[i]);
        rowStrengths.push_back({soldierCount, i});
    }
    // Step 2: Sort the rows based on the number of soldiers, and row index in case of ties
    sort(rowStrengths.begin(), rowStrengths.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        // If the number of soldiers is the same, the row with the smaller index is weaker
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    // Step 3: Extract the indices of the K weakest rows
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(rowStrengths[i].second);
    }

    return result;
}

