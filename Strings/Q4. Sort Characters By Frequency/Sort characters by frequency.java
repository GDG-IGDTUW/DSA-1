//Optimised approach using hashmap and priority queue
class Solution {
    public String frequencySort(String s) {
        String result = "";
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i = 0; i<s.length(); i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i),0)+1);
        }
        PriorityQueue<Character> pq = new PriorityQueue<>((a,b)->map.get(b)-map.get(a)); //This pq will arrange the characters in descending order of their freq counts.
        pq.addAll(map.keySet());
        while(!pq.isEmpty()){
            char curr= pq.poll();
            int frequency = map.get(curr);
            for (int i = 0; i < frequency; i++) {
                result+=curr;
            }
        }
        return result;
    }
}
