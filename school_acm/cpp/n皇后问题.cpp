/*
1314: n皇后问题（2013年校赛决赛）

题目描述
N皇后问题相信大家都早就听过，就是求一个n*n的国际象棋棋盘中，放n个皇后，让每个皇后不互相攻击，问有多少种符合要求放置方法。国际象棋中的皇后可以攻击同一行，同一列和同一斜线上的棋子，也就是说要求的是n*n的国际象棋棋盘中，任何两个皇后不放在同一行或同一列或同一斜线上。

这次我们加多一个条件：规定了棋盘上某些格子不能放皇后。

在这种情况下计算有多少种符合要求的放置方法。

输入

输入包含多组测试样例。每组测试样例的第一行有两个数字n和k(4<=n<=10, 0 <= k <= n*n)，接下来会跟着k行输入，每行输入两个整数(x,y)表示不能放棋子的位置（X，Y坐标都是从1开始，以最左上角的格子坐标为（1,1）为标准)。



输出

对每个测试样例，输出符合要求的放置方法数量。



样例输入
4 0
4 1
2 1
样例输出
2
1
*/

#include<iostream>
#include<vector>
using namespace std;

int count = 0;
int isCorrect(int n,int m,int i, int j, vector<vector<int> > Q,vector<vector<int> > Else)
{
    int s, t;
    for(s=i,t=0; t<n; t++)
        if(Q[s][t]==1 && t!=j)
            return 0;//判断行
    for(t=j,s=0; s<n; s++)
        if(Q[s][t]==1 && s!=i)
            return 0;//判断列
    for(s=i-1,t=j-1; s>=0&&t>=0; s--,t--)
        if(Q[s][t]==1)
            return 0;//判断左上方
    for(s=i+1,t=j+1; s<n&&t<n;s++,t++)
        if(Q[s][t]==1)
            return 0;//判断右下方
    for(s=i-1,t=j+1; s>=0&&t<n; s--,t++)
        if(Q[s][t]==1)
            return 0;//判断右上方
    for(s=i+1,t=j-1; s<n&&t>=0; s++,t--)
        if(Q[s][t]==1)
            return 0;//判断左下方
        //排除特定情况
        for (int s = 0; s < m; ++s)
        {
                if(Else[s][0]==i && Else[s][1]==j)
                    return 0;
        }

    return 1;//否则返回
}

void Queue(int n,int m,int j, vector<vector<int> > Q,vector<vector<int> > Else)
{
    int i,k;
    if(j==n){//递归结束条件
//        for(i=0; i<n; i++){
//                //得到一个解，在屏幕上显示
//            for(k=0; k<n; k++)
//                printf("%d ", Q[i][k]);
//            printf("\n");
//        }
//        printf("\n");
        count++;
        return ;
    }
    for(i=0; i<n; i++){
        if(isCorrect(n,m,i, j, Q,Else)){//如果Q[i][j]可以放置皇后
            Q[i][j]=1;//放置皇后
            Queue(n,m,j+1, Q,Else);//递归深度优先搜索解空间树
            Q[i][j]=0;//这句代码就是实现回溯到上一层
        }
    }
}

int main()
{
    int n,k;
    while(cin>>n>>k){
                vector<vector<int> > Else(k,vector<int>(2));
                for (int i = 0; i < k; ++i)
                {
                        for (int j = 0; j < 2; ++j)
                        {
                                cin>>Else[i][j];
                                Else[i][j] -= 1;
                        }
                }
        vector<vector<int> > Q(n,vector<int>(n,0));
       // Q[1][0]=1;
        Queue(n,k,0, Q,Else);
                cout<<count<<endl;
                count=0;

    }
    return 0;
}