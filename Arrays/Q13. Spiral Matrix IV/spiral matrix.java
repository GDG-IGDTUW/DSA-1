import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Integer> head = Arrays.asList(3, 0, 2, 4, 5, 3, 2, 1);
        int[][] matrix = generateSpiralMatrix(n,m,head);
        printMatrix(matrix);

    }
    public static void printMatrix(int[][] matrix){
        for(int i = 0; i<matrix.length; i++){
            for(int j = 0; j<matrix[i].length;j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static int[][] generateSpiralMatrix(int n,int m,List<Integer> head){
        int matrix[][]=new int[n][m];
        int startRow = 0;
        int l = head.size();
        int endRow = n-1;
        int startCol = 0;
        int endCol = m-1;
        int val = 1;
        int z = 0;
        while(startRow<=endRow && startCol <= endCol){
            for(int j = startCol; j<=endCol; j++){
                if(z<l){
                    matrix[startRow][j]=head.get(z);
                }else{
                    matrix[startRow][j]= -1;
                }
                z++;
            }
            startRow++;
            for(int i = startRow; i<=endRow; i++){
                if(z<l){
                    matrix[i][endCol]=head.get(z);
                }else{
                    matrix[i][endCol]= -1;
                }
                z++;
            }
            endCol -= 1;
            if(startRow <= endRow){
                for(int j = endCol; j>=startCol;j--){
                    if(z<l){
                        matrix[endRow][j]=head.get(z);
                    }else{
                        matrix[endRow][j]= -1;
                    }
                    z++;
                }
                endRow -= 1;
            }
            if(startCol<=endCol){
                for(int i = endRow; i>=startRow; i--){
                    if(z<l){
                        matrix[i][startCol]=head.get(z);
                    }else{
                        matrix[i][startCol]= -1;
                    }
                    z++;
                }
                startCol++;
            }
        }
        return matrix;

    }
}

