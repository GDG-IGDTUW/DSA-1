import java.util.Arrays;

public class AvwalKaur_Q1_AssignCookies {
    static int assignCookies(int[] greed, int[] size) {
        Arrays.sort(greed);
        Arrays.sort(size);
        int n=greed.length, m=size.length;
        int l=0, r=0;
        int cnt=0;
        while(l<n && r<m) {
            if(size[r]>=greed[l]) {
                l++;
                cnt++;
            } 
            r++;
        }
        return cnt;
    }
    public static void main(String[] args) {
        int[] greed={4,5,8,3,2};
        int[] size={3,2,1,4};
        System.out.println("Maximum number of children who can be assigned cookies are: "+assignCookies(greed, size));
    }
}
