class Solution {
    public void moveZeroes(int[] nums) {
        int a=-1;
        for (int i=0;i<nums.length;i++){
            if(nums[i]==0){
                a=i;
                break;
            }
        }
        if (a!=-1){
            for (int i=a+1;i<nums.length;i++){
                if(nums[i]!=0){
                    nums[a]=nums[i];
                    nums[i]=0;
                    a+=1;
                }
            }
        }
    }
}
