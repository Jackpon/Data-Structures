/*
1065: 芯片测试

问题描述 

　　有n（2≤n≤20）块芯片，有好有坏，已知好芯片比坏芯片多。 

　　每个芯片都能用来测试其他芯片。用好芯片测试其他芯片时，能正确给出被测试芯片是好还是坏。而用坏芯片测试其他芯片时，会随机给出好或是坏的测试结果（即此结果与被测试芯片实际的好坏无关）。 

　　给出所有芯片的测试结果，问哪些芯片是好芯片。 

输入格式 

　　输入数据第一行为一个整数n，表示芯片个数。 

　　第二行到第n+1行为n*n的一张表，每行n个数据。表中的每个数据为0或1，在这n行中的第i行第j列（1≤i,  j≤n）的数据表示用第i块芯片测试第j块芯片时得到的测试结果，1表示好，0表示坏，i=j时一律为1（并不表示该芯片对本身的测试结果。芯片不能对本  身进行测试）。 

输出格式 

　　按从小到大的顺序输出所有好芯片的编号 

样例输入 

3 

1  0  1 

0  1  0 

1  0  1 

样例输出 

1  3 

#思路：
	if有芯片数据一致，则flag++，且flag>n/2,输出i
*/

import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		while(in.hasNext()) {
			n = in.nextInt();
			int a[][] = new int[n+1][n+1];
			
			for (int i = 1; i < a.length; i++) 
				for (int j = 1; j < a.length; j++) 
					a[i][j] = in.nextInt();
				
			//
			int flag,m;
			for(int i = 1;i <= n;i++)  
		    {  
		        flag = 0;  
		        for(int k = 1;k <= n;k++)  
		        {  
		            m = 0;  
		            for(int j = 1;j <= n;j++)  
		            {  
		                if(a[i][j] == a[k][j])  
		                    m++;  
		            }  
		            if(m == n)  
		                flag++;  
		        }  
		        if(flag > n/2)  
		            System.out.print(i+" "); 
		    }  


		    		/*	Set<Integer> set = new HashSet<>();
			for (int i = 0; i < a.length; i++) 
				for (int j = 0; j < a.length; j++) {
					if (i==j) 
						continue;
					if (a[i][j] == 1 && a[j][i]==1) 
						set.add(i);
				}
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a.length; j++) {
					if (i==j) 
						continue;
					if(a[i][j]==1 && set.contains(i))
						set.add(j);
				}
			}
			
			Integer []num = new Integer[set.size()];
			set.toArray(num);
			for (int i = 0; i < num.length; i++) 
				System.out.print(num[i]+1+" ");
			System.out.println();*/
		}
	}
}