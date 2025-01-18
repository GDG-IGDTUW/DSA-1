from collections import defaultdict

class Solution:
    def countSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        left = 0
        count = 0
        char_count = defaultdict(int)

        for right in range(n):
            # Add the current character to the window
            char_count[s[right]] += 1

            # If the window has more than k distinct characters, shrink from the left
            while len(char_count) > k:
                char_count[s[left]] -= 1
                if char_count[s[left]] == 0:
                    del char_count[s[left]]
                left += 1

            # All substrings from left to right have at most k distinct characters
            count += (right - left + 1)

        return count

    def exactlyKdistinct(self, s: str, k: int) -> int:
        return self.countSubstrings(s, k) - self.countSubstrings(s, k - 1)


sol = Solution()
s = "aba"
k = 2
print(sol.exactlyKdistinct(s, k))  

s = "abaaca"
k = 1
print(sol.exactlyKdistinct(s, k)) 
s = "cdad"
k = 4
print(sol.exactlyKdistinct(s, k))
