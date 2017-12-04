/*
1056: 分解质因数

问题描述 

　　求出区间[a,b]中所有整数的质因数分解。 

输入格式 

　　输入两个整数a，b。 

输出格式 

　　每行输出一个数的分解，形如k=a1*a2*a3...(a1< =a2< =a3...，k也是从小到大的)(具体可看样例) 

样例输入 

3  10 

样例输出 

3=3 

4=2*2 

5=5 

6=2*3 

7=7 

8=2*2*2 

9=3*3 

10=2*5 

提示 

　　先筛出所有素数，然后再分解。 

数据规模和约定 

　　2< =a< =b< =10000 
*/
import java.util.Scanner;

public class Main {
	public static void out(int n) {
		System.out.print(n+"=");
		int n2=n;
	    for(int i = 2;i*i<=n2;i++)       
	    {        
	        while(n2%i==0)
	        {
	        	System.out.print(i);
	            n2=n2/i;
	            if(n2!=1)
	            	System.out.print("*");
	        }
	    }
	   
	    if(n2 != 1)   System.out.print(n2);      //当n为质数
	    
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a,b;
		while(in.hasNext()) {
			a = in.nextInt();
			b = in.nextInt();
			for (; a <= b; a++) {
				out(a);
				System.out.println();
			}		
		}
	}
}