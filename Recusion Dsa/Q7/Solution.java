class Solution {
    public void helper(int startInd, int nums[], List<Integer> curr, List<List<Integer>> ans, int target){
        if(target == 0){
            ans.add(new ArrayList<>(curr));
            return;
        }

        //try starting the subseq from each of the indices 
        for(int i=startInd; i<nums.length; i++){
            if(i>startInd && nums[i]==nums[i-1]) // if there are duplicates we skip them
                continue;
            if(nums[i]<=target){
                curr.add(nums[i]);
                helper(i+1, nums, curr, ans, target-nums[i]);
                curr.remove(curr.size()-1);
            }
           
        }
    }
    public List<List<Integer>> combinationSum2(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        helper(0, nums, curr, ans, target);
        return ans;
    }
}
