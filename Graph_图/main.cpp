#include "graph.h"

int main() {
	MGraph  graph;//����ͼ�ṹ����graph
	AdjMatrix g = &graph;//����ָ�����gָ��ͼgraph

	char d[MAXV] = { 'A','B','C','D','E','F','G' };//����һά����d��Ϊ�����

	//����һά����visited����ʼ������Ϊ���ʱ�ǡ�
	int visited[MAXV] = { 0,0,0,0,0,0,0 };
	int ivisited[MAXV] = { 0,0,0,0,0,0,0 };
	//�����ά����mΪ�ڽӾ���
	int m[MAXV][MAXV] = {
		{ 0,0,1,0,0,0,1 },
		{ 0,0,1,0,0,0,0 },
		{ 1,1,0,0,0,0,1 },
		{ 0,0,0,0,0,0,1 },
		{ 0,0,0,0,0,1,1 },
		{ 0,0,0,0,1,0,0 },
		{ 1,0,1,1,1,0,0 },
	};

	//��֪ͼ�Ķ������ڽӾ������ݣ�����ͼgraph���ڽӾ���
	CreateGraph(g, m, d, MAXV);

	//��ʾ�ڽӾ���
	DispGraph(g);
	cout << "������ȱ�����";

	//����ѡ��δ�����ʵĶ�����Ϊ����ͼ����������ȱ���
	for (int v = 1; v < g->n; v++)
		if (visited[v] == 0)     //��δ���ʹ��Ķ�����Ϊ���
			DFS(g, v, visited);
	cout << endl;
	cout << "wo������ȱ�����";
	iDFSTraverse(g,1,ivisited);
}
