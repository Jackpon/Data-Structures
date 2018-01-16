/*
1098: 单词个数统计

      
问题描述 
　　编写一个程序，输入一个字符串（长度不超过80），然后统计出该字符串当中包含有多少个单词。例如：字符串“this  is  a  book”当中包含有4个单词。 
　　输入格式：输入一个字符串，由若干个单词组成，单词之间用一个空格隔开。 
　　输出格式：输出一个整数，即单词的个数。 
　　输入输出样例 
　　用户输入数据样例： 
　　this  is  a  book 
　　系统输出数据如下： 
　　4 
*/

import java.util.Scanner;

public class Main {

	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in); 
		String a;
		while(in.hasNext()) {
			a=in.nextLine();
			char sum[] = a.toCharArray();
			int count=1;
			for (int i = 0; i < sum.length; i++) 
				if(sum[i]==' ')
					count++;
			System.out.println(count);
		}
	}

}