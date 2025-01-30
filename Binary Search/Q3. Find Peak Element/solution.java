import java.util.Scanner;

public class solution {
    
    public static int peakElement(int[] arr){
        int n = arr.length;
        if(n == 1){
            return 0;
        }

        if(arr[0] > arr[1]){
            return 0;
        }

        if(arr[n - 1] > arr[n - 2]){
            return n - 1;
        }

        int start = 1;
        int end = n - 2;
        while(start <= end){
            int mid = start + (end - start)/2;
            if((arr[mid] > arr[mid + 1]) && (arr[mid] > arr[mid - 1])){
                return mid;
            }

            else if(arr[mid] > arr[mid + 1]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the size of array: ");
        int n = scn.nextInt();

        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            System.out.print("Entr value: ");
            arr[i] = scn.nextInt();
        }

        scn.close();

        int ans = peakElement(arr);
        if(ans != -1){
            System.out.println("Peak element is at index: " + ans);
        }
        else{
            System.out.println("No peak element");
        }
    }
}
