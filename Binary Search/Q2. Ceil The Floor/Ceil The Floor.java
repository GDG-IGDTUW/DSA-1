public class ceilthefloor{
    static int findFloor(int[]arr, int n, int x){
        int l = 0; 
        int h = n-1;
        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[mid]<=x){
                ans = arr[mid];
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
    static int findCeil(int[]arr, int n, int x){
        int l = 0; 
        int h = n-1;
        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[mid]>=x){
                ans = arr[mid];
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] arr = {3, 4, 4, 7, 8, 10};
        int n = 6, x = 5;
        int floor = findFloor(arr, n, x);
        int ceil = findCeil(arr,n,x);
        System.out.println(floor+" "+ceil);
    }
} 
