class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j = 0; //track zeroes
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                j++;
            }
        }
    }
};