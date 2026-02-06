class Solution {
public:
    void heapify(vector<int>&arr, int n, int i){
        int largest=i;
        int left=(2*i)+1, right=(2*i)+2;

        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }

        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }

        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        
        }

    }
    vector<int> sortArray(vector<int>& nums) {
        int n= nums.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);

        }
        return nums;
        
    }
};
