class Solution {
    int day(int[] bloomDay ,int k ,int x){
        int count=0;
        int f=0;
        for(int j =0;j<bloomDay.length;j++){
            if(bloomDay[j]<=x){
                count++;
            }
            else{
                f+=count/k;
                count=0;
            }
        }
        f+=count/k;
    return f;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        if((long)m*k>bloomDay.length) return -1;
        int max=Integer.MIN_VALUE;
        int min=Integer.MAX_VALUE;
        for(int i =0;i<bloomDay.length;i++){
            max=Math.max(max,bloomDay[i]);
            min=Math.min(min,bloomDay[i]);
        }
        int low=min;
        int high=max;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(day(bloomDay,k,mid)>=m){
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