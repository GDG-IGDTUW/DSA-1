class Solution {
    public int dominantIndex(int[] nums) {
        int maxIndex = 0;
        for (int i=1;i<nums.length;i++) {
            if (nums[i]>nums[maxIndex]) {
                 //updating max variable
                maxIndex = i;
            }
        }

        //checking if max is greater than equal to twice the elements
        for (int i=0;i<nums.length;i++) {
            if (nums[maxIndex]<2*nums[i] && i!=maxIndex) {
                return -1;
            } 
        }
        return maxIndex;


        
    }
}
