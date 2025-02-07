// Time complexity: O(logR*n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> arr, int n, int m, int maxAllowedPages){
    int students = 1, pages = 0;
    for(int i=0; i<n; i++){ //O(n)
        if(arr[i] > maxAllowedPages) return false;

        if(pages+arr[i] <= maxAllowedPages){
            pages += arr[i];
        }
        else{
            students++;
            pages = arr[i];
        }
    }
    return (students>m) ? false : true;
}

int allocateBooks(vector<int>& arr, int n, int m){  // O(logR * n)
    if(m>n) return -1; // Number of students can't be greater than no of books
    int sum = 0;
    int result = -1;

    // Calculating sum of array
    for(int i:arr) sum += i; //O(n)

    // Creating an array of range in which the answer may lie
    int start = 0, end = sum;
    while (start <= end)    {   //O(log R) R = Range
        int mid = start + (end-start)/2;
        if(isValid(arr, n, m, mid)){    //O(n)
            result = mid;
            end = mid-1;
        }
        else start = mid+1;
    }
    return result;
}

int main(){
    vector<int> arr = {12, 34, 67, 90};
    int n = 4, m = 2; // n-> no of books, m -> no of students

    cout<<allocateBooks(arr, n, m);
    return 0;
}
