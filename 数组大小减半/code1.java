
//others
class Solution {
    public int minSetSize(int[] arr) {
        int[] a = new int[100001];
        int len = arr.length;
        for (int value : arr) {
            //记录每个元素的数量
            a[value]++;
        }
        int[] b = new int[100001];
        int maxindex=0;

        for (int i=1;i<=100000;i++) {
            if(a[i] > 0) {
                maxindex = Math.max(maxindex, a[i]);
                //记录在这个数量上出现的次数，或者说是在这个数量上的元素种类数
                b[a[i]]++;
            }
        }

        
        //记录所要集合个数
        int res = 0;
        //记录所使用集合能收容的元素个数
        int res2 = 0;
        //一半
        final int limit = len>>1;
        while(res2<=limit) {
            //跳格
            while (maxindex>1 && b[maxindex]==0) {
                System.out.println(maxindex);
                maxindex = maxindex -1;
            }
            //记录在这个数量上出现的次数，或者说是在这个数量上的元素种类数
            int time = b[maxindex];
            int val = maxindex;
            //(记录所使用集合不能收容的元素个数)除以这个数量上的出现次数
            //其实，下面到if结束就是说新加入的集合元素是否等于足够表示这些未收容的元素
            int count = (limit - res2)/val;
            //恰好可以表示
            boolean dok = (limit - res2) % val==0;
            //
            if(count < time || (count==time && dok)) {
                //若恰好可以表示，则加0，否则，再加一个等于该数量的元素，及等于目前maxindex的元素
                res += count + (dok?0:1);
                break;
            }
            //加入元素，用来衡量过半的进度
            res2 += maxindex * time;
            //集合元素
            res += time;
            //移步（探寻）下一个最大值
            maxindex = maxindex -1;
        }
        return res;
    }
}







