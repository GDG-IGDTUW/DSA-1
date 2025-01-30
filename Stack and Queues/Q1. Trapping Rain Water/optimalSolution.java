public class optimalSolution {
    public static int trap(int[] arr){
        int n = arr.length;
        if((arr == null) || (n <= 2)){
            return 0;
        }

        int start = 0;
        int end = n - 1;
        
        int leftMax = 0;
        int rightMax = 0;

        int amount = 0;
        while(start < end){
            if(arr[start] <= arr[end]){
                if(leftMax != 0){
                    leftMax = Math.max(leftMax, arr[start]);
                    amount += (leftMax - arr[start]);
                }
                else{
                    leftMax = arr[start];
                }
                start++;
            }
            else{
                if(rightMax != 0){
                    rightMax = Math.max(rightMax, arr[end]);
                    amount += (rightMax - arr[end]);
                }
                else{
                    rightMax = arr[end];
                }
                end--;
            }
        }

        return amount;
    }
}
