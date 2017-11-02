#include "BiTree.h"

int main()
{
	BTNode *root;

	//TreeInit(root);//初始化空二叉树
	//CreateBTree(root);//按照课件示意图建立一棵二叉树
	//cout << TwoDegreeCount(root);

	ElemType A[] = "ABD##E##CF#G###";//以"#"补充空分支后的某个遍历序列

	TreeInit(root);//初始化空二叉树
	CreateBTree_Pre(root, A);//以前序遍历序列建立二叉树
	PreOrder(root);//输出前序遍历序列
	cout << endl;
	InvertBiTree(root);
	PreOrder(root);
	//cout << "前序遍历序列：";
	//PreOrder(root);//输出前序遍历序列
	//cout << endl;
	//InOrder(root);
	//cout << endl;
	//PostOrder(root);
	//cout << endl;

	/*cout<<BTreeCount(root);
	cout<<FindBTree(root,'C');*/

	return 0;
}