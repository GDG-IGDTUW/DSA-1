class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {

        int len=flowerbed.length;

        if(n==0) return true;
        // base condition when len==1
        if(len==1){
            return flowerbed[0]==0 && n==1;
        }

        int i=1;
        int flower=0;

        if(flowerbed[0]==0 && flowerbed[1]!=1){
            flower++;
            i=2;
        }

        while(i<len-1){
            // chk adjacent idx before placing the flower
            if(flowerbed[i]==0 && flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                flower++;
                i+=2;
            }
            else i++;
        }
        // chk the last idx available for flower
        if(i==len-1 && flowerbed[i]==0 && flowerbed[i-1]!=1) flower++;

        return flower>=n;






    }
}