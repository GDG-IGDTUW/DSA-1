There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Example :

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
<img width="240" height="192" alt="image" src="https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg" />


Link to Question : https://leetcode.com/problems/number-of-provinces/description/

Provide a screenshot of the accepted solution on LeetCode, including the left pane in description of Pull request and push the solution. 
