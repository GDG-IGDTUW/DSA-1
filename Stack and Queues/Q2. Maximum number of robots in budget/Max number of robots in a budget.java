class Solution {
    public int maximumRobots(int[] chargeTimes, int[] runningCosts, long budget) {
        int n = chargeTimes.length; 
        Deque<Integer> dq = new ArrayDeque<>();
        long sum = 0;
        int left = 0;
        int result = 0;

        for (int right = 0; right < n; right++) {
            while (!dq.isEmpty() && chargeTimes[dq.peekLast()] <= chargeTimes[right]) {
                dq.pollLast();
            }
            dq.offerLast(right);

            sum += runningCosts[right];

            while (!dq.isEmpty() && (chargeTimes[dq.peekFirst()] + (right - left + 1) * sum) > budget) {
                if (dq.peekFirst() == left) {
                    dq.pollFirst();
                }
                sum -= runningCosts[left];
                left++;
            }

            result = Math.max(result, right - left + 1);
        }

        return result;
    }
}
