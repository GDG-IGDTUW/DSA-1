import java.util.Arrays;

/* 
Question Solution - Assign Cookies- In the given question, we have to find the maximum no. of content children which will be only possible
if the size of the cookie is greater than or equal to the greed factor of the child. So, we will sort the greed factor and cookie size
to take children with less greed factor and cookie size first, and maximize the result in this way. For ex. g = [2,1,3], s = [1,1] => here 
first array is not sorted and second array is sorted. So, if we sort both arrays, then g = [1,2,3] and s = [1,1]. Now, we will compare, we will first take
1st child with 1st cookie, which satisfies first child increasing the count to one. Then, 2nd child have greed factor 2, but second cookie 
is of 1 size, count remains same, we will move size pointer to next, but its end of array, means there is no bigger array.
So, the output will be 1. 
It is a greedy approach, as we are taking the smallest size cookie first and then moving to bigger size cookies. We are being greedy by taking
small size cookies first, so that we can maximize the content children.
*/

public class TannuRawatQ1AssignCookies {

    public static int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g); // Sort 1st array
        Arrays.sort(s); // Sort 2nd array
        int i = 0; // Pointer for greed factor
        int j = 0; // Pointer for cookie size
        int count = 0; // Count of content children
        while (i < g.length && j < s.length) { // Loop till the end of both arrays
            if (s[j] >= g[i]) { // If cookie size is greater than or equal to greed factor
                i++; // Move to next child
                j++; // Move tocookie
                count++; // increase count of content children
            } else {
                j++; // else move only size pointer to find bigger cookie
            }
        }
        return count; // return count of content children
    }

    // Main function
    public static void main(String[] args) {
        int[] greedFactors = { 1, 2, 3 };
        int[] cookieSizes = { 1, 1 };

        int result = findContentChildren(greedFactors, cookieSizes);
        System.out.println("Number of content children: " + result);
    }
}