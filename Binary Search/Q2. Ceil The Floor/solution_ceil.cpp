#include<iostream>
#include<bits/stdc++.h>
using namespace std;
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int low=0;
	int high=n-1;
	int floor_=-1;
	int ceil_=-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]>=x){
			ceil_=a[mid];
			high=mid-1;
		}
		else low=mid+1;
	}
	low=0;
	high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]<=x){
			floor_=a[mid];
			low=mid+1;
		}
		else high=mid-1; 
	}
	return{floor_,ceil_};
}
int main(){
    vector<int> a = {1, 2, 8, 10, 10, 12, 19};
    int x = 5; // Target value

    // Find floor and ceil
    pair<int, int> result = getFloorAndCeil(a, a.size(), x);

    // Output the results
    cout << "Floor: " << result.first << ", Ceil: " << result.second << endl;
    return 0;
}