There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Example :

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
<img width="584" height="257" alt="image" src="https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png" />


Link to Question : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

Provide a screenshot of the accepted solution on LeetCode, including the left pane in description of Pull request and push the solution. 
