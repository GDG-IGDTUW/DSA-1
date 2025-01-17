//Brute-Force-Approach
//Intution: The brute force approach tries all possible ways to allocate books to m students. For each possible allocation, it calculates the maximum pages assigned to any student and keeps track of the minimum among all possible allocations.
//Algorithm: i)Generate all possible partitions of the array into m contiguous subarrays using recursion or backtracking.
//ii) For each partition, calculate the maximum pages assigned to a student.
//iii) Return the minimum of these maximum values.
//Time Complexity: O(n^(m-1) * n) (Exponential), Space Complexity: O(m)

//CODE IMPLEMENTATION:

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum pages in a partition
int calculateMaxPages(vector<int>& arr, int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += arr[i];
    }
    return sum;
}

// Recursive function to solve the problem
int allocateBooks(int idx, int remainingStudents, vector<int>& arr) {
    int n = arr.size();
    // Base case: only one student left, allocate all remaining books
    if (remainingStudents == 1) {
        return calculateMaxPages(arr, idx, n - 1);
    }

    int minMaxPages = INT_MAX;
    int sum = 0;

    // Try allocating books to the current student and recursively solve for the remaining
    for (int i = idx; i < n - remainingStudents + 1; i++) {
        sum += arr[i];
        int maxPages = max(sum, allocateBooks(i + 1, remainingStudents - 1, arr));
        minMaxPages = min(minMaxPages, maxPages);
    }

    return minMaxPages;
}

int findPagesBrute(vector<int>& arr, int n, int m) {
    // Impossible case: more students than books
    if (m > n) return -1;
    return allocateBooks(0, m, arr);
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = 4, m = 2;

    cout << "The answer (Brute Force) is: " << findPagesBrute(arr, n, m) << endl;
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//OPTIMAL SOLUTION:

//Step-1 Binary Search Range Setup: The search range for the minimum maximum pages lies between max(arr) (largest single book) and sum(arr) (sum of all book pages).
//-Initialize low = max(arr) and high = sum(arr).
//Step-2 Feasibility Check:  Implement a helper function to check if the books can be allocated within a given maximum page limit (mid) using the available number of students (m).
//Step-3 Binary Search Logic: While low <= high then Compute mid = (low + high) / 2.
//-If countStudents(arr, mid) > m (more students needed than available), set low = mid + 1. Otherwise, set high = mid - 1 to explore smaller maximum page limits.
//Step-4 Termination and Result: The search stops when low > high, Then Return low, which represents the minimum maximum pages that can be assigned to any student.
// Time Complexity: O(n * log(sum(arr) - max(arr)))  ,  Space Complexity: O(1)

//CODE IMPLEMENTATION: 
#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& arr, int pages) {
    int students = 1, pagesSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (pagesSum + arr[i] <= pages) {
            pagesSum += arr[i];  // Add pages to the current student
        } else {
            students++;          // Allocate to the next student
            pagesSum = arr[i];   // Reset the pages sum for the new student
        }
    }
    return students;
}

// Function to find the minimum possible maximum pages
int findPagesOptimal(vector<int>& arr, int n, int m) {
    // Edge case: allocation is impossible
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());  // Minimum possible max pages
    int high = accumulate(arr.begin(), arr.end(), 0);  // Maximum possible max pages
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);

        if (students > m) {  // Too many students needed, increase the limit
            low = mid + 1;
        } else {  // Feasible, try to minimize further
            result = mid;
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = 4, m = 2;

    cout << "The answer (Optimal) is: " << findPagesOptimal(arr, n, m) << endl;
    return 0;
}
