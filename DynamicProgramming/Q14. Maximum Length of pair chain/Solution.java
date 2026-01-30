class Solution {
    public int findLongestChain(int[][] pairs) {
        // Sort by second element (end time)
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[1], b[1]));

        int count = 1;
        int lastEnd = pairs[0][1];

        for (int i = 1; i < pairs.length; i++) {
            if (pairs[i][0] > lastEnd) {
                count++;
                lastEnd = pairs[i][1];
            }
        }

        return count;
    }
}
