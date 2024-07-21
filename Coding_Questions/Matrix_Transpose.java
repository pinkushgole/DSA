package Coding_Questions;

public class Matrix_Transpose {

    public void transposeMatrix(int matrix[][]) {
        int[][] ans = new int[3][3];

        for (int k = 0; k < matrix.length; k++) {
            for (int j = 0; j < matrix[k].length; j++) {

                ans[k][j] = matrix[j][k];

            }
        }

        for (int i = 0; i < ans.length; i++) {
            for (int j = 0; j < ans[i].length; j++) {

                System.out.println(ans[i][j]);

            }
            System.out.println();
        }
    }

    public static void main(String aa[]) {

        int[][] matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

        Matrix_Transpose m = new Matrix_Transpose();
        m.transposeMatrix(matrix);
    }
}
