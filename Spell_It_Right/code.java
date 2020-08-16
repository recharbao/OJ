package PAT;

import java.util.Scanner;
import java.util.Stack;

public class Spell_It_Right {
    public static void main(String[] args) {
        String[] word = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        int result = 0;

        for (int i = 0; i < input.length(); i++) {
            String tmp = "";
            tmp += input.charAt(i);
            result += Integer.parseInt(tmp);
        }

        /*
        for (int i = 0; i < input.length(); i++) {
            result += Integer.parseInt(input.substring(i,i + 1));
        }*/


        Stack<Integer> st = new Stack<Integer>();
        if(result == 0){
            System.out.print(word[0]);
        }else{
            while (result != 0){
                int tmp = result % 10;
                result /= 10;
                st.push(tmp);
            }
            System.out.print(word[st.pop()]);
            while (!st.empty()){
                System.out.print(" " + word[st.pop()]);
            }
        }


    /*
        String sum = "" + result;
        for (int i = 0; i < sum.length(); i++) {
            int j = Integer.parseInt(sum.substring(i, i + 1));
            if (i == 0) {
                System.out.print(word[j]);
            } else {
                System.out.print(" " + word[j]);
            }
        }*/
    }
}
