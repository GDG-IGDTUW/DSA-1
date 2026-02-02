Given a string s, reverse the order of words in the string.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Example :

Input: s = "the sky is blue"  
Output: "blue is sky the"

Link to question : https://leetcode.com/problems/reverse-words-in-a-string/

Provide a screenshot of the accepted solution on Leetcode, including the left pane in the description of pull request and push the solution.

#this code is in python
s.strip()
words = s.split()

return ' '.join(reversed(words))
