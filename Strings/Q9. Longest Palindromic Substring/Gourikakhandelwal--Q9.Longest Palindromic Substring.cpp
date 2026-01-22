#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to find the longest palindromic substring in a given string
    string longestPalindrome(string s) {
        int start = 0, end = 0; // Track boundaries of the longest palindrome found

        // Iterate through each character, treating it as a potential center
        for (int center = 0; center < s.length(); center++) {
            // Case 1: Odd-length palindrome (centered at a single character)
            int lenOdd = expandFromCenter(s, center, center);

            // Case 2: Even-length palindrome (centered between two characters)
            int lenEven = expandFromCenter(s, center, center + 1);

            // Take the maximum length palindrome from both cases
            int maxLen = max(lenOdd, lenEven);

            // Update the longest palindrome boundaries if a longer one is found
            // Formula explanation:
            // - (maxLen - 1) / 2 → how far palindrome extends to the left of center
            // - Subtracting it from center gives the starting index.
            
            // - maxLen / 2       → how far palindrome extends to the right of center
            //- Adding it to center gives the ending index.

            if (maxLen > end - start) {
                start = center - (maxLen - 1) / 2;
                end   = center + maxLen / 2;
            }
        }

        // Extract and return the longest palindromic substring
        return s.substr(start, end - start + 1);
    }

private:
    // Helper function: expand around the given center (left, right)
    // Returns the length of the palindrome found
    int expandFromCenter(const string& str, int left, int right) {
        // Expand outward while characters match and indices are within bounds
        while (left >= 0 && right < str.length() && str[left] == str[right]) {
            left--;
            right++;
        }
        // Length = right - left - 1 because both ends overshoot by one step
        return right - left - 1;
    }
};