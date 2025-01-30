class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        Deque<Integer> q = new LinkedList<>();
        for(int i = 0; i<nums.length; i++){
            while(!q.isEmpty() && nums[q.getLast()]<nums[i]){
                q.pollLast();
            }
            q.addLast(i);
            if(q.getFirst()<=i-k){
                q.pollFirst();
            }
            if(i>=k-1){
                list.add(nums[q.getFirst()]);
            }
        }
        int[]res = new int[list.size()];
        for(int i = 0; i<res.length; i++){
            res[i] = list.get(i);
        }
        return res;
    }
}
