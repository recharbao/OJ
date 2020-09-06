package leetcode;

import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

public class Main3 {
    //贪心
    /*
    public int minSwapsCouples(int[] row) {
        if (row.length <= 2){
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < row.length - 1; i += 2){
            for (int j = i + 1; j < row.length; j++){
                if ((row[i] ^ 1) == row[j]){
                    System.out.println("i = " + i + " j = " + j + " and row = " + row[j]);
                    if (j != i + 1){
                        int tmp = row[j];
                        row[j] = row[i + 1];
                        row[i + 1] = tmp;
                        ans++;
                    }
                    break;
                }
            }
        }

        return ans;
    }*/


    //贪心改进方法,加上map:
    public int minSwapsCouples(int[] row) {

        int n = row.length;

        if (n <= 2){
            return 0;
        }

        int indexArr[] = new int[n];
        //映射
        for (int i = 0; i < n; i++){
            indexArr[row[i]] = i;
        }

        int ans = 0;

        for (int i = 0; i < n; i += 2){
            if ((row[i] ^ 1) != row[i + 1]){
                //修改map
                int frIndex = indexArr[row[i] ^ 1];
                indexArr[row[i + 1]] = frIndex;
                indexArr[row[i] ^ 1] = i + 1;
                //交换位置
                int tmp = row[frIndex];
                row[frIndex] = row[i + 1];
                row[i + 1] = tmp;
                ans++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] row = {0,2,4,6,7,1,3,5};
        int result = new Main3().minSwapsCouples(row);
        System.out.println(result);
    }
}

