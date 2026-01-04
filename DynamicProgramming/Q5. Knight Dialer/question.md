# Question 5: Knight Dialer

## Problem Statement
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagram:

A chess knight can move as indicated in the chess diagram below:

<img width="402" height="402" alt="image" src="https://github.com/user-attachments/assets/1fab88f8-013e-4b98-8ff0-64365538b897" />

We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
<img width="242" height="322" alt="image" src="https://github.com/user-attachments/assets/cd33009d-50ce-43d9-8a67-41e5634bfb3c" />

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

Link to Problem:https://leetcode.com/problems/knight-dialer/description/


## Examples

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

## Guidelines 
Provide a screenshot of the accepted solution on Leetcode, including the left pane in the description of pull request and push the solution.
