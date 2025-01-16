//First Approach
class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int[]result = new int[nums.length];
        int[]prefix = new int[nums.length];
        prefix[nums.length-1] = nums[0];
        for(int i = nums.length-2; i>=0; i--){
            prefix[i] = prefix[i+1]^nums[nums.length-i-1];
        }
        for(int j = 0; j<nums.length; j++){
            int x = (int)Math.pow(2, maximumBit)-1;
            result[j] = prefix[j]^x;
        }
        return result;
    }
}
//Better approach
class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int n = nums.length;
        int[] result = new int[n];
        int xor = 0;
        for (int x: nums) {
            xor ^= x;
        }
        int maxK = (1 << maximumBit) - 1; //(1<<maximumBit) basically calculates 2^maximumBit. This expression gives the maximum possible value of k.
        for (int i = 0; i < n; i++) {
            result[i] = xor ^ maxK;  //Calculate the result[i] by calculating the xor of maxK with the current xor
            xor ^= nums[n - i - 1]; //Removing the current last element from the xor because xor of the same elements eliminate each other.
        }
        return result;
    }
}
