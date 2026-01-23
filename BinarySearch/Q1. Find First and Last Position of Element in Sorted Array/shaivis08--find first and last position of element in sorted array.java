class Solution {
    public int[] searchRange(int[] nums, int target) {
          int first = binarySearch(nums, target, true);
          int last  = binarySearch(nums, target, false);
          return new int[] {first, last};
    }
    public int binarySearch(int[] nums,int target, boolean findFirst) {
          int start=0;
          int end=nums.length-1;
          int mid=0;
          int ans=-1;
          while(start<=end) {
            mid=start+(end-start)/2;
            if (nums[mid]==target) {
                ans=mid;
                if(findFirst)
                end=mid-1;
                else
                start=mid+1;

            } else if(nums[mid]>target) {
                end=mid-1;
            } else
            start=mid+1;
          } 
          return ans;
    }
}
