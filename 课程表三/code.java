package leetcode;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main4 {
    //错误的思路

    /*public int scheduleCourse(int[][] courses) {
        int nowTime = 0;
        int preOverIndex = -1;
        int ans = 0;
        int n = courses.length;
        int[] visited = new int[n];
        boolean flag = true;
        while (flag){
            flag = false;
            for (int i = 0; i < n; i++){
                if (visited[i] == 0 && nowTime + courses[i][0] <= courses[i][1]){
                    flag = true;
                    if (preOverIndex == -1){
                        preOverIndex = i;
                    }else {
                        if (courses[preOverIndex][1] > courses[i][1]){
                            preOverIndex = i;
                        }
                    }
                }
            }
            if (!flag){
                break;
            }
            ans++;
            nowTime += courses[preOverIndex][0];
            visited[preOverIndex] = 1;
            preOverIndex = -1;
        }
        return ans;
    }*/
    public int scheduleCourse(int[][] courses) {
        //排序
        /*Comparator<int[]> comparatorCourses = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] > o2[1]){
                    return 1;
                }else if (o1[1] < o2[1]){
                    return -1;
                }
                return 0;
            }
        };*/

        Comparator<int[]> comparatorCourses = (o1, o2) -> {
            if (o1[1] > o2[1]){
                return 1;
            }else if (o1[1] < o2[1]){
                return -1;
            }
            return 0;
        };

        Arrays.sort(courses, comparatorCourses);

        /*for (int i = 0; i < courses.length; i++){
            System.out.print("courses[" + i + "][" + 0 + "] = " + courses[i][0] + "  ");
            System.out.println("courses[" + i + "][" + 1 + "] = " + courses[i][1] + "  ");
        }*/

        Queue<Integer> queue = new PriorityQueue<>();

        int ans = 0;

        int nowTime = 0;

        for (int i = 0; i < courses.length; i++){
            queue.offer(-courses[i][0]);
            if (nowTime + courses[i][0] <= courses[i][1]){
                nowTime += courses[i][0];
                ans++;
            }else {
                int needTime = queue.poll() + courses[i][0];
                nowTime += needTime;
            }
        }

        return ans;

    }

    public static void main(String[] args) {
        int[][] courses = {{7,16},{2,3},{3,12},{3,14},{10,19},{10,16},{6,8},{6,11},{3,13},{6,16}};
        int result = new Main4().scheduleCourse(courses);
        System.out.println(result);
    }
}

