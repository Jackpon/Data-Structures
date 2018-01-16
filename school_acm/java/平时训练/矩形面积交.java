/*
1063: 矩形面积交

问题描述 

　　平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。对于每个矩形，
	我们给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积。 

输入格式 

　　输入仅包含两行，每行描述一个矩形。 

　　在每行中，给出矩形的一对相对顶点的坐标，每个点的坐标都用两个绝对值不超过10^7的实数表示。 

输出格式 

　　输出仅包含一个实数，为交的面积，保留到小数后两位。 

样例输入 

1  1  3  3 

2  2  4  4 

样例输出 

1.00 
*/
//oj运行错误，但我觉得是对的
import java.util.Scanner;

public class Main {
	
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int []a = new int[4];
		int []b = new int[4];
		while(in.hasNext()) {
			for (int i = 0; i < 4; i++) 
				a[i] = in.nextInt();
			for (int i = 0; i < 4; i++) 
				b[i] = in.nextInt();
			
			//求圆心
			double ay[] = new double[2];
			double by[] = new double[2];
			ay[0] = a[0]+(a[2]-a[0])/2;
			ay[1] = a[1]+(a[3]-a[1])/2;
			by[0] = b[0]+(b[2]-b[0])/2;
			by[1] = b[1]+(b[3]-b[1])/2;
			
			//求半径
			double ra=Math.sqrt(Math.pow(ay[1]-a[1],2 )+Math.pow(ay[0]-a[0], 2));
			double rb=Math.sqrt(Math.pow(by[1]-b[1],2 )+Math.pow(by[0]-b[0], 2));
			//两点距离(勾股定理)
			double l = Math.sqrt(Math.pow((by[1]-ay[1]), 2) + Math.pow((by[0]-ay[0]), 2));
			//判断
			double s=0;
			if (l <= rb-ra) //包含
				s = (a[3]-a[1])*(a[2]-a[0]);
				
			if(l<ra+rb && l>rb-ra) 
				s = (by[1]-ay[1])*(by[0]-ay[0]);
			
			System.out.printf("%.2f",s);
			System.out.println();
		}
	}
}
