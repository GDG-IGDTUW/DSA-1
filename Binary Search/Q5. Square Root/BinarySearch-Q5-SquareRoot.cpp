#include<iostream>
using namespace std;
/*
Logic:
    1) If n is 0 or 1, return the number itself.
    2) Use Binary Search to find square root of n.
    3) If mid*mid == n, return mid.
    4) If mid*mid < n, update low = mid+1 and ans = mid.
    5) If mid*mid > n, update high = mid-1.
    6) Return the closest value if number is not perfect square.
*/

int squareRoot(int n){
    if(n==0 || n==1){
        return n;
    }
    
    int low = 1, high = n, ans = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mid*mid == n) return mid;
        if(mid*mid < n){
            low = mid+1;
            ans = mid;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    // Driver Code
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"The square root of "<<n <<" is: "<<squareRoot(n);
}