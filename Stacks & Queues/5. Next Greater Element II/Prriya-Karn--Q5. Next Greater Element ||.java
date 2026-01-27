import java.util.*;

class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];

        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;

            while (j != i && nums[j] <= nums[i]) {
                j = (j + 1) % n;
            }

            if (nums[j] > nums[i]) {
                res[i] = nums[j];
            } else {
                res[i] = -1;
            }
        }

        return res;
    }
}
