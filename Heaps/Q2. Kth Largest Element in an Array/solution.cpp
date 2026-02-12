class Solution {
public://i've listed my approach in comments
    int findKthLargest(vector<int>& nums, int k) {
    //approach1:
       //sorting:
    /*
       sort(begin(nums),end(nums),greater<int>()); //tc=nlogn
       return nums[k-1];
    */
    //approach 2:using priority queue (heap implementation)
    priority_queue<int,vector<int>,greater<int>>pq;//minimum heap
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();

     
    }
};
