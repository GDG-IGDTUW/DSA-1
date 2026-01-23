class Solution {
    public void helper(int ind, int nums[], List<Integer> list, List<List<Integer>> ans){
        if(ind == nums.length){
            ans.add(new ArrayList<>(list));
            return;
        }
        //pick
        list.add(nums[ind]);
        helper(ind+1, nums, list, ans);
        //skip
        list.remove(list.size()-1);
        helper(ind+1, nums, list, ans);
    }   

    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> list = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        helper(0, nums, list, ans);
        return ans;
    }
}
