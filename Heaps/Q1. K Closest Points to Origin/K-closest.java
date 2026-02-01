import java.util.*;

class Solution {
    public int[][] kClosest(int[][] points, int k) {

        // Max Heap based on distance from origin
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> (b[0]*b[0] + b[1]*b[1]) - (a[0]*a[0] + a[1]*a[1])
        );

        for (int[] point : points) {
            pq.offer(point);
            if (pq.size() > k) {
                pq.poll(); // remove farthest
            }
        }

        int[][] result = new int[k][2];
        int i = 0;
        while (!pq.isEmpty()) {
            result[i++] = pq.poll();
        }

        return result;
    }
}
