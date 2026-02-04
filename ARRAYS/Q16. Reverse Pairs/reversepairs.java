class Solution {
    void  merge(int []nums,int low,int mid,int high){
        int count=0;
        int left=low;
        int i=0;
        int right=mid+1;
        int []temp=new int[high-low+1];
        
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp[i]=nums[left];
                left++;
            }
            else if(nums[left]>nums[right]){
                temp[i]=nums[right];
                right++;
                
            }
            i++;
        }
        while(left<=mid){
            temp[i]=nums[left];
            left++;
            i++;
        }
        while(right<=high){
            temp[i]=nums[right];
            right++;
            i++;
        }
        for(int j=low;j<=high;j++){
            nums[j]=temp[j-low];
        }


        
    }
    int countPairs(int nums[],int low,int mid,int high){
        int count=0;
        int right=mid+1;
        for(int j =low;j<=mid;j++){
            
            while(right<=high && (long)nums[j]>2L*nums[right]){
                right++;
            }
            count+=right-(mid+1);
        }
        return count;
    }
    int  mergeSort(int [] nums, int low,int high){
        int mid=low+(high-low)/2;
        int count =0;
        if(low>=high) return count;
        count+=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);
        count+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return count;
    }
    public int reversePairs(int[] nums) {
     
        return mergeSort(nums,0,nums.length-1);
    }
}