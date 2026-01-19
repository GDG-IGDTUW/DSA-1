class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Bruteforce solution
        int n = nums.size();
        k = k % n;

        vector <int> tmp;
        int i = 0;
        for(int j = n-k; j < n; j++){
            tmp.push_back(nums[j]);
        }
        for(int i = 0; i < n-k; i++){
            tmp.push_back(nums[i]);
        }
        nums = tmp;
    }
};