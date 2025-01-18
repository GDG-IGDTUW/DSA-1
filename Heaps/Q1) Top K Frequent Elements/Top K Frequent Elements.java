import java.util.*;
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int num:nums){
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->Integer.compare(a[1], b[1])); 
        for(Map.Entry<Integer, Integer> entry: map.entrySet()){
            pq.offer(new int[]{entry.getKey(), entry.getValue()});
            if(pq.size()>k){
                pq.poll(); //Makes sure only k elements are there in the queue
            }
        }
        int[]result = new int[k];
        for(int i = k-1; i>=0; i--){
            result[i] = pq.poll()[0];
        }
        return result;
    }
}
