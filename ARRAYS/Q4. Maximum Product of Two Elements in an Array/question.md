# Q4. Maximum Product of Two Elements in an Array

LeetCode: [Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)

Given the integer array `nums`, choose two distinct indices `i` and `j` such that `(nums[i] - 1) * (nums[j] - 1)` is maximized.

Return the maximum possible value of `(nums[i] - 1) * (nums[j] - 1)`.

## Sample Test Cases

- Input: `nums = [3,4,5,2]`
  Output: `12`
  Explanation: Choose `nums[2] = 5` and `nums[1] = 4`, so the product is `(5 - 1) * (4 - 1) = 12`.

- Input: `nums = [1,5,4,5]`
  Output: `16`
  Explanation: Choose the two `5`s, so the product is `(5 - 1) * (5 - 1) = 16`.

- Input: `nums = [3,7]`
  Output: `12`

## Constraints

- `2 <= nums.length <= 500`
- `1 <= nums[i] <= 10^3`

## NOTE
Provide a screenshot of the accepted solution on LeetCode, including the left pane in description of Pull request and push the solution.

