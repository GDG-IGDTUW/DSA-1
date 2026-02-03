class Solution {
    int funcCap(int capacity,int [] weights){
        int day=1;
        int load=0;
        for(int i =0;i<weights.length;i++){
            if(weights[i]+load>capacity){
                load=weights[i];
                day+=1;
            }
            else{
                load+=weights[i];
            }
        }
    return day;
    }
    public int shipWithinDays(int[] weights, int days) {
        int sum=0;
        int max=Integer.MIN_VALUE;
        for(int i =0;i<weights.length;i++){
            sum+=weights[i];
            max=Math.max(max,weights[i]);
        }
        int low=max;
        int high=sum;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(funcCap(mid,weights)<=days){
                ans=mid;
                high=mid-1;
            }
            else{
              
                low=mid+1;
            }
        
        }
    return ans;
    }
}