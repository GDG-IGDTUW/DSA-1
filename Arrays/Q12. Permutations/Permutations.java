class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        backtrack(nums,result, temp, used);
        return result;
    }
    void backtrack(int[]nums,List<List<Integer>>result, List<Integer>temp, boolean[]used){
        if(temp.size()==nums.length){
            result.add(new ArrayList<>(temp));
            return;
        }
        for(int i = 0; i<nums.length; i++){
            if(used[i]!=true){
                used[i] = true;
                temp.add(nums[i]);
                backtrack(nums, result, temp, used);
                used[i] = false;
                temp.remove(temp.size()-1);
            }
        }
    }
}
