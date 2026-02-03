class Solution {
    public int maxProduct(int[] nums) {
      int ans=Integer.MIN_VALUE;
      int prefix=1;
      int suffix=1;
      int n=nums.length;
      for(int i=0;i<nums.length;i++){
        if(suffix==0) suffix=1;
        if(prefix==0) prefix=1;
        prefix*=nums[i];
        suffix*=nums[n-i-1];
        ans=Math.max(ans,Math.max(prefix,suffix));
      }
       
    return ans;  
    }
}