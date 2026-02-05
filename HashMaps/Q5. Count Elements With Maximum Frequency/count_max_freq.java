class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer,Integer> map=new HashMap<>();
        for(int i =0;i<nums.length;i++){
            map.put(nums[i],map.getOrDefault(nums[i], 0)+1);
        }
        int max=Integer.MIN_VALUE;
        int count=0;
        for (Map.Entry<Integer, Integer> e : map.entrySet()) {
            if(max==e.getValue()){
                count+=e.getValue();
            }
            else if(e.getValue()>max){
          max=Math.max(e.getValue(),max);
          count=max;
            }else{
                max=Math.max(e.getValue(),max);
            }
    }
    return count;
    }
}