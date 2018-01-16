/*
日子计算问题（2013年校赛决赛）

题目描述
计算两个日期间（格式：y年m月d日）相隔了多少天.

输入
输入包含多组测试数据，以判断输入到达文件尾（EOF）终止程序。

每个测试样例包含6个整数:y1,m1,d1,y2,m2,d2。分别表示两个日期的年月日( 0 < y1,y2 <= 10^9)，每个整数间以空格隔开。输入保证每个日期都是有效。

输出
对每个测试样例，输出其相应的答案。

样例输入
2005 12 1 2005 12 2
2005 12 1 2005 12 31
2004 1 1 2004 3 1
2003 1 1 2003 3 1
2001 1 1 2001 1 1
样例输出
1
30
60
59
0
*/
//使用内置函数，但是时间超时
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class Main {
	public static void out() throws ParseException {
		Scanner in = new Scanner(System.in);
		int d[][] = new int[2][3];
		while(in.hasNext()) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
					d[i][j] = in.nextInt();
				}
			}
			//格式化日期
			String idate[] = {"",""};
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 3; j++) {
					idate[i] += Integer.toString(d[i][j]);
					if(j != 2)
						idate[i] += "-";
				}
				
			}
			//
			SimpleDateFormat myFormat = new SimpleDateFormat("yyyy-MM-dd"); 
			java.util.Date date = null;
			java.util.Date mydate = null;
			date= myFormat.parse(idate[0]);
			mydate = myFormat.parse(idate[1]);
			long day = (mydate.getTime() - date.getTime()) / (24 * 60 * 60 * 1000);   
			System.out.println(day); 
		}
	}
	public static void main(String[] args) throws ParseException {
		out();
	}
}