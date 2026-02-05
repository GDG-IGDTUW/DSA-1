import java.util.*;

class Solution {

    public List<List<Integer>> subsetsWithDup(int[] nums) {

        List<List<Integer>> result = new ArrayList<>();

        // Step 1: Sort to handle duplicates
        Arrays.sort(nums);

        // Step 2: Backtracking
        backtrack(0, nums, new ArrayList<>(), result);

        return result;
    }

    private void backtrack(int index, int[] nums,
                           List<Integer> current,
                           List<List<Integer>> result) {

        // Add current subset
        result.add(new ArrayList<>(current));

        for (int i = index; i < nums.length; i++) {

            // Step 3: Skip duplicates at same level
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Choose
            current.add(nums[i]);

            // Explore
            backtrack(i + 1, nums, current, result);

            // Un-choose (backtrack)
            current.remove(current.size() - 1);
        }
    }
}
