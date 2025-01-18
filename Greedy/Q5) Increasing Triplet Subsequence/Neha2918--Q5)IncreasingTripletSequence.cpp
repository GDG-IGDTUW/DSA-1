class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums) {
            if (num > second) {
                // If we find a number greater than `second`, we found the triplet
                return true;
            } else if (num > first && num < second) {
                // Update `second` if the current number is greater than `first` but smaller than `second`
                second = num;
            } else if (num < first) {
                // Update `first` if the current number is smaller
                first = num;
            }
        }
        return false;
    }
};
