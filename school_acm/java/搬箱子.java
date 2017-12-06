/*
1307: 搬箱子

题目描述
搬运公司要将一堆纸皮箱子从XXX公司的楼低搬到楼上，但是搬箱子的人手有限，一个人同时只能拿一个箱子。但Sec想到了一个办法，让他们把小箱子装到大箱子里面，即体积小箱子能装到体积大的箱子中（体积相同不能互装），这样就能节省很多人手。例：有三个箱子体积分别是1,2,3，这样就可以把体积1的箱子装到体积2的箱子中，再让体积2的箱子装到体积3的箱子中，这样只用一个人就能把体积3的箱子搬上去，就可以把所有箱子搬上去了。

现在给出n个箱子和每个箱子的体积，问至少要多少个人才能把所有箱子搬上去？

输入
输入包含多组测试样例，以判断输入到达文件尾（EOF）终止程序。

每个测试样例第一行输入一个整数n ( 0 < n <= 10^3 )，接下来第二行包含n个整数xi (0< xi <= 10^3)

输出
对于每个输入样例，立刻输出他对应的答案。输出占一行，只包含一个整数m，即搬箱子需要的最少人数。

样例输入
5
1 2 3 1 2
6
1 4 5 6 2 3
5
1 1 1 1 1
样例输出
2
1
5
*/
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void out(){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			int n = in.nextInt();
			int num[] = new int[n];
			for (int i = 0; i < n; i++)
				num[i] = in.nextInt();
			//开始
			int temp;
			int len = 0,count=0;
			while(len < n) {
				Arrays.sort(num);
//找到第一个非零元素，并将其赋予temp以及设为0
				if (num[len]==0) {
					len++;
					continue;
				}
				temp = num[len];
				num[len] = 0;
//遍历后面大于第一个非零元素的值，设为0并更新temp
				for (int i = len+1; i < num.length; i++) {
					if (num[i] > temp) {
						temp = num[i];
						num[i]=0;
						len++;
					}
				}
	//每回合加一
			count++;
			}
			System.out.println(count);
		}
	}
	public static void main(String[] args){
		out();
	}
}