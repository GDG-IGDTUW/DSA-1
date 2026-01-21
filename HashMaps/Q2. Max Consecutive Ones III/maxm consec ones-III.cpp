class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,r=0,mx=0,cnt=0;
        int len;
        while(r<n){
            if(arr[r]==0)cnt++;
            while(cnt>k){
                if(arr[l]==0)
                    cnt--;
                    l++;
                
            }
            if(cnt<=k){
                len=r-l+1;
                mx=max(mx,len);
            }
            r++;
        }
        return mx;
    }
};