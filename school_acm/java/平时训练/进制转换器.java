/*
1306: 进制转换器

题目描述
日常生活中，很多地方要用到进制转换。例如：我们读IP地址会把计算机中二进制的IP地址转成十进制；我们看某些变量的内存地址会把计算机中二进制的变量地址转换为十六进制。

现在要求你写一个进制转换器，可以使一个d进制的整数n，转为t进制的整数m。

十进制以上超过9的数字依次用大写字母A,B,C...代替。

输入
输入包含多个测试数据，以判断输入到达文件为（EOF）终止程序。

每个样例包含三个整数，分别为n,d,t(2<= d,t <=16, n是十进制形式不大于10^9的非负整数)，输入没有前导0。

输出
对每个输入样例，输出相应的答案m，每个输出占一行
样例输入
101 2 5
123 4 16
AB 16 10
样例输出
10
1B
171
*/
import java.util.Scanner;

public class Main {
	public static void out(){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			String n = in.next();
			int d = in.nextInt();
			int t = in.nextInt();
			char []num = n.toCharArray();
			int []inum = new int[num.length];
			//转换为int数组
			for (int i = 0; i < num.length; i++) {
				if (num[i] >= 'A') {
					inum[i] = (int)num[i]-55;
					continue;
				}
				inum[i] = Integer.parseInt(num[i]+"");
			}
			//开始操作,转换为10进制
			int k=0,sum=0;
			for (int i = inum.length-1; i >= 0 ; i--) {
				sum +=inum[i] * Math.pow(d, k++);
			}
			//转换为t进制
			System.out.println(Integer.toString(sum, t).toUpperCase());
		}
	}
	public static void main(String[] args){
		out();
	}
}