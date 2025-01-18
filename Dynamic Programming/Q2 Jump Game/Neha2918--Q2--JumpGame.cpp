class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // maxReachable is the maximum index of the array that can be reached
        int maxReachable = 0;

        // Iterating over each index of array to calculate maxReachable
        for(int i = 0; i<n; i++){
            if(i>maxReachable)
                return false;

            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};