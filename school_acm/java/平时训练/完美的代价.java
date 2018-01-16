/*
1059: 完美的代价

问题描述 
	回文串，是一种特殊的字符串，它从左往右读和从右往左读是一样的。小龙龙认为回文串才是完美的。
	现在给你一个串，它不一定是回文的，请你计算最少的交换次数使得该串变成一个完美的回文串。 
	交换的定义是：交换两个相邻的字符 

　　例如mamad 

　　第一次交换  ad  :  mamda 

　　第二次交换  md  :  madma 

　　第三次交换  ma  :  madam  (回文！完美！) 

输入格式 

　　第一行是一个整数N，表示接下来的字符串的长度(N  < =  8000) 

　　第二行是一个字符串，长度为N.只包含小写字母 

输出格式 

　　如果可能，输出最少的交换次数。 

　　否则输出Impossible 

样例输入 
5 
mamad 

样例输出 
3 

#思路：
		分为单字符时要怎么处理，以及其他情况处理；
		单字符时：如果n%2==0则impossible，否则step += n/2 - i 
		偶数时：step += j-t;并移动元素
*/
import java.util.Scanner;

public class Main {
	public static int Num(char a[],int n) {
		//开始
		int t;  
	    int j=n-1;  
	    int flag=0,step=0;  
	    for(int i=0;i<j;i++){  
	        t=j;  
	        //查找匹配的字符   
	        while(a[i]!=a[t]) 
	            t--;  
	         
	        
	        if(i==t){   //如果为单个字符   
	            flag++;  
	            if(n%2==0||flag>1){  
	                System.out.println("Impossible");  
	                return 0;  
	            }  
	            step += n/2-i;  
	              
	            continue;   //如果不加该语句,则单个字符也会执行下面的if语句a[i]==a[t] && t==i   
	        }  
	        //如果找到相匹配的两个数   
	        if(i != t){  
	          
	            step+=j-t;  
	            char temp=a[t];  
	            for(int l=t;l<j  
	            ;l++){  
	                a[l]=a[l+1];  
	            }  
	            a[j]=temp;  
	            j--;  
	        }  
	    }     
	      
	   System.out.println(step);
	      
	    return 0;  
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		String s;
		while(in.hasNext()) {
			n=in.nextInt();
			s=in.next();
			char a[]=s.toCharArray();
			Num(a,n);
		}
	}
}