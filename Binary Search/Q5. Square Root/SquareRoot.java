//100% testcases passed on leetcode
class Solution {
    public int mySqrt(int x) {
        if(x<2)
        return x;
        int left=1; int right=x/2;
        int ans=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            long square=(long)mid*mid;
            if(square==x)
            return mid;
            else if(square<x){
            left = mid+1;
            ans=mid;

            }
            else
            {right=mid-1;}
        }
        return ans;
    }
}
