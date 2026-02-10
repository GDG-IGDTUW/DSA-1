import java.util.Arrays;

class Solution {
    public int findMinArrowShots(int[][] points) {

        if (points == null || points.length == 0) return 0;

        // Sort balloons by end coordinate
        Arrays.sort(points, (a, b) -> {
            if (a[1] == b[1]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        int arrows = 1;
        int arrowPos = points[0][1];

        for (int i = 1; i < points.length; i++) {
            // If current balloon starts after arrow position, need new arrow
            if (points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1];
            }
        }

        return arrows;
    }
}
