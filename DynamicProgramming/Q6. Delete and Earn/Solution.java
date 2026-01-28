class Solution {
    public int deleteAndEarn(int[] nums) {

        int[] a = new int[10001];

        for (int x : nums)
            a[x] += x;

        int b = 0, c = 0;

        for (int i = 0; i <= 10000; i++) {
            int t = c;
            c = Math.max(c, b + a[i]);
            b = t;
        }

        return c;
    }
}
