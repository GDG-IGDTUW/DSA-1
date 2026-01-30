class Solution {
    public int findNumbers(int[] nums) {
        int count=0;
        for (int i=0;i<nums.length;i++){
            if(Even(nums[i])){
                count++; //increasing count if Even function returns true
            }
        }
        return count;
        
    }
    public static boolean Even(int num) {
            String str= Integer.toString(num); //converting integer to string
           
                return Integer.toString(num).length() % 2 == 0; //checking if string has even length
                
            }
}
