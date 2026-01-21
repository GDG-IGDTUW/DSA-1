class Solution {
    public boolean canJump(int[] nums) {
       int maxReach = 0;
       
       for (int i=0;i<nums.length;i++) {
         if (i<=maxReach) { //checking if current index can be reached or not
            maxReach = Math.max(maxReach,i+nums[i]); //proceeding further how far can we reach from here
         }
         else {
            return false; //cant reach the last index if we cant reach current one only
         }
         
       }
       return true;
        
    }
}
