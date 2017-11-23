#include "graph.h"

//�����ڽӾ���, g��ָ��ͼ��ָ�������m[][MAXV]���ڽӾ���d[]�Ƕ����,n�������
void CreateGraph(AdjMatrix g, int m[][MAXV], ElemType d[], int n) {
	int i, j;

	g->n = n;//Ϊͼg�Ķ��������ֵ

	for (i = 0; i < n; i++) {
		g->data[i] = d[i]; //Ϊͼg�Ķ����ֵ

		for (j = 0; j < n; j++) //Ϊͼg���ڽӾ���ֵ
			g->arcs[i][j] = m[i][j];
	}
}

//��ʾ�ڽӾ���
void DispGraph(AdjMatrix g) {
	int i, j;

	cout << "ͼ�Ķ��㣺  ";
	for (i = 0; i < g->n; i++)//���ͼg�Ķ���
		cout << " " << g->data[i];

	cout << "\n\nͼ���ڽӾ���:" << endl;
	//���forѭ�����ƶ�ÿһ��������б���
	for (i = 0; i < g->n; i++) {
		cout << " " << g->data[i];//�������i������

		for (j = 0; j < g->n; j++)//���������i������֮���������i��Ӧ���ڽӾ���ĵ�i�е�����
			cout << " " << g->arcs[i][j];
		cout << endl;
	}
	cout << endl;
}

//ȡ����v�ĵ�һ���ڽӵ�
int GetFirst(AdjMatrix g, int v)
{
	int j;
	if (v < 0 || v >= g->n)//�������±귶Χ��0��g->n-1֮�䣬�±꼴�Ƕ�������
	{
		cout << "����v������Χ" << endl;
		return -1;
	}

	for (j = 0; j < g->n; j++)
		if (g->arcs[v][j] == 1)//ɨ�趥��v�����е�Ԫ��ֵ����һ��Ԫ��ֵΪ1�Ķ�Ӧ�Ķ��㼴�Ƕ���v�ĵ�һ���ڽӵ�
			return   j;//���ض���v�ĵ�һ���ڽӵ�����
	return -1;
}

//ȡ����v��λ�ڶ���t֮�����һ���ڽӵ�
int GetNext(AdjMatrix g, int v, int t) {
	int j;
	if (v < 0 || v >= g->n || t < 0 || t >= g->n)
	{
		cout << "����v��t������Χ" << endl;
		return -1;
	}

	for (j = t + 1; j < g->n; j++) //�ھ���ĵ�v�У��ӵ�t+1�п�ʼɨ��
		if (g->arcs[v][j] == 1)
			return   j;
	return -1;
}

//�Զ���vΪ��㣬������ȱ���ͼ
void DFS(AdjMatrix g, int v, int visited[]) {
	int u;
	cout << " " << g->data[v];  //�������v
	visited[v] = 1;             //���ʱ�־��Ϊ1�������ѷ���

	u = GetFirst(g, v);         //ȡ����v�ĵ�һ���ڽӵ�u
	while (u != -1)
	{
		if (visited[u] == 0)    //�������uδ������
			DFS(g, u, visited); //�Զ���uΪ��㣬����������ȱ���(�ݹ�)
		u = GetNext(g, v, u);   //�ص�����u��ȡ����v��λ�ڶ���u֮�����һ���ڽӵ㣬���У�����ѭ������
	}
}

//�ڶ���DFS��������

void iDFS(AdjMatrix g, int v,int ivisited[])
{
	ivisited[v] = 1;
	cout << g->data[v];
	for (int  i = 0; i <g->n; i++)
		if (g->arcs[v][i]==1 && ivisited[i]==0) 
			iDFS(g,i, ivisited);
}

void iDFSTraverse(AdjMatrix g,int v,int ivisited[])
{
	
	for (int i = v; i < g->n; i++)
	{
		if (ivisited[i]==0)
			iDFS(g,i, ivisited);
	}
	
}
