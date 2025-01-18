class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0; // Initialize the count of valid triangles
        int n = nums.size();

        // Step 1: Sort the array to make the triangle condition easier to check
        sort(nums.begin(), nums.end());

        // Step 2: Iterate from the largest element as the largest side of the triangle
        for (int i = n - 1; i >= 2; i--) {
            int low = 0;            // Pointer for the smallest side
            int high = i - 1;       // Pointer for the middle side

            // Step 3: Use a two-pointer approach to check triangle condition
            while (low < high) {
                if (nums[low] + nums[high] > nums[i]) {
                    // If the sum of nums[low] and nums[high] is greater than nums[i],
                    // all pairs between low and high can form a triangle
                    ans += (high - low);
                    high--; // Move the high pointer to check other pairs
                } else {
                    // Otherwise, increment the low pointer
                    low++;
                }
            }
        }

        return ans; // Return the total count of valid triangles
    }
};
