class Solution {
    public void subset2(int []nums,int n,int idx,List<Integer> ds,List<List<Integer>> ans){
        
         ans.add(new ArrayList<>(ds));
       
        for(int i =idx;i<nums.length;i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            ds.add(nums[i]);
            subset2(nums,n,i+1,ds,ans);
            ds.remove(ds.size()-1);
            
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        int idx=0;
        List<Integer> ds= new ArrayList<>();
        List<List<Integer>> ans= new ArrayList<>();
        subset2(nums,n,idx,ds,ans);
        return ans;

    }
}