package leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Main2 {
    public int[][] dicts = {{1,0},{-1,0},{0,1},{0,-1}};
    public int m,n;
    public int longestIncreasingPath(int[][] matrix) {
        m = matrix.length;
        if (m == 0){
            return 0;
        }
        n = matrix[0].length;
        //定义出度
        int outDegree[][] = new int[m][n];
        //首先计算每个点的出度
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                //尝试四个方向移动
                for (int[] dict : dicts){
                    int newRow = i + dict[0];
                    int newColum = j + dict[1];
                    if (newRow >= 0 && newColum >= 0 && newRow < m && newColum < n && matrix[newRow][newColum] > matrix[i][j]){
                        outDegree[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                System.out.print(outDegree[i][j] + " ");
            }
            System.out.println();
        }

        Queue<int[]> queue = new LinkedList<>();

        //查看所有出度为0的节点
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (outDegree[i][j] == 0){
                    queue.offer(new int[]{i,j});
                }
            }
        }

        int ans = 0;
        while (!queue.isEmpty()){
            ans++;
            int size = queue.size();
            for (int i = 0; i < size; i++){
                int[] tp = queue.poll();
                //往四个方向走
                for (int[] dict : dicts){
                    int newRow = tp[0] + dict[0];
                    int newColum = tp[1] + dict[1];

                    if (newRow >= 0 && newColum >= 0 && newRow < m && newColum < n && matrix[newRow][newColum] < matrix[tp[0]][tp[1]]){
                        outDegree[newRow][newColum]--;
                        if (outDegree[newRow][newColum] == 0){
                            queue.offer(new int[]{newRow , newColum});
                        }
                    }
                }
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int[][] matrix = {
                {2,12, 8, 9},
                {4, 3,11,10},
                {6,10, 7, 9},
                {7, 4, 5, 6}
        };
        int result = new Main2().longestIncreasingPath(matrix);
        System.out.println(result);
    }
}

