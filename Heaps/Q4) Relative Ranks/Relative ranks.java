class Solution {
    public String[] findRelativeRanks(int[] score) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> score[b] - score[a]);
        String[] result = new String[score.length];
        for (int i = 0; i < score.length; i++) {
            pq.add(i);
        }
        result[pq.poll()] = "Gold Medal";
        if(pq.size()>0){
            result[pq.poll()] = "Silver Medal";
        }
        if(pq.size()>0){
            result[pq.poll()] = "Bronze Medal";
        }
        int pos = 4;
        while (!pq.isEmpty()) {
            int index = pq.poll();
            result[index] = String.valueOf(pos++);
        }
        return result;
    }
}
