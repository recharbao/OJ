package PAT;

import java.util.Scanner;

public class WorldCupBetting {
    public static void main(String[] args) {
        String[] map = {"W","T","L"};
        double input[][] = new double[3][3];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                input[i][j] = sc.nextDouble();
            }
        }



        //注意MAX更迭
        //下面是错误解法:
        /*
        double max = -1;
        int maxIndex = 0;
        double result = 1;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (max < input[i][j]){
                    max = input[i][j];
                    maxIndex = j;
                }
            }
            result *= max;
            if (i == 0){
                System.out.print(map[maxIndex]);
            }else {
                System.out.print(" " + map[maxIndex]);
            }
        }
        System.out.print(" " + String.format("%.2f", (result * 0.65 - 1) * 2));
    }*/



        double result = 1;

        //注意MAX更迭

        for (int i = 0; i < 3; i++){
            int maxIndex = 0;
            for (int j = 0; j < 3; j++){
                if (input[i][maxIndex] < input[i][j]){
                    maxIndex = j;
                }
            }
            result *= input[i][maxIndex];
            if (i == 0){
                System.out.print(map[maxIndex]);
            }else {
                System.out.print(" " + map[maxIndex]);
            }
        }
        System.out.print(" " + String.format("%.2f", (result * 0.65 - 1) * 2));
    }

}
