#include<bits/stdc++.h>
using namespace std;

/*
Logic:
    1) Create a hashmap to store the count of each element.
    2) Iterate through the array and store the count of each element in the hashmap.
    3) Iterate through the hashmap and return the element with count > n/2.
    4) Return -1 if no majority element is found.
    5) Time complexity: O(N).
*/

int majorityElement(vector<int> &nums){
    unordered_map<int,int> count;
    for(int n: nums){
        count[n] += 1;
    }
    for(auto p: count){
        if(p.second > nums.size()/2){
            return p.first;
        }
    }
    // Will never reach as majority element is always present
    return -1;    
}

int main(){
    int n;
    cout<<"Enter Number of Elements: ";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cout<<"Enter Element "<<i+1<<": ";
        cin>>nums[i];
    }
    cout<<"Majority Element: "<<majorityElement(nums)<<endl;
}