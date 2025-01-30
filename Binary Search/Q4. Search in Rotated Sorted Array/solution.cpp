#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            // left sorted
            if(nums[low]<=nums[mid]){
                if (nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else low=mid+1;
            }

            //right sorted
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = search(nums, target);
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}