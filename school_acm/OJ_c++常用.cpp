/*
#include<iostream>
#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<string>
//#include<math.h>
#include<algorithm>
//#define inttochar(x) ('0'+x)
//#define chartoint(x) (x-'0')
//#include<stack>
//#include<queue>
#include<vector>
using namespace std;
bool comp(int &a,int &b){
  return a>b;
}
int main()
{
  
  return 0;
}
*/

//获取一整行：
		string s;
    	getline(cin,s);

//获取未知个数
		while(scanf("&d",&n)!=EOF)
//pow和sqrt在math库中

char -> int
	#define chartoint(x) (x-'0')
	cout<<chartonumber(c)+1;
int -> char
	#define inttochar(x) ('0'+x)
	cout<<(char)inttochar(2);
//初始化数组B为0 or -1
memset(B,0,sizeof(B));
//字母大小写转换
cout<<(char)toupper('a'); A
cout<<(char)tolower('A'); a

//头文件

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
  //倒序
  bool comp(int &a,int &b){
  return a>b;
  }
  sort(a,a+5,comp);
#define inttochar(x) ('0'+x)
#define chartoint(x) (x-'0')
#include<queue>// 队列 
#include<stack>//栈
using namespace std;

//定义方式

stack<int>  s;
queue<int>  q;

//栈：
s.empty()//如果栈为空返回true，否则返回false  
s.size()//返回栈中元素的个数  
s.pop()//删除栈顶元素但不返回其值  
s.top()//返回栈顶的元素，但不删除该元素  
s.push(X)//在栈顶压入新元素 ，参数X为要压入的元素

stack<int> s;
s.push(1);
cout<<s.top();
s.pop();
if(s.empty())
cout<<1;

//队列：
q.empty()// 如果队列为空返回true，否则返回false  
q.size() // 返回队列中元素的个数  
q.pop()  //删除队列首元素但不返回其值  
q.front()  // 返回队首元素的值，但不删除该元素  
q.push(X) //在队尾压入新元素 ，X为要压入的元素
q.back() //返回队列尾元素的值，但不删除该元素  

 queue<int> q;
 q.push(1);
 q.push(2);
 cout<<q.back();

#include <vector>

vector<int> a ;  //声明一个int型向量a
vector<int> a(10) ;  //声明一个初始大小为10的向量
vector<int> a(10, 1) ; //声明一个初始大小为10且初始值都为1的向量
vector<int> b(a) ; //声明并用向量a初始化向量b
vector<int> b(a.begin(), a.begin()+3) ; //将a向量中从第0个到第2个(共3个)作为向量b的初始值

// 除此之外, 还可以直接使用数组来初始化向量:
int n[] = {1, 2, 3, 4, 5} ;
vector<int> a(n, n+5) ;  //将数组n的前5个元素作为向量a的初值

元素的输入和访问可以像操作普通的数组那样, 用cin>>进行输入, 
cout<<a[n]这样进行输出:

尾插元素： V.push_back(a[i]);
插入元素：  V.insert(V.begin()+i,a); //在第i+1个元素前面插入a
删除元素：vec.erase(vec.begin()+i); //删除第i+1个元素
求vector的长度：V.size();
a.empty() //判断向量是否为空
交换 - swap
        b.swap(a) ;//a向量与b向量进行交换
sort(V.begin(),V.end());//排序方法

vector<int> a;
  int value;
  while(scanf("%d",&value)){
    if(value==-1)
      break;
    a.insert(a.begin(),value);
  }
  //两种遍历方式，既可以像数组一样
  for(int i=0;i<a.size();++i){
    if(i==3)
      a[i]=3;
  }
  vector<int>::iterator it;
  for(it=a.begin();it!=a.end();it++){
    cout<<*it<<endl;
  }


//二维向量
vector< vector<int> > b(10, vector<int>(5));
 //创建一个10*5的int型二维向量
vector< vector<int> > b(10, vector<int>(5, 0)) ;
   //对部分数据进行输入
  cin>>b[1][1] ;
  cin>>b[2][2] ;
  cin>>b[3][3];

   //全部输出
   int m, n ;
   for(m=0; m<b.size(); m++)           //b.size()获取行向量的大小
   {
       for(n=0; n<b[m].size(); n++)    //获取向量中具体每个向量的大小
           cout<<b[m][n]<<" " ;
       cout<<"\n" ;
  }

