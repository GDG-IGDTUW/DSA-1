from collections import defaultdict

class Solution:
    def groupPeople(self, groupSize: list[int]) -> list[list[int]]:
        res = []
        groups = defaultdict(list)  # Use defaultdict to automatically create lists
        for i, size in enumerate(groupSize):
            groups[size].append(i)

            # If the current group size reaches the required size, add to result and reset
            if len(groups[size]) == size:
                res.append(groups.pop(size))

        return res

# Examples
sol = Solution()
groupSizes = [3, 3, 3, 3, 3, 1, 3]   
print(sol.groupPeople(groupSizes))  

groupSizes = [2, 1, 3, 3, 3, 2]
print(sol.groupPeople(groupSizes)) 