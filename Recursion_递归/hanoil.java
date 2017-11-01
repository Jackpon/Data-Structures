/*
汉诺塔问题

#思路：
		将n个盘分为‘n-1’和第一个两部分，第一个直接移动到‘z’即可，而
		‘n-1’这部分要先从‘x’通过‘z’移到到‘y’，再从‘y’->‘x’->‘z’
*/

public static int hanoil(int n,char x,char y,char z) {
	if (n == 1) 
		System.out.println(x+"->"+z);
	else {
		hanoil(n-1,x,z,y);
		System.out.println(x+"->"+z);
		hanoil(n-1, y, x, z);
	}
	return (int) (Math.pow(2, n)-1);
}