public class betterSolution {
    public static int trap(int[] arr){
        int n = arr.length;
        if((arr == null) || (n <= 2)){
            return 0;
        }

        // Finding the leftMax array
        int[] left = new int[n];
        left[0] = arr[0];
        for(int i=1; i<n; i++){
            left[i] = Math.max(left[i - 1], arr[i]);
        }

        // Finding the rightMax array
        int[] right = new int[n];
        right[n - 1] = arr[n - 1];
        for(int i=n-2; i>=0; i--){
            right[i] = Math.max(right[i + 1], arr[i]);
        }

        // Finding the amount of water trapped
        int amount = 0;
        for(int i=0; i<n; i++){
            amount += (Math.min(left[i], right[i]) - arr[i]);
        }

        return amount;
    }
}
