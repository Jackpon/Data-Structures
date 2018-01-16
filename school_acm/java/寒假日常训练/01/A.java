A - 基础题
Contest time again! How excited it is to see balloons floating around. But to tell you a secret, 
the judges favorite time is guessing the most popular problem. When the contest is over, 
they will count the balloons of each color and find the result.
This year, they decide to leave this lovely job to you. 

Input
Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- 
the total number of balloons distributed. The next N lines contain one color each.
 The color of a balloon is a string of up to 15 lower-case letters. 
A test case with N = 0 terminates the input and this test case is not to be processed. 

Output
For each case, print the color of balloon for the most popular problem on a single line. 
It is guaranteed that there is a unique solution for each test case. 

Sample Input
5
green
red
blue
red
red
3
pink
orange
pink
0

Sample Output
red
pink

//

import java.util.HashSet;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			int n = in.nextInt();
			if(n > 0 && n <1001) {
				String s[] = new String[n];
				for (int i = 0; i < n; i++) 
					s[i]=in.next();
				
				//放到set是元素不重复,然后转换为数组
				HashSet<String> set = new HashSet<>();
				for (int i = 0; i < n; i++) 
					set.add(s[i]);
				
				String a[] = new String[set.size()];
				set.toArray(a);
				//
				int count=0,sum=0;
				String string = null;
				for (int i = 0; i < a.length; i++) {
					for (int j = 0; j < n; j++) 
						if(a[i].equals(s[j]))
							count++;
					
					if(count > sum) {
						sum = count;
						string=a[i];
					}
					count=0;
				}
			System.out.println(string);
			}
		}
	}
}

