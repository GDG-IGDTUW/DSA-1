class Solution {
    public:
        int dominantIndex(vector<int>& nums) {
            int n=nums.size();
            int maxNum=0;
            int pos=0;
            for(int i=0;i<n;i++){
                if(nums[i]>maxNum){
                    maxNum=nums[i];
                    pos=i;
                }
            }
            for(int i=0;i<n;i++){
                if(nums[i]!=maxNum && maxNum<nums[i]*2){
                    return -1;
                }
            }
            return pos;
        }
    };