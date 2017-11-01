#include "BiTree.h"

//��ʼ���ն�����
void TreeInit(BTNode* &root)
{
	root = NULL;
}

//���տμ�ʾ��ͼ����һ�ö�����
void CreateBTree(BTNode* &root)
{
	BTNode *a, *b, *c, *d, *e, *f, *g;

	a = root = new BTNode;
	a->data = 'A';

	b = a->lchild = new BTNode;
	b->data = 'B';

	c = a->rchild = new BTNode;
	c->data = 'C';
	c->rchild = NULL;

	d = b->lchild = new BTNode;
	d->data = 'D';
	d->lchild = NULL;
	d->rchild = NULL;

	e = b->rchild = new BTNode;
	e->data = 'E';
	e->lchild = NULL;
	e->rchild = NULL;

	f = c->lchild = new BTNode;
	f->data = 'F';
	f->lchild = NULL;

	g = f->rchild = new BTNode;
	g->data = 'G';
	g->lchild = NULL;
	g->rchild = NULL;

}
//����ǰ��������н���������
void CreateBTree_Pre(BTNode * &root, ElemType Array[])
{
	static int count = 0;	//��̬����count��������Ϊ�ݹ�����³�ʼ�� ######
	char item = Array[count];//��ȡArray[]�����еĵ�count��Ԫ��
	count++;
	if (item == '#') //�������#�ַ�����������
	{
		root = NULL; return;
	}
	else
	{
		root = new BTNode;
		root->data = item;
		CreateBTree_Pre(root->lchild, Array); //�������� 
		CreateBTree_Pre(root->rchild, Array); //�������� 
	}
}

//ǰ�����������
void PreOrder(BTNode * root)
{
	if (root != NULL) {
		cout << root->data;  //���ʸ�
		PreOrder(root->lchild); 	//ǰ�����������
		PreOrder(root->rchild);   //ǰ�����������
	}
}
//�������������
void InOrder(BTNode * root)
{
	if (root != NULL) {
		
		InOrder(root->lchild); 	//ǰ�����������
		cout << root->data;  //���ʸ�
		InOrder(root->rchild);   //ǰ�����������
	}
}
//�������������
void PostOrder(BTNode * root)
{
	if (root != NULL) {
		
		PostOrder(root->lchild); 	//ǰ�����������
		PostOrder(root->rchild);   //ǰ�����������
		cout << root->data;  //���ʸ�
	}
}
//������������
int BTreeDepth(BTNode * root)
{
	if (root == NULL)        return 0;
	else {
		int depl = BTreeDepth(root->lchild);
		int depr = BTreeDepth(root->rchild);
		if (depl>depr)       return depl + 1;
		else            return depr + 1;
	}
}
//�ͷŶ����������н��
void ClearBTree(BTNode *& root)
{
	if (root != NULL)
	{
		ClearBTree(root->lchild);
		ClearBTree(root->rchild);
		delete root;
		root = NULL;
	}
}
//���������Ҷ�ӽ������ĺ���
int LeafCount(BTNode * root)
{
	if (root == NULL)
		return 0;
	if (root->rchild == NULL && root->lchild == NULL)
		return 1;

	return LeafCount(root->rchild) + LeafCount(root->lchild);
}
//���������˫��֧�������ĺ���
int TwoDegreeCount(BTNode * root)
{
	int n = 0;
	if (root == NULL)
		return 0;
	if (root->rchild != NULL && root->lchild != NULL)
		n = 1;
	return n+TwoDegreeCount(root->rchild) + TwoDegreeCount(root->lchild);
}
//ͳ�ƶ������н��������
int BTreeCount(BTNode * root)
{
	if (root == NULL) return 0; //�����Ľ����Ϊ0
	else
		return  BTreeCount(root->lchild) +
		BTreeCount(root->rchild) + 1;

}
//���Ҷ�������ֵΪitem�Ľ��
BTNode * FindBTree(BTNode * root, ElemType item)
{
	if (root == NULL) return NULL;
	if (root->data == item) return root;
	BTNode *p = FindBTree(root->lchild, item);
	if (p != NULL) return p;
	else
		return FindBTree(root->rchild, item);

}
