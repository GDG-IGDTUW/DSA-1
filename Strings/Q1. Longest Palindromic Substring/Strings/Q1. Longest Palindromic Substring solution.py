def longestPalindrome(s: str) -> str:
    if len(s) < 1:
        return ""
#using the brute force approach would increase the time complexicity so we expand around the centre of a index
    def expandAroundCenter(left: int, right: int) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1:right]

    longest = ""
    for i in range(len(s)):
        #if the length of the palindrome is odd
        odd_palindrome = expandAroundCenter(i, i) 
        if odd_palindrome and len(odd_palindrome) > len(longest):
            longest = odd_palindrome
        #if the length of the palindrome is even
        even_palindrome = expandAroundCenter(i, i + 1)
        if even_palindrome and len(even_palindrome) > len(longest):
            longest = even_palindrome

    return longest

s = "babad"
print(longestPalindrome(s))

s = "cbbd"
print(longestPalindrome(s))
