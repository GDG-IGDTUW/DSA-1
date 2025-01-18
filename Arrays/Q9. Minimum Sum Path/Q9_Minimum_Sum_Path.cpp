#include <iostream>
#include <vector>
using namespace std;

int MinSumPath(vector<vector<int>>& grid, int m, int n) {
    for (int i = 1; i < m; i++) {
        grid[i][0] += grid[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
        grid[0][j] += grid[0][j - 1];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the elements of the grid:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << "SUM = " << MinSumPath(grid, m, n) << endl;
    return 0;
}
