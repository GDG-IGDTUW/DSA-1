import java.util.PriorityQueue;

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        // Add first m elements of nums1
        for (int i = 0; i < m; i++) {
            minHeap.offer(nums1[i]);
        }

        // Add all elements of nums2
        for (int i = 0; i < n; i++) {
            minHeap.offer(nums2[i]);
        }

        // Put back sorted elements into nums1
        int index = 0;
        while (!minHeap.isEmpty()) {
            nums1[index++] = minHeap.poll();
        }
    }
}
