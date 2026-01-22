class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long max_prod = nums[0];
        long long min_prod = nums[0];
        long long ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(max_prod, min_prod);
            }
            max_prod = max((long long)nums[i], max_prod * nums[i]);
            min_prod = min((long long)nums[i], min_prod * nums[i]);
            ans = max(ans, max_prod);
        }
        return ans;
    }
};
