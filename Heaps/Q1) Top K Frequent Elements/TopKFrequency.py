class Solution:
    def topKFelements(self, nums: list[int], k: int) -> list[int]:
        count={}
        freqency= [[] for i in range(len(nums)+1)]

        for n in nums:
            count[n] = 1 + count.get(n,0)
        for n, c in count.items():
            freqency[c].append(n)

        result = []
        for i in range(len(freqency) -1, 0, -1):
            for n in freqency[i]:
                result.append(n)
                if len(result)== k:
                    return result
#xample 1:
sol = Solution()
nums = [1,1,1,2,2,3]
k = 2 
print(sol.topKFelements(nums, k))


nums = [1]
k = 1 
print(sol.topKFelements(nums, k))
