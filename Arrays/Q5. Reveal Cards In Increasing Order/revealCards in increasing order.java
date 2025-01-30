class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i<deck.length; i++){
            q.add(i);
        }
        Arrays.sort(deck);
        int[]result = new int[deck.length];
        for(int i = 0; i<deck.length; i++){
            int index = q.poll();
            if(q.size()>0){
                int next_num = q.poll();
                q.add(next_num);
            }
            
            result[index] = deck[i];
        }
        return result;
    }
}
