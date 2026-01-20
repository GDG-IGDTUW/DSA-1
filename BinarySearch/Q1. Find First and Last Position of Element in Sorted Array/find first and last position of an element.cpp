class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size(),st=0,end=n-1,mid=st+(end-st)/2;
        vector<int> ans;
        while(st<=end){
            mid=st+(end-st)/2;
            if(nums[mid]<target)st=mid+1;
            else if(nums[mid]>target)end=mid-1;
            else{
                while(nums[end]!=target)end--;
                while(nums[st]!=target)st++;
                ans.push_back(st);
                ans.push_back(end);
                return ans;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};