You are given a character array `tasks`, where each character represents a task, and an integer `n` representing the cooldown period.

Each task takes one unit of time to execute, and the same task must be separated by at least `n` units of time.

Return the least number of units of time needed to finish all tasks.

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2  
Output: 8  

Explanation:  
A -> B -> idle -> A -> B -> idle -> A -> B

Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0  
Output: 6  

Link to Problem:  
https://leetcode.com/problems/task-scheduler/

Provide a screenshot of the accepted solution on LeetCode, including the left pane in the description of Pull Request and push the solution.
