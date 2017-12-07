/*
注： ASCALL码 大写字母A-Z为65-90;小写字母a-z为97-122
1304: 简单密文

题目描述
Sec和Nanae在执行一个秘密任务，他们之间的通讯靠一些密文传输，原文与密文转换规则如下：

有一个键值d，和一个字符串(字符串中只包含字母,大小写均有),只要将原文中的每个字母都变为它们本身在字母表中位置再往后数第d个位置的字母，如：d=2时，A->C,B->D,...,X->Z,Y->A,Z->B。(如果往后数第d个字母位置已超出字母表，则回到A位置继续数。)现在要求你设计程序。帮他们把想传达的原文转换为密文进行传输。（转换后密文的字母与原文的字母大小写一致）

Input

输入包含多个测试数据，以判断输入到达文件为（EOF）终止程序。

每组数据包括一个字符串和键值d，（字符串长度不大于1000，0<=d<=10^9）字符串只包括大小写字母，不包括任何符号。

输入
输入包含多个测试数据，以判断输入到达文件为（EOF）终止程序。

每组数据包括一个字符串和键值d，（字符串长度不大于1000，0<=d<=10^9）字符串只包括大小写字母，不包括任何符号。

输出
对于每个输入样例要相应输出其答案，答案只包含密文字符串，一个答案占一行。

样例输入
ABCxyz 2
ABC 12
ABC 26
ABC 27
样例输出
CDEzab
MNO
ABC
BCD
*/

import java.util.Scanner;

public class Main {
	public static void out(){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			String s = in.next();
			int d = in.nextInt();
			char num[] = s.toCharArray();
			d = d%26;
			for (int i = 0; i < num.length; i++) {
			//处理大写字母
			if ((num[i]+d) > 90 && num[i]<=90) {
				num[i] = (char)(num[i]+d-26);
				continue;
			}
			//处理小写字母
			if ((num[i]+d) > 122 && num[i]>=97) {
				num[i] = (char)(num[i]+d-26);
				continue;
			}
			num[i] = (char)(num[i]+d);
				
			}
			
			System.out.println(num);
		}
	}
	public static void main(String[] args){
		out();
	}
}

//C++
#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
//#include<string>
//#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    int d;
    while(cin>>s>>d){
        char num[s.size()];
        s.copy(num,s.size());
        d = d%26;
        for (int i = 0; i < sizeof(num)/sizeof(num[0]); i++) {
        //处理大写字母
        if ((num[i]+d) > 90 && num[i]<=90) {
            num[i] = (char)(num[i]+d-26);
            continue;
        }
        //处理小写字母
        if ((num[i]+d) > 122 && num[i]>=97) {
            num[i] = (char)(num[i]+d-26);
            continue;
        }
        num[i] = (char)(num[i]+d);
        }
       for(int i=0;i<sizeof(num)/sizeof(num[0]);++i){
         cout<<num[i];
       }
       cout<<endl;
    }
    return 0;
}