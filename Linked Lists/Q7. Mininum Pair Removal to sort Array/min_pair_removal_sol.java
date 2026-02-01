import java.util.*;

class Solution {

    static class Pair {
        int sum;
        int index;
        Pair(int sum, int index) {
            this.sum = sum;
            this.index = index;
        }
    }

    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;
        if (n <= 1) return 0;

        LinkedList<Integer> list = new LinkedList<>();
        for (int x : nums) list.add(x);

        int ops = 0;

        while (!isNonDecreasing(list)) {

            PriorityQueue<Pair> pq = new PriorityQueue<>(
                (a, b) -> a.sum != b.sum ? a.sum - b.sum : a.index - b.index
            );

            for (int i = 0; i < list.size() - 1; i++) {
                pq.offer(new Pair(list.get(i) + list.get(i + 1), i));
            }

            Pair best = pq.poll();
            int idx = best.index;

            int merged = list.get(idx) + list.get(idx + 1);
            list.remove(idx + 1);
            list.set(idx, merged);

            ops++;
        }

        return ops;
    }

    private boolean isNonDecreasing(List<Integer> list) {
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i) < list.get(i - 1)) return false;
        }
        return true;
    }
}
