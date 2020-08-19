package leetcode;

import java.util.*;

public class Solution {
    public int minSetSize(int[] arr) {
        int num = arr.length;
        double sum = 0.0;
        int times = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < arr.length; i++) {
            if (map.get(arr[i]) == null) {
                map.put(arr[i], 1);
            } else {
                int tmp = map.get(arr[i]);
                map.put(arr[i], ++tmp);
            }
        }
        List<List<Integer>> list = new ArrayList<List<Integer>>();

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            List<Integer> list1 = new ArrayList<>();
            list1.add(entry.getKey());
            list1.add(entry.getValue());
            list.add(list1);
        }

        Collections.sort(list, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> o1, List<Integer> o2) {
                return -o1.get(1).compareTo(o2.get(1));
            }
        });

        int result = 0;
        int removeCount = 0;

        for (int i = 0; i < list.size(); i++){
            if (removeCount >= arr.length / 2){
                return  result;
            }
            result++;
            removeCount += list.get(i).get(1);
        }
        return 0;
        /*
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for (int i = 0; i < arr.length; i++){
            if (map.get(arr[i]) == null){
                map.put(arr[i],1);
            }else {
                int tmp = map.get(arr[i]);
                map.put(arr[i],++tmp);
            }
        }

        while (!map.isEmpty()){
            int maxKey = 0;
            int Key = 0;
            for (Map.Entry<Integer,Integer> entry : map.entrySet()) {
                if (maxKey < entry.getValue()) {
                    maxKey = entry.getValue();
                    Key = entry.getKey();
                }
            }
            map.remove(Key);
            sum += maxKey;
            times++;
            if (num / sum <= 2){
                return times;
            }
        }
        return 0;
    }*/

    public static void main(String[] args) {
        int[] arr = {};
        Solution solution = new Solution();
        int result = solution.minSetSize(arr);
    }
}
