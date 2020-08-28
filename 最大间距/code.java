package leetcode;
/*
import java.util.Arrays;

public class Solution2 {
    public int maximumGap(int[] nums){
        if (nums.length < 2){
            return 0;
        }
        Arrays.sort(nums);
        int max = -1;
        for (int i = 1; i < nums.length; i++){
            if (max < nums[i] - nums[i - 1]){
                max = nums[i] - nums[i - 1];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] nums = {3,6,9,1};
        int result = new Solution2().maximumGap(nums);
        System.out.println(result);
    }
}*/

import java.util.ArrayList;

import java.util.List;

//法二，抽屉原理

class basket{
    boolean used = false;
    int Max = -999999999;
    int Min = 999999999;
}

public class Solution2 {
    public int maximumGap(int[] nums){
        if (nums.length < 2){
            return 0;
        }
        int Max = -99999999;
        int Min = 99999999;
        for (int i = 0; i < nums.length; i++){
            if (Max < nums[i]){
                Max = nums[i];
            }
        }

        for (int i = 0; i < nums.length; i++){
            if (Min > nums[i]){
                Min = nums[i];
            }
        }

        int basketSize = Math.max((Max - Min) / (nums.length - 1),1);
        int basketNums = (Max - Min) / basketSize + 1;

        List<basket> basketArr = new ArrayList<>();
        for (int i = 0; i < basketNums; i++){
            basketArr.add(new basket());
        }

        for (int i = 0; i < nums.length; i ++){
            int basketId = (nums[i] - Min) / basketSize;

            basketArr.get(basketId).used = true;
            basketArr.get(basketId).Max = Math.max(basketArr.get(basketId).Max,nums[i]);
            basketArr.get(basketId).Min = Math.min(basketArr.get(basketId).Min,nums[i]);
        }

        int preBasketMax = Min;
        int maxGloble = 0;
        for (int i = 0; i < basketArr.size(); i++){
            if (!basketArr.get(i).used){
                continue;
            }

            maxGloble = Math.max(maxGloble, basketArr.get(i).Min - preBasketMax);
            preBasketMax = basketArr.get(i).Max;
        }

        return maxGloble;
    }

    public static void main(String[] args) {
        int[] nums = {3,6,9,1};
        int result = new Solution2().maximumGap(nums);
        System.out.println("result = " + result);
    }
}
