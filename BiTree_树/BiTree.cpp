#include "BiTree.h"

//初始化空二叉树
void TreeInit(BTNode* &root)
{
	root = NULL;
}

//按照课件示意图建立一棵二叉树
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
//按照前序遍历序列建立二叉树
void CreateBTree_Pre(BTNode * &root, ElemType Array[])
{
	static int count = 0;	//静态变量count，不会因为递归而重新初始化 ######
	char item = Array[count];//读取Array[]数组中的第count个元素
	count++;
	if (item == '#') //如果读入#字符，创建空树
	{
		root = NULL; return;
	}
	else
	{
		root = new BTNode;
		root->data = item;
		CreateBTree_Pre(root->lchild, Array); //建左子树 
		CreateBTree_Pre(root->rchild, Array); //建右子树 
	}
}

//前序遍历二叉树
void PreOrder(BTNode * root)
{
	if (root != NULL) {
		cout << root->data;  //访问根
		PreOrder(root->lchild); 	//前序遍历左子树
		PreOrder(root->rchild);   //前序遍历右子树
	}
}
//中序遍历二叉树
void InOrder(BTNode * root)
{
	if (root != NULL) {
		
		InOrder(root->lchild); 	//前序遍历左子树
		cout << root->data;  //访问根
		InOrder(root->rchild);   //前序遍历右子树
	}
}
//后序遍历二叉树
void PostOrder(BTNode * root)
{
	if (root != NULL) {
		
		PostOrder(root->lchild); 	//前序遍历左子树
		PostOrder(root->rchild);   //前序遍历右子树
		cout << root->data;  //访问根
	}
}
//计算二叉树深度
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
//释放二叉树中所有结点
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
//计算二叉树叶子结点个数的函数
int LeafCount(BTNode * root)
{
	if (root == NULL)
		return 0;
	if (root->rchild == NULL && root->lchild == NULL)
		return 1;

	return LeafCount(root->rchild) + LeafCount(root->lchild);
}
//计算二叉树双分支结点个数的函数
int TwoDegreeCount(BTNode * root)
{
	int n = 0;
	if (root == NULL)
		return 0;
	if (root->rchild != NULL && root->lchild != NULL)
		n = 1;
	return n+TwoDegreeCount(root->rchild) + TwoDegreeCount(root->lchild);
}
//统计二叉树中结点总数；
int BTreeCount(BTNode * root)
{
	if (root == NULL) return 0; //空树的结点数为0
	else
		return  BTreeCount(root->lchild) +
		BTreeCount(root->rchild) + 1;

}
//查找二叉树中值为item的结点
BTNode * FindBTree(BTNode * root, ElemType item)
{
	if (root == NULL) return NULL;
	if (root->data == item) return root;
	BTNode *p = FindBTree(root->lchild, item);
	if (p != NULL) return p;
	else
		return FindBTree(root->rchild, item);

}
