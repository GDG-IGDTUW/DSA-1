//Memoisation Approach -The goal is to find the minimum jumps needed to reach the last index of the array starting from the first index, where each element specifies the maximum jump length from that position.

public class TannuRawatQ2JumpGame {

    public static int minJumpsRecur(int i, int[] arr, int[] memo) {

        // Return 0 when last element is reached.
        if (i == arr.length - 1)
            return 0;

        // If value for current index is memoized,
        // then return it.
        if (memo[i] != -1)
            return memo[i];

        // Traverse through all the points
        // reachable from arr[i].
        // Recursively, get the minimum number
        // of jumps needed to reach array end from
        // these points.
        int ans = Integer.MAX_VALUE;
        for (int j = i + 1; j <= i + arr[i] && j < arr.length; j++) {
            int val = minJumpsRecur(j, arr, memo);
            if (val != Integer.MAX_VALUE)
                ans = Math.min(ans, 1 + val);
        }

        // Memoize the value and
        // return it.
        return memo[i] = ans;
    }

    // Function to return the minimum number
    // of jumps to reach arr[h] from arr[l]
    public static int minJumps(int[] arr) {

        // array to memoize values
        int[] memo = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            memo[i] = -1;
        }

        int ans = minJumpsRecur(0, arr, memo);

        // If end cannot be reached.
        if (ans == Integer.MAX_VALUE)
            return -1;

        return ans;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
        System.out.println("Min-Jumps" + minJumps(arr));
    }
}
