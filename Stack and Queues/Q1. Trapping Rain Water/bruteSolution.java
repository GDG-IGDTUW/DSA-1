public class bruteSolution{
    public static int trap(int[] arr){
        int n = arr.length;
        if((arr == null) || (n <= 2)){
            return 0;
        }

        int waterTrapped = 0;
        for(int i=0; i<n; i++){
            int j = i;
            int leftMax = 0;
            int rightMax = 0;

            // Calculating leftMax
            while(j >= 0){
                leftMax = Math.max(leftMax, arr[j]);
                j--;
            }

            // Calculating rightMax
            j = i;
            while(j < n){
                rightMax = Math.max(rightMax, arr[j]);
                j++;
            }

            waterTrapped += Math.min(leftMax, rightMax) - arr[i];
        }

        return waterTrapped;
    }
}