from collections import Counter, defaultdict
class Solution:
    def frequencySort(self, s: str) -> str:
        count = Counter(s)
        buckets = defaultdict(list) 
       
        for char, cnt in count.items():
            buckets[cnt].append(char)
        result = []
        for i in range(len(s), 0, -1):
            for c in buckets[i]:
                result.append(c * i)
        return "".join(result)
    
sol = Solution()
s = "tree"
print(sol.frequencySort(s)) 

s = "cccaaa"
print(sol.frequencySort(s))

s = "Aabb"
print(sol.frequencySort(s)) 
