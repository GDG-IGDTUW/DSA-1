class Solution {
public:
    bool isPeak(vector<int>& nums, int mid) {
        int n = nums.size();
        if (mid == 0)
            return nums[0] > nums[1];
        if (mid == n - 1)
            return nums[n-1] > nums[n - 2];
        return nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1];
    }
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                high = mid;      
        }
        return low;
    }
};