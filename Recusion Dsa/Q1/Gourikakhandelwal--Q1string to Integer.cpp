#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Recursive helper function to build the number digit by digit
    long long func(string s, int i, int n, long long res, int sign) {
        // Base case: stop if index exceeds bounds or current char is not a digit
        if (i > n || !isdigit(s[i])) {
            return sign * res; // Apply sign and return the result
        }

        // Accumulate the digit into the result
        res = 10 * res + (s[i] - '0');

        // Clamp to INT_MAX or INT_MIN if overflow is detected
        if (sign * res > INT_MAX) return INT_MAX;
        if (sign * res < INT_MIN) return INT_MIN;

        // Recurse to the next character
        return func(s, i + 1, n, res, sign);
    }

    int myAtoi(string s) {
        int n = s.size();     // Length of input string
        int ind = 0;          // Index to traverse the string
        int sign = 1;         // Default sign is positive

        // Skip leading whitespaces
        while (ind < n && s[ind] == ' ') ind++;

        // Check for optional '+' or '-' sign
        if (ind < n && (s[ind] == '+' || s[ind] == '-')) {
            if (s[ind] == '-') sign = -1; // Update sign if negative
            ind++;
        }

        // Call recursive function to parse digits and apply sign
        int final = func(s, ind, n - 1, 0, sign);

        // Return the final result as int (already clamped if needed)
        return final;
    }
};