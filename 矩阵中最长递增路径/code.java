package leetcode;


import java.awt.*;

/**
 * 思路不正的的解法：
 *
 */
/*
public class Main1 {
    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length;
        if (m == 0){
            return 0;
        }
        int n = matrix[0].length;
        int[][][] dp = new int[m][n][2]; //0增长，1下降
        int max = 1;

        //dp[0][0][0] = 1;
        //dp[0][0][1] = 1;

        int count = 0;
        while (count++ < 2){
            //第二次要反转
            if (count == 2){
                int tmp = 0;
                for (int i = 0; i <= m / 2; i++){
                    for (int j = 0; j <= n / 2; j++){
                        //对角反转
                        tmp = matrix[i][j];
                        matrix[i][j] = matrix[m - 1 - i][n - 1 - j];
                        matrix[m - 1 - i][n - 1 - j] = tmp;
                        //斜对角反转
                        if (i != m / 2 && j != n / 2){
                            tmp = matrix[m - 1 - i][j];
                            matrix[m - 1 - i][j] = matrix[i][n - 1 - j];
                            matrix[i][n - 1 - j] = tmp;
                        }
                    }
                }
            }

            System.out.println("times ： " + count);

            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    System.out.print(matrix[i][j] + " ");
                }
                System.out.println();
            }


            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    dp[i][j][0] = 1;
                    dp[i][j][1] = 1;
                }
            }

            //由上到下
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    if (i == 0 && j == 0){
                        continue;
                    }
                    else if (i == 0 && j != 0){
                        if (matrix[i][j] > matrix[i][j - 1]) {
                            dp[i][j][0] = 1 + dp[i][j - 1][0];
                            max = Math.max(dp[i][j][0],max);
                        }else if (matrix[i][j] < matrix[i][j - 1]){
                            dp[i][j][1] = 1 + dp[i][j - 1][1];
                            max = Math.max(dp[i][j][1],max);
                        }
                    }
                    else if (i != 0){
                        if (matrix[i][j] > matrix[i - 1][j]){
                            if (j == 0){
                                dp[i][j][0] = 1 + dp[i - 1][j][0];
                            }
                            else if (matrix[i][j] > matrix[i][j - 1]){
                                dp[i][j][0] = 1 + Math.max(dp[i - 1][j][0],dp[i][j - 1][0]);
                                max = Math.max(max,dp[i][j][0]);
                            }else if (matrix[i][j] < matrix[i][j - 1]){
                                max = Math.max(max,dp[i - 1][j][0] + dp[i][j - 1][1] + 1);
                                dp[i][j][0] = dp[i - 1][j][0] + 1;
                                dp[i][j][1] = dp[i][j - 1][1] + 1;
                            }

                        }else if (matrix[i][j] < matrix[i - 1][j]){
                            if (j == 0){
                                dp[i][j][1] = 1 + dp[i - 1][j][1];
                            }
                            else if (matrix[i][j] < matrix[i][j - 1]){
                                dp[i][j][1] = 1 + Math.max(dp[i - 1][j][1],dp[i][j - 1][1]);
                                max = Math.max(max,dp[i][j][1]);
                            }else if (matrix[i][j] > matrix[i][j - 1]){
                                max = Math.max(max, dp[i - 1][j][1] + dp[i][j - 1][0] + 1);
                                dp[i][j][0] = dp[i][j - 1][0] + 1;
                                dp[i][j][1] = dp[i - 1][j][1] + 1;
                            }
                        }
                    }
                }

            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                System.out.print(dp[i][j][0] + "" + dp[i][j][1] + " ");
            }
            System.out.println();
        }

        return max;
    }

    public static void main(String[] args) {

        /*int[][] matrix = {
                {9,9,4},
                {6,6,8},
                {2,1,1}
        };*/
        /*int[][] matrix = {
                {9}
        };*/
        /*int[][] matrix = {
                {7,7,5},
                {2,4,6},
                {8,2,0}
        };*/
        /*int[][] matrix = {
                {7,8,9},
                {9,7,6},
                {7,2,3}
        };*/

        /*int[][] matrix = {
                {7,8,9},
                {9,7,6},
                {7,2,3}
        };*/
       /* int[][] matrix = {
                {6,7,9},
                {5,4,1},
                {7,3,2}
        };


        /*int[][] matrix = {
                {3,4,5},
                {3,2,6},
                {2,2,1}
        };*/

        /*int result = new Main1().longestIncreasingPath(matrix);
        System.out.println("result = " + result);
    }
}
*/


public class Main1{
    //控制方向
    public int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    public int m,n;
    public int longestIncreasingPath(int[][] matrix) {
        m = matrix.length;
        if (m == 0){
            return 0;
        }
        n = matrix[0].length;
        int[][] memo = new int[m][n];
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans = Math.max(ans,memory_dfs(matrix,i,j,memo));
            }
        }
        return ans;
    }
    public int memory_dfs(int[][] matrix, int row, int colum, int[][] memo){
        if (memo[row][colum] != 0){
            return memo[row][colum];
        }

        memo[row][colum] ++;

        for (int[] dir : dirs){
            int newRow = row + dir[0];
            int newColum = colum + dir[1];
            if (newRow >=0 && newRow < m && newColum >=0 && newColum < n && matrix[newRow][newColum] < matrix[row][colum]){
                memo[row][colum] = Math.max(memo[row][colum],1 + memory_dfs(matrix,newRow,newColum,memo));
            }
        }
        return memo[row][colum];
    }

    public static void main(String[] args) {

        int[][] matrix = {
                {3,4,5},
                {3,2,6},
                {2,2,1}
        };

        int result = new Main1().longestIncreasingPath(matrix);
        System.out.println(result);
    }
}

