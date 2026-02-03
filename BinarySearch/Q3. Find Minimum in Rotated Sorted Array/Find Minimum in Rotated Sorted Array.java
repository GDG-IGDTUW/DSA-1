class Solution {
    int function(int [] nums,int n){
        int low=0;
        int high=n-1;
        int ans=Integer.MAX_VALUE;
        while(low<=high){
            int mid=high+low/2;
            if(nums[low]<=nums[high]){
                ans=Math.min(ans,nums[low]);
                break;
            }
            
            if(nums[low]<=nums[mid]){
                ans=Math.min(ans,nums[low]);
                low=mid+1;
            }
            else{
              ans=Math.min(ans,nums[mid]);  
              high=mid-1;
            }
        }
    return ans;
    }
    public int findMin(int[] nums) {
        return function(nums,nums.length);
    }
}