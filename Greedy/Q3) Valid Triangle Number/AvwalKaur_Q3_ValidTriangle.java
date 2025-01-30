import java.util.Arrays;

public class AvwalKaur_Q3_ValidTriangle {
    // BRUTE FORCE --> O(n^3) 
    static int bruteApproach(int[] arr) {
        // Try out all posiible triplets that satisfy the property of triangle
        int cnt=0;
        int n=arr.length;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if((arr[i]+arr[j]>arr[k]) && (arr[j]+arr[k]>arr[i]) && (arr[k]+arr[i]>arr[j])) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    // USING TWO POINTER APPROACH --> O(n^2)
    static int validTriangle(int[] arr) {
        int n=arr.length;
        // if the number of elements in array are less than 3, no triangle can be formed
        if(n<3) return 0; 

        Arrays.sort(arr);
        int cnt=0;

        // Fix the largest element as one of the sides and look for pair of other of two sides in triangle
        for(int i=n-1;i>=2;i--) {
            // Use two pointers -> keep one at index 0 and one at index (n-1) to check no. of valid triplets
            // that can be found from index j to k
            int j=0, k=i-1;
            while(j<k) {
                // if the sum of elements at j and k are greater than index i, then that means that all elements 
                // between k and j will create a valid pair with i index
                // once these are explored, move k to a lesser index to check if that can be included in pair as well.
                if(arr[j]+arr[k]>arr[i]) {
                    cnt+=(k-j); 
                    k--;
                } else {
                    j++;
                }
            }
        }
        return cnt;
    }
    public static void main(String[] args) {
        int[] arr={4,2,3,4};
        System.out.println("Number of triplets that can be made triangles are: "+validTriangle(arr));
    }
}