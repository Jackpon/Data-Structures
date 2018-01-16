/*
1064: 矩阵乘法

问题描述 

给定一个N阶矩阵A，输出A的M次幂（M是非负整数） 

例如： 

A  = 

1  2 

3  4 

A的2次幂 

7  10 

15  22 

输入格式 

第一行是一个正整数N、M（1< =N< =30,  0< =M< =5），表示矩阵A的阶数和要求的幂数 

接下来N行，每行N个绝对值不超过10的非负整数，描述矩阵A的值 

输出格式 

输出共N行，每行N个整数，表示A的M次幂所对应的矩阵。相邻的数之间用一个空格隔开 

样例输入 

2  2 

1  2 

3  4 

样例输出 

7  10 

15  22 
*/

import java.util.Scanner;

public class Main {
    
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in); 
		int n,m;
		while(in.hasNext()) {
			//in
			n = in.nextInt();
			m = in.nextInt();
			int [][]A = new int[n][n];
			for (int i = 0; i < n; i++) 
				for (int j = 0; j < n; j++) 
					A[i][j] = in.nextInt();
			//deal
			for (int i = 0; i < n && m==0; i++) 
				for (int j = 0; j < n; j++) {
					if (i==j) 
						A[i][j]=1;
					else
						A[i][j]=0;
				}	
			
			int [][]B=A;
			int [][]C =A;
			while(m>1) {
				B = new int[n][n];
				m--;
				for (int i = 0; i < n; i++) 
					for (int j = 0; j < n; j++) {
						for (int j2 = 0; j2 < n; j2++) 
							B[i][j] += C[i][j2]*A[j2][j];
					}
				C=B;
			}

			//out
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) 
					System.out.print(B[i][j]+" ");
				System.out.println();
			}
		}
	}

}
//C++
#include<iostream>
#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
//#include<string>
//#include<math.h>
#include<algorithm>
#define inttochar(x) ('0'+x)
#define chartoint(x) (x-'0')
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m){
      int A[n][n];
      for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
          cin>>A[i][j];
        }
      }
     //deal
			for (int i = 0; i < n && m==0; i++)
				for (int j = 0; j < n; j++) {
					if (i==j)
						A[i][j]=1;
					else
						A[i][j]=0;
				}

			int B[n][n];
			int C[n][n] ;
			for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
          B[i][j] = A[i][j];
          C[i][j] = A[i][j];
        }
      }
			while(m>1) {
        memset(B,0,sizeof(B));
				m--;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						for (int j2 = 0; j2 < n; j2++)
							B[i][j] += C[i][j2]*A[j2][j];

				for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
          C[i][j] = B[i][j];
        }
      }

    }

			//out
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					cout<<B[i][j]<<" ";
				cout<<endl;
    }
    }
    return 0;
}




