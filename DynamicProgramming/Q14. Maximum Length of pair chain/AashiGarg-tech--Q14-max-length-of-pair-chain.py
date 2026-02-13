class Solution:
    def findLongestChain(self, pairs):
        pairs.sort(key=lambda x: x[1])

        count = 1
        last_end = pairs[0][1]

        for i in range(1, len(pairs)):
            if pairs[i][0] > last_end:
                count += 1
                last_end = pairs[i][1]

        return count
 