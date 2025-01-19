class Solution {
    public int search(int[] nums, int target) {

        int pivot=-1;int search=-2;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i]>nums[i+1])
            pivot=i+1;
        }
        if(pivot==-1)
        pivot=nums.length-1;
        int low=0;int high=pivot;int mid=0;
        while(low<=high)
        {
         mid=(low+high)/2;
         if(nums[mid]==target)
         {search=mid;break;}
         if(nums[mid]>target)
         high=mid-1;
         else 
         low=mid+1;
        }
        low=pivot;
        high=nums.length-1;
        while(low<=high)
        {
         mid=(low+high)/2;
         if(nums[mid]==target)
         {search=mid;break;}
         if(nums[mid]>target)
         high=mid-1;
         else 
         low=mid+1;
        }
        if(search>=0)
        return search;
        else return -1;
    }
}

