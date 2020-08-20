package PAT;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ReversiblePrimes {
    public boolean JudgePrime(int num){
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++){
            if (num % i == 0){
                return false;
            }
        }
        return true;
    }


    public int reverse(int num, int radix){
        String str = "";
        int result = 0;
        while (num > 0){
            str += num % radix;
            num /= radix;
        }

        for (int i = 0; i < str.length(); i++){
            result += Integer.parseInt(str.substring(i,i + 1)) * Math.pow(radix,str.length() - 1 - i);
        }
        return result;
    }


    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int a = 1;
        int b = 0;
        while (a > 0){
            a = sc.nextInt();
            if (a < 0){
                break;
            }
            b = sc.nextInt();
            list.add(a);
            list.add(b);
        }

        ReversiblePrimes rp = new ReversiblePrimes();
        for (int i = 0; i < list.size(); i += 2){
            int value = rp.reverse(list.get(i),list.get(i + 1));
            if (rp.JudgePrime(list.get(i)) && rp.JudgePrime(value)){
                System.out.println("Yes");
            }else {
                System.out.println("No");
            }
        }
    }
}
