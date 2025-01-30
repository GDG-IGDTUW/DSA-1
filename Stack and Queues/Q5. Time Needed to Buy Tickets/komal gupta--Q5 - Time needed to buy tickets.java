// Approach
// 1. Initialize a variable time to keep track of the total time taken.
// 2. While the person at position k hasn't bought all their tickets:
// Iterate through the queue and let each person buy a ticket.
// Update the queue by decrementing the number of tickets for the person who bought a ticket.
// Increment the time by 1 second for each pass.
// 3. Return the total time taken.


class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int total = 0;

        for (int i = 0; i < tickets.length; i++) {
            if (i <= k) {
                total += Math.min(tickets[i], tickets[k]);
            } else {
                total += Math.min(tickets[i], tickets[k] - 1);
            }
        }

        return total;
    }
}


// Time complexity:O(n)
// Space complexity:O(1)
