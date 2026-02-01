import java.util.Arrays;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {

        int n = intervals.length;
        if (n == 0) return 0;

        // 1. Sort by end time
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

        // 2. Activity Selection
        int maxNonOverlap = 1;           // select first activity
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            // If current activity does not overlap
            if (intervals[i][0] >= lastEnd) {
                maxNonOverlap++;
                lastEnd = intervals[i][1];
            }
        }

        // 3. Remove = total - maximum non-overlapping
        return n - maxNonOverlap;
    }
}
