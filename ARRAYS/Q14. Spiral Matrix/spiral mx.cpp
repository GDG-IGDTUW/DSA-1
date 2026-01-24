class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mx) {
        vector<int> a;
        int m=mx.size();
        int n=mx[0].size();
        int top=0,left=0,right=n-1,bottom=m-1;
        while(top<=bottom and left<=right){
        for(int i=left;i<=right;i++){
            a.push_back(mx[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            a.push_back(mx[i][right]);
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            a.push_back(mx[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            a.push_back(mx[i][left]);
        }
        left++;
        }
    }
    return a;
    }
};