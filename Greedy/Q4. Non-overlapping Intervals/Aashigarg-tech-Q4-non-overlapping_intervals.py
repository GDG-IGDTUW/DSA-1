class Solution:
    def eraseOverlapIntervals(self, intervals):
        intervals.sort(key=lambda x: x[1])

        countk = 1
        last = intervals[0][1]

        for i in range(1, len(intervals)):
            if intervals[i][0] >= last:
                countk += 1
                last = intervals[i][1]

        return len(intervals) - countk