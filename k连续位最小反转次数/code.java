package leetcode;

public class Main5 {
    public int minKBitFlips(int[] A, int K){
        int ans = 0;
        int i = 0;
        for (; i <= A.length - K; i++){
            if (A[i] != 1){
                ans++;
                for (int j = i; j < i + K; j++){
                    A[j] = A[j] ^ 1;
                }
            }
        }
        for (; i < A.length; i++){
            if (A[i] == 0){
                return -1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] A = {};
        int K = 3;
        int result = new Main5().minKBitFlips(A,K);
        System.out.println(result);
    }
}

