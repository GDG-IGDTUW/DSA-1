class Solution {
public:
    int knapsack(vector<int> wt, vector<int> val, int n, int W) {
        // Initialize a 1D DP array with size W+1 to store maximum value at each weight capacity
        vector<int> prev(W + 1, 0);

        // Base case: If the first item's weight is less than or equal to the weight capacity,
        // we can include it and assign its value
        for (int weight = wt[0]; weight <= W; weight++) {
            prev[weight] = val[0];
        }

        // Iterate over all items starting from the second one (index 1)
        for (int ind = 1; ind < n; ind++) {
            // Traverse the weight capacity in reverse to avoid overwriting during computation
            for (int weight = W; weight >= 0; weight--) {
                int notTake = 0 + prev[weight]; // Option: Don't take the current item
                int take = INT_MIN; // Initialize the take option to a very low value

                // Check if the current item's weight is less than or equal to the current capacity
                if (wt[ind] <= weight) {
                    // Option: Take the current item and add its value to the remaining capacity
                    take = val[ind] + prev[weight - wt[ind]];
                }

                // Store the maximum of taking or not taking the current item
                prev[weight] = max(notTake, take);
            }
        }

        // Return the maximum value obtainable at the given weight capacity
        return prev[W];
    }
};
