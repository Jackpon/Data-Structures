#include <iostream>
using namespace std;

#define MAXV 7//��󶥵����

typedef int weight;//�ڽӾ���Ԫ������
typedef char ElemType;//��������Ԫ������



//�ڽӾ�������
typedef struct {
	weight  arcs[MAXV][MAXV]; //�ڽӾ���
	ElemType  data[MAXV];//һά���鶥���
	int n;//�������
} MGraph, *AdjMatrix;

//�����ڽӾ���, g��ָ��ͼ��ָ�������m[][MAXV]���ڽӾ���d[]�Ƕ����,n�������
void CreateGraph(AdjMatrix g, int m[][MAXV], ElemType d[], int n);

//��ʾ�ڽӾ���
void DispGraph(AdjMatrix g);

//ȡ����v�ĵ�һ���ڽӵ�
int GetFirst(AdjMatrix g, int v);

//ȡ����v��λ�ڶ���t֮�����һ���ڽӵ�
int GetNext(AdjMatrix g, int v, int t);

//�Զ���vΪ��㣬������ȱ���ͼ
void DFS(AdjMatrix g, int v, int visited[]);

void iDFS(AdjMatrix g, int v);

void iDFSTraverse(AdjMatrix g,int v,int ivisited[]);