class Solution:
    def canCompleteCircuit(self, gas, cost):
        n = len(gas)
        totalGas = sum(gas)
        totalCost = sum(cost)
        if totalGas < totalCost:
            return -1
        remaining = 0
        ans = 0
        for i in range(n):
            remaining += gas[i] - cost[i]
            if remaining < 0:
                ans = i + 1
                remaining = 0
        
        return ans
