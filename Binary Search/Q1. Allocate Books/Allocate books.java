import java.util.ArrayList;

public class Solution {
    public static int findPages(ArrayList<Integer> arr, int n, int m) {
        if (m > n) {
            return -1;
        }

        int low = arr.get(0);
        int high = 0;

        for (int i = 0; i < arr.size(); i++) {
            high += arr.get(i); 
            low = Math.max(low, arr.get(i));
        }
      //low represents the minimum number of pages a student can read
      //high represents the maximum number of pages a student can read
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2; //current max number of pages to be alloted to a student (to be minimised)
            int studentsRequired = 1; //Number of students required to allocate books
            int currentSum = 0; //Pages allocated to current studen
            boolean flag = false;
            for (int i = 0; i < arr.size(); i++) {
                if (currentSum + arr.get(i) > mid) { //if this val> max number of pages to be alloted, number of students need to be increased.
                    studentsRequired++;
                    currentSum = arr.get(i); //new book is assigned to current student
                    if (studentsRequired > m) { //if number of students needed exceeds the number of students, this arrangement is not possible.
                        flag = true;
                        break;
                    }
                } else {
                    currentSum += arr.get(i);
                }
            }

            if (flag) {
                low = mid + 1;
            } else {
                result = mid;
                high = mid - 1;
            }
        }

        return result;
    }
}
