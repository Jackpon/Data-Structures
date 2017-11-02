/*
汉诺塔问题

#思路：
		将n个盘分为前‘n-1’和最后一个两部分，如果只有一个盘直接移动到‘z’即可，否则，
		先将前‘n-1’这部分从‘x’通过‘z’移到到‘y’，再将最后一个直接从‘x’->‘z’
		最后将前‘n-1’从‘y’->‘x’->‘z’
*/

public static int hanoil(int n,char x,char y,char z) {
	if (n == 1) // 只有一个盘子时，将其从X塔移动到Z塔
		System.out.println(x+"->"+z);
	else {
		//借助Z塔,将前n-1个盘子从X塔移动到Y塔
		hanoil(n-1,x,z,y);
		//将X塔上剩下的1个盘子移到Z塔
		System.out.println(x+"->"+z);
		//借助X塔,将前n-1个盘子从Y塔移动到Z塔
		hanoil(n-1, y, x, z);
	}
	return (int) (Math.pow(2, n)-1);
}