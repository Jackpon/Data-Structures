/*
1318: Nanae画画（2014年ACM校赛初赛）

题目描述
Nanae小的时候很喜欢画画，一天他的朋友然他画个矩形出来，给了矩形的宽和高了。
输入
输入包含多个测试数据，以判断输入到达文件为（EOF）终止程序。每个样例第一行输入两个整数，
分别为宽度(w)和高度(h),0<w,h<75; 

输出
每个输入一个样例，每个样例。画出矩形的宽度和高度。

样例输入
3 2
3 3
样例输出
+---+
|   |
|   |
+---+
+---+
|   |
|   |
|   |
+---+
*/
import java.util.Scanner;

public class Main {
	public static void out(){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			int w = in.nextInt();
			int h = in.nextInt();
			//
			for (int i = 0; i < h+2; i++) {
				for (int j = 0; j < w+2; j++) {
					if((i==0 || i==h+1) &&(j==0 || j ==w+1)) {
						System.out.print("+");
					}
					else if ((i==0||i==h+1) && j!=0 && j !=w+1) {
						System.out.print("-");
					}
					else if (i!=0 && i!=h+1 &&(j==0 || j ==w+1)) {
						System.out.print("|");
					}
					else if (i!=0 && j!=0 && j !=w+1 && i!=h+1) {
						System.out.print(" ");
					}
					if (j==w+1) {
						System.out.println();
					}
				}
			}
		}
	}
	public static void main(String[] args){
		out();
	}
}