/*
1308: 机器人（2013年校赛初赛）

题目描述
有一个机器人，他有两种前进方式，飞或者跑，如果是跑的话，一次能够跑a距离，飞的话一次能够飞b个距离。问，给出一段距离，他能够用多少种方式刚好到达？

输入
输入包含多组测试样例，以判断输入到达文件尾（EOF）终止程序。

每个测试样例第一行输入三个整数N ( 0 < N <= 10^6 )，a和b，（0<a,b）

输出
对于每个输入样例，立刻输出他对应的答案。输出占一行，只包含一个整数M，即完成这段路程有几种方式？由于结果可能过大，因此取余10000007。如果没有办法刚好达到，则输出0；

样例输入
1 1 2
6 2 3
5 3 4
样例输出
1
2
0
*/
//直接暴力枚举
import java.util.Scanner;

public class Main {
    public static void out(){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int n=in.nextInt();
            int a=in.nextInt();
            int b=in.nextInt();
            //
            int count=0;
            for (int i = 0; i < n/b+2; i++) {
                for (int j = 0; j < n/a+2; j++) {
                    if (a*j+i*b == n) {
                        count++;
                        count = count%10000007;
                    }
                }
            }
            System.out.println(count);
        }
    }
    public static void main(String[] args){
        out();
    }
}