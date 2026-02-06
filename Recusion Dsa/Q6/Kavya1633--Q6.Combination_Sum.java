class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> targetSum=new ArrayList<>();
        ArrayList<Integer> candList=new ArrayList<>();

        getCombinations(0,candidates,target, candList,targetSum);
        return targetSum;

    }

    public void getCombinations(int idx,int[] nums,int target,ArrayList<Integer> candList, List<List<Integer>> ans){
        if(target==0){
            // store the copy of the list if not already exist.
            if(!ans.contains(candList)) ans.add(new ArrayList<>(candList));
        }
        if(idx>=nums.length){
            return;
        }

        //pick the element
        if(target>=nums[idx]){
            //add ele to the list
            candList.add(nums[idx]);

            // can take same ele multiple times
            getCombinations(idx,nums,target-nums[idx],candList,ans);

            // remove the ele from the list
            candList.remove(candList.size()-1);
        }

        //not pick the element
        getCombinations(idx+1,nums,target,candList,ans);
    }
}