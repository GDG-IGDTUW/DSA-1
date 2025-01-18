#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int assignCookies(vector<int>& greed,vector<int>& cookieSize){
    int n=greed.size();
    int m=cookieSize.size();
    sort(greed.begin(),greed.end());
    sort(cookieSize.begin(),cookieSize.end());
    int l=0; //pointer at cookieSize array at starting pos
    int r=0; //pointer at greed array at starting pos ie 1st child
    while(l<m && r<n){
        if(greed[r]<=cookieSize[l]){
            r++;
        } 
        l++;

    }
    return r;
}

int main(){
    vector<int> greed={1,2,3};
    vector<int> cookieSize={1,1};
    int ans=assignCookies(greed,cookieSize);
    cout<<"No. of kids assigned cookies"<<" "<<ans;
}