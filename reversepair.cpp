class Solution {
public:
    void merge(vector<int>&nums,int start,int mid,int end){
        int left=start,right=mid+1;
        vector<int>temp;
        while(left<=mid && right<=end){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=end){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=start;i<=end;i++){
            nums[i]=temp[i-start];
        }
    }

    int countPairs(vector<int>&nums,int start,int mid,int end){
        int right=mid+1;
        int cnt=0;
        for(int i=start;i<=mid;i++){
            while(right<=end && (long long)nums[i]>2LL*nums[right]){
                right++;
            }
            cnt+=right-(mid+1);
        }
        return cnt;
    }
    int mergeSort(vector<int>&nums,int start,int end){
        int count=0;
        if(start>=end){
            return count;
        }
        int mid=start+(end-start)/2;
        count+=mergeSort(nums,start,mid);
        count+=mergeSort(nums,mid+1,end);
        count+=countPairs(nums,start,mid,end);
        merge(nums,start,mid,end);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
        
    }
};
