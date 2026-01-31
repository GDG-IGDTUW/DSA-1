import java.util.Arrays;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) return 0;

        // Sort intervals by end time
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

        int removals = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            // If overlapping
            if (intervals[i][0] < prevEnd) {
                removals++;
            } else {
                // No overlap, update prevEnd
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
}
