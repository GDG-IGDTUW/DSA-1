class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool row=false,col=false;
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){ row=true; break;}
        }
        for(int j=0;j<m;j++){
            if(matrix[j][0]==0) {col=true; break;}
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                    if(matrix[0][j]==0 or matrix[i][0]==0) matrix[i][j]=0;
            }
        }
        if(row){
            for (int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};