// TC: O(log n) as exponent is reduced by half at every step
// SC: O(1) as constant extra space

/*
Approach:
1. instead of multiplying x by itself n times, we use binary exponentiation.
2. we repeatedly break the exponent into:
    an odd part (when n is odd, one extra x is needed)
    an even part (which can be handled by squaring x)
3. if n is negative, we convert the problem to (1/x)^|n|.
*/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (n < 0) //if n is negative. problem can be framed as 1/x ^ |n|
        {
            x = 1 / x;
        } 
        while (n != 0) // until all the bits are processed
        {
            if ((n%2) != 0) // if exponent is odd
            {
                ans *= x; //include in answer
            }
            x *= x; // squaring base
            n = n/2; // halving the exponent
        }
        return ans;
    }
};
