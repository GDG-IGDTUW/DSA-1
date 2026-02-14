class Solution(object):
    def minCostClimbingStairs(self, cost):
        n=len(cost)

        prev2=cost[0]
        if n==1:
            return prev2
        prev1=cost[1]
        
        for i in range(2,n):
            cur=cost[i]+min(prev1,prev2)
            prev2=prev1
            prev1=cur

        return min(prev1,prev2)