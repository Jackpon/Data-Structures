#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct Node {
	ElemType	data;    //数据域	
	struct Node *lchild;
	struct Node *rchild; //结点的左右子树指针	
}BTNode;//二叉树结点类型

		//初始化空二叉树
void TreeInit(BTNode* &root);

//按照课件示意图建立一棵二叉树
void CreateBTree(BTNode* &root);

//按照前序遍历序列建立二叉树
void CreateBTree_Pre(BTNode* &root, ElemType Array[]);

//前序遍历二叉树
void PreOrder(BTNode *root);
//中序遍历二叉树
void InOrder(BTNode * root);
//后序遍历二叉树
void PostOrder(BTNode * root);


//计算二叉树深度
int BTreeDepth(BTNode *root);

//释放二叉树中所有结点
void ClearBTree(BTNode* &root);

//计算二叉树叶子结点个数的函数
int LeafCount(BTNode *root);

//计算二叉树双分支结点个数的函数
int TwoDegreeCount(BTNode *root);

//统计二叉树中结点总数；
int BTreeCount(BTNode *root);

//查找二叉树中值为item的结点
BTNode* FindBTree(BTNode* root, ElemType item);

//反转二叉树
void InvertBiTree(BTNode *root);