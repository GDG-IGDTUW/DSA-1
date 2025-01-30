import java.util.*;

class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;

        // Sort the deck
        Arrays.sort(deck);

        // Create a queue s
        Queue<Integer> indexQueue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            indexQueue.add(i);
        }

        // Result array 
        int[] result = new int[n];

        // Place cards in the correct order
        for (int card : deck) {
            // Place the smallest card in the position indicated by the front of the queue
            result[indexQueue.poll()] = card;

            // simulate moving the next index to the back
            if (!indexQueue.isEmpty()) {
                indexQueue.add(indexQueue.poll());
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] deck = {17, 13, 11, 2, 3, 5, 7};
        int[] result = solution.deckRevealedIncreasing(deck);

        System.out.println(Arrays.toString(result)); // Output: [2, 13, 3, 11, 5, 17, 7]
    }
}
