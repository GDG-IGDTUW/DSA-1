class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> order=new ArrayList<>();
        int r=matrix.length;
        int c=matrix[0].length;

        int tr=0, br=r-1, lc=0, rc=c-1;
        int totalElements=0;

        while(totalElements<r*c){
            for(int i=tr;i<=rc && totalElements<r*c;i++){
                order.add(matrix[tr][i]);
                totalElements++;
            
            
        }
        tr++;

         for(int j=tr;j<=br  && totalElements<r*c;j++){
                order.add(matrix[j][rc]);
                totalElements++;
            
            
        }
        rc--;
         for(int i=rc;i>=lc  && totalElements<r*c;i--){
                order.add(matrix[br][i]);
                totalElements++;
            
            
        }
        br--;
         for(int i=br;i>=tr  && totalElements<r*c;i--){
                order.add(matrix[i][lc]);
                totalElements++;
            
            
        }
        lc++;


    }
    return order;
    }
}
