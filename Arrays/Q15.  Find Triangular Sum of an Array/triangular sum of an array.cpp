class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // Base case: if the array has only one element, return it
        if (nums.size() == 1) {
            return nums[0];
        }

        // Create a new array 
        vector<int> newNums(nums.size() - 1);

        // Populate the new array
        for (int i = 0; i < nums.size() - 1; ++i) {
            newNums[i] = (nums[i] + nums[i + 1]) % 10;
        }

        // find the triangular sum of the new array
        return triangularSum(newNums);
    }
};
