# Q3. Move Zeroes

LeetCode: [Move Zeroes](https://leetcode.com/problems/move-zeroes/)

Given an integer array `nums`, move all `0`s to the end of the array while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

## Sample Test Cases

- Input: `nums = [0,1,0,3,12]`
  Output: `[1,3,12,0,0]`

- Input: `nums = [0]`
  Output: `[0]`

## Constraints

- `1 <= nums.length <= 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`

## NOTE
Provide a screenshot of the accepted solution on LeetCode, including the left pane in description of Pull request and push the solution.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int counter = 0;  
        int t;

        for (int i = 0; i < size - 1; i++) 
        {
            for (int j = 0; j < size - 1; j++) 
         {
                if (nums[j] == 0) 
                {
                    t = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = t;
                }     
            }
     }
   }
};

