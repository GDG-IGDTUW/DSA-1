import java.util.Scanner;

public class solution {
    public static int searchRotatedSorted(int[] arr, int target){
        int start = 0;
        int end = arr.length - 1;

        while(start <= end){
            int mid = start + (end - start)/2; // avoiding integer overflow this way
            if(arr[mid] == target){
                return mid;
            }

            // Handling duplicates
            if((arr[start] == arr[mid]) && (arr[mid] == arr[end])){
                start++;
                end--;
                continue;
            }

            if((target > arr[mid]) || (target < arr[mid])){
                // now checking for left or right sort
                if(arr[start] <= arr[mid]){ // left sort
                    if((target >= arr[start]) && (target <= arr[mid])){
                        end = mid - 1;
                    }
                    else{
                        start = mid + 1;
                    }
                }
                else{ // right sort
                    if((target >= arr[mid]) && (target <= arr[end])){
                        start = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input array size
        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();

        // Input array elements
        int[] arr = new int[n];
        System.out.println("Enter the elements of the rotated sorted array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Input target value
        System.out.print("Enter the target value to search: ");
        int target = scanner.nextInt();

        // Perform search
        int result = searchRotatedSorted(arr, target);

        // Output result
        if (result != -1) {
            System.out.println("Target found at index: " + result);
        } else {
            System.out.println("Target not found in the array.");
        }

        scanner.close();
    }
}
