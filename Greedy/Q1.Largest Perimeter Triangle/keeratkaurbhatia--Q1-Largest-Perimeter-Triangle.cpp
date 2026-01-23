//TC : O(n log n) due to sorting
//SC : O(1) as the sorting is in-place

/*
Approach:
1. sort the array in ascending order
2. traverse from the largest elements backward and consider triplets (a,b,c), where a<=b<=c
3. a triangle is valid if we satisfy a + b > c, as the remaining inequalities already satisfy (c+b>a, c+a>b as c>=a, and c>=b)
4. the first valid triplet found like this gives the max possible perimeter
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
      //sorting  
      sort(nums.begin(), nums.end());

        //backward scan
        for (int i = nums.size() - 1; i >= 2; i--) 
        {
          //a+b>c check
          if (nums[i-2] + nums[i-1] > nums[i]) {
                return nums[i-2] + nums[i-1] + nums[i]; //return sum of all sides (perimeter)
            }
        }
        return 0; //if no such triplet found, no triangle possible
    }
};
