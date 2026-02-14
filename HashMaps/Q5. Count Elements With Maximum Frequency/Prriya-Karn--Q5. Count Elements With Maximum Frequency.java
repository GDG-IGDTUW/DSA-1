class Solution {
    public int maxFrequencyElements(int[] nums) {

        int[] hash = new int[101];
        int max = 0;
        int count = 0;

        
        for (int i = 0; i < nums.length; i++) {
            hash[nums[i]]++;
        }

         for (int i = 0; i < hash.length; i++) {

            if (hash[i] > max) {
                max = hash[i];
                count = max;

            } else if (hash[i] == max) {
                count = count + max;
            }
        }

        return count;
    }
}
