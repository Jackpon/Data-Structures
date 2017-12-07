/*
1300: 错误票据

问题描述 
某涉密单位下发了某种票据，并要在年终全部收回。 
每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。 
因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。 
你的任务是通过编程，找出断号的ID和重号的ID。 
假设断号不可能发生在最大和最小号。 
输入格式 
要求程序首先输入一个整数N(N< 100)表示后面数据行数。 
接着读入N行数据。 
每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000），请注意行内和行末可能有多余的空格，你的程序需要能处理这些空格。 
每个整数代表一个ID号。 
输出格式 
要求程序输出1行，含两个整数m  n，用空格分隔。 
其中，m表示断号ID，n表示重号ID 
样例输入1 
2 
5  6  8  11  9  
10  12  9 
样例输出1 
7  9 
样例输入2 
6 
164  178  108  109  180  155  141  159  104  182  179  118  137  184  115  124  125  129  168  196 
172  189  127  107  112  192  103  131  133  169  158  
128  102  110  148  139  157  140  195  197 
185  152  135  106  123  173  122  136  174  191  145  116  151  143  175  120  161  134  162  190 
149  138  142  146  199  126  165  156  153  193  144  166  170  121  171  132  101  194  187  188 
113  130  176  154  177  120  117  150  114  183  186  181  100  163  160  167  147  198  111  119 
样例输出2 
105  120 
*/
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void out() {
		Scanner in = new Scanner(System.in);
		int n;
		while(in.hasNext()) {
			n = in.nextInt();
			String fuck = in.nextLine();//解决n后的 /r
			String []s = new String[n];
			for (int i = 0; i < n; i++) 
				s[i] = in.nextLine();
			
			//
			int num[] = new int[10000];
			int k=0;
			for (int i = 0; i < s.length; i++) {
				String []arr = s[i].split("\\s+");
				for (int j = 0; j < arr.length; j++) 
					num[k++] = Integer.parseInt(arr[j]+"");
				
			}
			Arrays.sort(num, 0, k);
			int mn[] = new int[2];
			for (int i = 1; i < k; i++) {
				if(num[i] != num[i-1]+1 && num[i] != num[i-1])
					mn[0] = num[i-1]+1;
				if (num[i] == num[i-1]) 
					mn[1] = num[i];
			}
			System.out.println(mn[0]+" "+mn[1]);
		}
	}
	public static void main(String[] args) {
		out();
	}
}

//下面是c++实现方式
#include<iostream>
#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<string>
//#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    while(cin>>n){
       int num[100*n];
       int value,k=0;
      while(scanf("%d",&value)!=EOF)
        {
         num[k++]=value;
        }
        sort(num,num+k);
        int mn[2];
      for(int i=1;i<k;++i){
        if(num[i] != num[i-1]+1 && num[i] != num[i-1])
                mn[0] = num[i-1]+1;
        if (num[i] == num[i-1])
                mn[1] = num[i];
      }
        cout<<mn[0]<<" "<<mn[1]<<endl;
    }
    return 0;
}
