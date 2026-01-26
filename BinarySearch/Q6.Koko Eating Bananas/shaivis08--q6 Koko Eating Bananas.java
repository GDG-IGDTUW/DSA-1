class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int start=1;
        int end = piles[0];
        int result=end;
        for (int i = 1; i < piles.length; i++) {
            end = Math.max(end, piles[i]);
        }
        
        while (start<=end) {
            int k = start+(end-start)/2;
            long sum=0;
            for (int i=0;i<piles.length;i++) {
                sum+=((piles[i]+(long)(k-1))/k);
            }
           if (sum <= h) {
                result=k;
                end = k - 1; 
            } else {
                start = k + 1; 
            }
        }
        return result;
    }
}
