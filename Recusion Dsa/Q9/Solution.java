class Solution {
    public void helper(int startInd, int k, List<Integer> curr, List<List<Integer>> ans, int target){
        if(target==0 && curr.size()==k){
            ans.add(new ArrayList<>(curr));
            return;
        }

        for(int i=startInd; i<10; i++){
            if(i<=target){ // pick it up
                curr.add(i);
                helper(i+1, k, curr, ans, target-i);
                curr.remove(curr.size()-1);
            }
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        helper(1, k, curr, ans, n);
        return ans;
    }
}
