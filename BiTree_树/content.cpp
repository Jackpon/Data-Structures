#include "BiTree.h"

int main()
{
	BTNode *root;

	//TreeInit(root);//��ʼ���ն�����
	//CreateBTree(root);//���տμ�ʾ��ͼ����һ�ö�����
	//cout << TwoDegreeCount(root);

	ElemType A[] = "ABD##E##CF#G###";//��"#"����շ�֧���ĳ����������

	TreeInit(root);//��ʼ���ն�����
	CreateBTree_Pre(root, A);//��ǰ��������н���������

	//cout << "ǰ��������У�";
	//PreOrder(root);//���ǰ���������
	//cout << endl;
	//InOrder(root);
	//cout << endl;
	//PostOrder(root);
	//cout << endl;

	cout<<BTreeCount(root);
	cout<<FindBTree(root,'C');

	return 0;
}