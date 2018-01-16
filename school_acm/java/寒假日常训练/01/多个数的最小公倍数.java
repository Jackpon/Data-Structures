D - 基础题

The least common multiple (LCM) of a set of positive integers is the smallest positive integer which is divisible by all the numbers in the set. For example, the LCM of 5, 7 and 15 is 105. 

Input
Input will consist of multiple problem instances. The first line of the input will contain a single integer indicating the number of problem instances. Each instance will consist of a single line of the form m n1 n2 n3 ... nm where m is the number of integers in the set and n1 ... nm are the integers. All integers will be positive and lie within the range of a 32-bit integer. 
Output
For each problem instance, output a single line containing the corresponding LCM. All results will lie in the range of a 32-bit integer. 
Sample Input
2
3 5 7 15
6 4 10296 936 1287 792 1
Sample Output
105
10296
//
import java.util.Scanner;

public class Main {
	//最大公约数(辗转相除法)
	static long maxnum(long a,long b) {
		if(a%b==0)
			return b;
		else 
			return maxnum(b, a%b);
	}
	//最小公倍数=a*b/maxnum;
//	static int minnum(int a,int b) {
//		return a*b/maxnum(a, b)	;
//	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			int n = in.nextInt();
			for (int i = 0; i < n; i++) {
				int z = in.nextInt();
				long m,ans=1;
				for (int j = 0; j< z; j++) {
					m=in.nextInt();
					ans= ans*m/maxnum(ans, m);
				}
				System.out.println(ans);
			}
		}
	}
}