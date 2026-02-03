class Solution {
 
    
    public boolean searchMatrix(int[][] matrix, int target) {

    int row=0;
    int n =matrix.length;
    int m=matrix[0].length;
    int col=m-1;
    while(row< n && col>=0){
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]<target) row++;
        else  col--;
    }
    return false;
    }
}
