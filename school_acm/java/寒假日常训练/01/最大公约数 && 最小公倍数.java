//最大公约数 && 最小公倍数
import java.util.Scanner;

public class Main {
	//最大公约数(辗转相除法)
	static int maxnum(int a,int b) {
		if(a%b==0)
			return b;
		else 
			return maxnum(b, a%b);
	}
	//最小公倍数=a*b/maxnum;
	static int minnum(int a,int b) {
		return a*b/maxnum(a, b)	;
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			int a = in.nextInt();
			int b = in.nextInt();
			System.out.println(minnum(a, b));
		}
	}
}