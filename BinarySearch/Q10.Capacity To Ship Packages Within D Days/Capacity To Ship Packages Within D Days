class Solution {
public:
    bool valid(vector<int>& weights,int n,int d,int max) {
        int days=1,weight=0;
        for (int i=0;i<n;i++) {                 
            if (weights[i]>max ) return false;  

            if (weights[i]+weight<=max) {
                weight+=weights[i];           //if weight sum <max then keep adding
            }else{
                weight=weights[i];            //else add a day & start weight with new weight[i]
                days++;
            }
        }
        return days<=d;
    }

    int shipWithinDays(vector<int>& weights, int d) {
        int sum=0,n=weights.size();
        for (int i=0;i<n;i++) {           //calculating total max weight
            sum+=weights[i];
        }
        int ans=-1;
        int st=0,end=sum;                //binary search on the arr of capacity containg 1 to sum of weights (eg : 1,2,3,....sum)
        while (st<=end) {
            int mid=st+(end-st)/2;
            if (valid(weights,n,d,mid)) {  //checking if the weight is possible or not.We need to calculate least of max weights . 
                end=mid-1;
                ans=mid;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};
