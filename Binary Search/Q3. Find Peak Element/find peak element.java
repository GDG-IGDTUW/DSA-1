//100% testcases passed on leetcode
class Solution {
    public int findPeakElement(int[] nums) {
        int low=0;int high=nums.length-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid>0&&nums.length-1>mid&&nums[mid-1]<nums[mid]&&nums[mid+1]<nums[mid])
            return mid;
            else if(mid>=1&&mid==nums.length-1&&nums[mid]>nums[mid-1])
            return mid;
            else if(nums.length>=2&&mid==0&&nums[mid]>nums[mid+1])
            return mid;
            if(nums.length-1>mid&&nums[mid]<nums[mid+1])
            low=mid+1;
            else
            high=mid-1;
        }
        return 0;
    }
}
