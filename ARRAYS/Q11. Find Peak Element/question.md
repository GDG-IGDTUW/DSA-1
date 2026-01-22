# Q11. Find Peak Element

LeetCode: [Find Peak Element](https://leetcode.com/problems/find-peak-element/)

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array `nums`, find a peak element and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that `nums[-1] = nums[n] = -∞`. You must write an algorithm that runs in `O(log n)` time.

## Sample Test Cases

- Input: `nums = [1,2,3,1]`
  Output: `2`
  Explanation: `nums[2] = 3` is a peak element and the function should return the index `2`.

- Input: `nums = [1,2,1,3,5,6,4]`
  Output: `5`
  Explanation: The function can return either index `1` (peak element `2`) or index `5` (peak element `6`).

## Constraints

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `nums[i] != nums[i + 1]` for all valid `i`

## NOTE
Provide a screenshot of the accepted solution on LeetCode, including the left pane in description of Pull request and push the solution.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size=nums.size();
        if(size==1)
        {
            return 0;
        }
        if(nums[1]<nums[0])
        {
            return 0; 
        }
        if(nums[size-2]<nums[size-1])
        {
            return (size-1); 
        }
        for(int i=1;i<=(size-2);i++)
        {
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1])
            {
                return i;
            }
        }
        return -1;
    }
};

