
import java.util.*;

public class _1_A {
    public long GoodSub(int[] matrix){
        //前缀和p_x
        //p_(r) - p_(l-1) = r - l + 1 = r - (l - 1);
        //p_r - p_(k) = r - (k);
        //p_r - r = p_(k) - (k);
        //即寻找 p_r - r = p_(k) - (k)的数量;

        int n = matrix.length;

        long[] preSum = new long[n + 1];

        long ans = 0;

        Map<Long,Long> map = new HashMap<>();

        for (int i = 1; i <= n; i++){
            preSum[i] = preSum[i - 1] + matrix[i - 1];
        }
        

        /*
        for (int r = 1; r <= n; r++){
            for (int k = r - 1; k >= 0; k--){
                if (preSum[r] - r == preSum[k] - k){
                    //System.out.println("r = " + r);
                    //System.out.println("k = " + k);
                    ans++;
                }
            }
        }*/

        //利用map改进
        for (int r = 0; r <= n; r++){
            long valueIndex = preSum[r] - r;
            if (map.get(valueIndex) == null){
                map.put(valueIndex, 1l);
            }else {
                long num = map.get(valueIndex);
                map.put(valueIndex, num + 1);
                ans += num;
            }
        }
        
        return ans;
    }


    public static void main(String[] args) {

        List<Long> ans = new ArrayList<>();
        
        _1_A a = new _1_A();

        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int i = 0;
        while (i++ < num){
            int size = sc.nextInt();
            String l = sc.next();
            int[] matrix = new int[size];
            int j = 0;
            while (j < size){
                matrix[j] = Integer.parseInt(l.substring(j,j + 1));
                j++;
            }
            long result = a.GoodSub(matrix);
            ans.add(result);
        }

        for (int k = 0; k < ans.size(); k++){
            System.out.println(ans.get(k));
        }
    }
}

