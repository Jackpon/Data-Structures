/*
1310: 围圈圈游戏（2013年校赛初赛）

题目描述
Sec参加了一个活动，里面有一个游戏，让n个同学都围成一个圈圈。然后让编号为1的同学开始从1开始报数，报到m的那个同学就被淘汰，重新让剩下n-1个同学继续游戏，接着让被淘汰的那个同学的下一个同学重新从1开始报，以此类推。直到剩下最后一个人，那个人就是胜利者。

Sec希望赢得这个比赛，但不知道应该站在编号是多少的位置，希望你来帮他选一个编号，这个位置可以令Sec取得这个游戏的胜利。

输入
输入包含多个测试数据，以判断输入到达文件为（EOF）终止程序。

每个输入数据包含2个整数n和m( 2<=n<=10^6 , 1<=m<=10^6)

输出
每输入一个样例，程序立即输出该样例的答案，每个输出占一行。

样例输入
3 2
3 5
10 4
样例输出
3
1
5
*/
//建立数组暴力解决，超时
int main()
{
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF){

    int a[n+1];
    for (int i = 1; i <= n; ++i)
    {
      a[i]=i;
    }
    int step=1;
    int i=1;
    int count=0;
    int value=m;
    while(i<n+1){
      if(value>(n-count))
        m=value%(n-count);
      if(m==0)
        m=n-count;
      if(step==m){
        a[i]=0;
        step=0;
        count++;
      }

      i++;
      if(i==n+1)
        i=1;
      if(a[i]!=0)
      {
        step++;
      }
      if(count==(n-1))
        break;
    }
    for (int i = 1; i <= n; ++i)
    {
      if(a[i]!=0)
      {
        printf("%d\n", a[i]);
        break;
      }
    }
  }
  return 0;
}

//改进，利用顺序表
#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF){
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
      v.push_back(i);
    }
    int value=m;
    while(v.size()>1){
       if(value>v.size())
        m=value%v.size();
      if(m==0)
        m=v.size();
      v.erase(v.begin()+m-1);
    }
    printf("%d\n", v[0]);
  }
  return 0;
}

