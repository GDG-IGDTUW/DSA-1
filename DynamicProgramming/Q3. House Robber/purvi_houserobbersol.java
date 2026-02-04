class Solution {
    public int rob(int[] nums) {
    int n =nums.length;
    
    int prev=nums[0];
    int prev2=0;
    
    for(int i =1;i<nums.length;i++){
    
        int pick=nums[i];
        if(i>1)pick+=prev2;
        int notpick=prev;

        int curr=Math.max(pick,notpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
    }
}