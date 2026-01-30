class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int res = 0;
        
        // Stores the last seen index of each character
        vector<int> lastIndex(128, -1); 
        int start = 0; // The starting index of the current window

        for (int end = 0; end < n; end++) {
            // Jump the start of the window to the position after the last
            // occurrence of the current character.
            start = max(start, lastIndex[s[end]] + 1);

            // Update the result with the length of the current window
            res = max(res, end - start + 1);

            // Update the last index of the current character
            lastIndex[s[end]] = end;
        }
        return res;
    }
};
