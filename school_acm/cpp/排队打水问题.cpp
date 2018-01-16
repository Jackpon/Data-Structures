/*
1120: 排队打水问题

题目描述
算法提高  排队打水问题    
时间限制：1.0s     内存限制：256.0MB 
      
问题描述 
　　有n个人排队到r个水龙头去打水，他们装满水桶的时间t1、t2………..tn为整数且各不相等，应如何安排他们的打水顺序才能使他们总共花费的时间最少？ 
输入格式 
　　第一行n，r  (n< =500,r< =75) 
　　第二行为n个人打水所用的时间Ti  (Ti< =100)； 
输出格式 
　　最少的花费时间 
样例输入 
3  2 
1  2  3 
样例输出 
7 
*/
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
//装满时间最少的最先排,总时间sum等于a[i]+d(等待时间)
int main()
{
  int n,r;
  while(cin>>n>>r){
  	int a[n];//n个人的装水时间
  	int d[r];//等待时间
  	int sum=0;//总共时间
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	memset(d,0,sizeof(d));

	for (int i = 0; i < n; ++i)
	{
		sort(d,d+r);
		sum += d[0]+a[i];
		d[0]+=a[i];
	}
	cout<<sum<<endl;
  }
  return 0;
}

