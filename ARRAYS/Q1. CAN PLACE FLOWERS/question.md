# Q1. Can Place Flowers

LeetCode: [Can Place Flowers](https://leetcode.com/problems/can-place-flowers/)

Suppose you have a long flowerbed in which some of the plots are planted, and some are not. However, no two flowers can be planted in adjacent plots.

Given an integer array `flowerbed` containing `0`s and `1`s, where `0` means empty and `1` means not empty, and an integer `n`, return `true` if `n` new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and `false` otherwise.

## Sample Test Cases

- Input: `flowerbed = [1,0,0,0,1]`, `n = 1`
  Output: `true`

- Input: `flowerbed = [1,0,0,0,1]`, `n = 2`
  Output: `false`

## Constraints

- `1 <= flowerbed.length <= 2 * 10^4`
- `flowerbed[i]` is `0` or `1`
- No two adjacent flowers are planted in `flowerbed`

- `0 <= n <= flowerbed.length`

## NOTE
Provide a screenshot of the accepted solution on LeetCode, including the left pane in description of Pull request and push the solution.

## solution in cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        int start = 1;
        int end = size - 2;

        if (size == 1) {
            if (flowerbed[0] == 0)
             {
                flowerbed[0]=1;
                n--;
             }
            if(n<=0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if(flowerbed[0]==0 && flowerbed[1]==0)
            {
              flowerbed[0]=1;  
              n--;
              start = 2; 
            }
        if(flowerbed[size-1]==0 && flowerbed[size-2]==0)
            {
              flowerbed[size-1]=1;  
              n--;
              end = size - 3;
            }
        
        for(int i=start;i<=end;i++)
        {
            
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0)
            {
                flowerbed[i]=1;
                n--;
            }
         }
         if(n<=0)
         {
            return true;
         }
         else
         {
            return false;
         }

        
    }
};


