/*
1303: 计算N！

题目描述
向计算机中输入N(0<=N<=10^6) ,并计算其阶乘：

N! = 1*2*3*...*N

因为答案可能会很大，所以只要求输出N！求余10000007的值。
输入
输入包含多个测试数据，以判断输入到达文件为（EOF）终止程序。每个样例会输入一个N。

输出
每输入一个样例，程序立即输出该样例的答案，每个输出占一行。
样例输入
5
2001
120
样例输出
120
6479726
3702033
*/
import java.util.Scanner;

public class Main {
	public static void out(){
		Scanner in = new Scanner(System.in);
		int n;
		while(in.hasNext()) {
			n = in.nextInt();
			long sum=1;
			for (int i = 2; i <= n; i++) {
				sum = sum*i%10000007;
			}
			System.out.println(sum);
		}
	}
	public static void main(String[] args){
		out();
	}
}