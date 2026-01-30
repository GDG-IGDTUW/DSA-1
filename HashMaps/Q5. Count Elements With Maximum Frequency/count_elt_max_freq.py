class Solution:
    def maxFrequencyElements(self, nums):
        freq = {}
        max_freq = 0
        total = 0

        for n in nums:
            if n in freq:
                freq[n]+=1
            else:
                freq[n]=1

            if freq[n]>max_freq:
                max_freq=freq[n]
                total=max_freq
            elif freq[n]==max_freq:
                total+=max_freq

        return total

        
