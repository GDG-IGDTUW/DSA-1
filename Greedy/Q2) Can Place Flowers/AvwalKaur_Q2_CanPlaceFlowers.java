public class AvwalKaur_Q2_CanPlaceFlowers{
    static boolean canPlaceFlowers(int[] flowerbed, int n) {
        int m=flowerbed.length;
        if(n==0) return true;
        
        for(int i=0;i<m;i++) {
            boolean left=(i==0 || flowerbed[i-1]==0); 
            // if i==0, we are safe from left side and if not for remaining indices check with the adjacent left values
            boolean right=(i==m-1 || flowerbed[i+1]==0);
            // if i==m-1, we are safe from right side and if not for remaining indices check with the adjacent right values

            if(left==true && right==true && flowerbed[i]==0) {
                flowerbed[i]=1;
                n--;
            }
        }
        if(n<=0) return true;
        return false;
    }
    public static void main(String[] args) {
        int[] flowerbed = {1,0,0,0,1};
        int n=1;
        if(canPlaceFlowers(flowerbed, n)) {
            System.out.println(n+" flowers can be placed");
        } else {
            System.out.println(n+" flowers can't be placed");
        }
    }
}