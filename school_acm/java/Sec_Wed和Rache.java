/*
1319: Sec_Wed和Rache（2014年ACM校赛初赛）

题目描述

Rache他突然间想经商，他收购一些货物，每件货物都有价值和保质期，每天可以卖一件货物，做为ACMer的他，要做出一个程序出来，算出他这些货物卖出的最大价值的啦。

         其中pi为货物的价值，di为货物的保质期。

         比如Rache拥有货物=={a,b,c,d}，和(pa,da)=(50,2), (pb,db)=(10,1), (pc,dc)=(20,2), and (pd,dd)=(30,1)，如图所以是这些货物所有可能的出售计划，货物b和d都是一天，所以Rache只能第一天卖d货物，然后第二天只能选取a货物，所以Rache得到80元。




输入
输入包含多个测试数据，以判断输入到达文件为（EOF）终止程序。第一行输入0 <= n <= 10000（表示有N件货物），紧接着是货物的价值和这货物的保质期。1 <= pi <= 10000 and 1 <= di <= 10000。

输出
每个样例输出一行，输出最大获得利润值。
样例输入
4  50 2  10 1   20 2   30 1
7  20 1   2 1   10 3  100 2   8 2 5 20  50 10
样例输出
80
185
#思路：
	货物保质期越小优先级越高，同等级下，
	取货物价值最高的，直至遍历完就是最大价值
*/
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void out(){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			int n = in.nextInt();
			int [][]num = new int[n][2];
			int di[] = new int[n];
			int k=0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 2; j++) {
					num[i][j] = in.nextInt();
					if (j==1) {
						di[k++] = num[i][j];
					}
				}
			}
		//
			Arrays.sort(di);
			int temp=0,sum=0,value=0;
			for (int i = 0; i < di.length; i++) {
				if(di[i] <= temp) {
					continue;
				}
				temp = di[i];
				for (int j = 0; j < n; j++) {
					if(num[j][1]==temp && num[j][0]>value) {
						value = num[j][0];
					}
				}
				sum+=value;
				value=0;
			}
		System.out.println(sum);
		}
	}
	public static void main(String[] args){
		out();
	}
}