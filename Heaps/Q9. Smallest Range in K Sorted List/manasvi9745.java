import java.util.*;

class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        
        int k = nums.size();
        
        // Min heap: [value, listIndex, elementIndex]
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );
        
        int currentMax = Integer.MIN_VALUE;
        
        // Initialize heap with first element from each list
        for (int i = 0; i < k; i++) {
            int val = nums.get(i).get(0);
            minHeap.offer(new int[]{val, i, 0});
            currentMax = Math.max(currentMax, val);
        }
        
        int rangeStart = 0;
        int rangeEnd = Integer.MAX_VALUE;
        
        while (true) {
            
            int[] curr = minHeap.poll();
            int minVal = curr[0];
            int listIndex = curr[1];
            int elemIndex = curr[2];
            
            // Update best range
            if (currentMax - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = currentMax;
            }
            
            // Move to next element in same list
            if (elemIndex + 1 == nums.get(listIndex).size()) {
                break;  // One list exhausted
            }
            
            int nextVal = nums.get(listIndex).get(elemIndex + 1);
            minHeap.offer(new int[]{nextVal, listIndex, elemIndex + 1});
            
            currentMax = Math.max(currentMax, nextVal);
        }
        
        return new int[]{rangeStart, rangeEnd};
    }
}
