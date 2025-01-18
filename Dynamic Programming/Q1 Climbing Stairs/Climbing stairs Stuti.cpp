// question
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#include <iostream>
#include <vector>
using namespace std;

int recursive(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    return recursive(n - 1) + recursive(n - 2);
}
// have solved recursively by returning 1 to indicate reaching the final step

int dpTopdown(int n, vector<int>& dp) {
    if (dp[n] != -1) return dp[n];
    if (n == 0) return dp[0] = 1;
    if (n < 0) return 0;
    return dp[n] = recursive(n - 1) + recursive(n - 2);
}
// storing the answers as i move recursively to reduce the time complexity from 
//exponential to linear 

int dpBottomUp(int n,vector<int>& dp){
dp[0]=1;
dp[1]=1;
int i=2;
while(i<=n){
  dp[i]=dp[i-1]+dp[i-2];
  i++;
}
// my state is f(n)=f(n-1)+f(n-2)
// have initialised the base cases of n=1 , n=0 where this wont work properly 
// and have further build the answer
return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << recursive(n) << " solution of my recursive approach " << endl;
    vector<int> dp1(n + 1, -1);
    cout << dpTopdown(n, dp1) << " solution of top down approach" << endl;
    vector<int>dp2(n+1);
    cout << dpBottomUp(n,dp2) << " solution of bottom up";

    return 0;
}
