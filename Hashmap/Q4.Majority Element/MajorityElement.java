class Solution {
    public int majorityElement(int[] nums) {
        int c=0;int number1=nums[0];int i=0;int number2=0; 
        while(c<=nums.length/2)
        {
            if(i<nums.length&&nums[i]==number1)
            {
                c++;i++;
            }
            else if(i<nums.length&&nums[i]!=number1&&number1==nums[number2])
            {
                number2=i;
            }
            else if(i<nums.length){
                i++;}
                else{
                    i=number2;
                    number1=nums[number2];c=0;
                }        }
         return number1;
    }
}
