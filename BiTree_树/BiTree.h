#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct Node {
	ElemType	data;    //������	
	struct Node *lchild;
	struct Node *rchild; //������������ָ��	
}BTNode;//�������������

		//��ʼ���ն�����
void TreeInit(BTNode* &root);

//���տμ�ʾ��ͼ����һ�ö�����
void CreateBTree(BTNode* &root);

//����ǰ��������н���������
void CreateBTree_Pre(BTNode* &root, ElemType Array[]);

//ǰ�����������
void PreOrder(BTNode *root);
//�������������
void InOrder(BTNode * root);
//�������������
void PostOrder(BTNode * root);


//������������
int BTreeDepth(BTNode *root);

//�ͷŶ����������н��
void ClearBTree(BTNode* &root);

//���������Ҷ�ӽ������ĺ���
int LeafCount(BTNode *root);

//���������˫��֧�������ĺ���
int TwoDegreeCount(BTNode *root);

//ͳ�ƶ������н��������
int BTreeCount(BTNode *root);

//���Ҷ�������ֵΪitem�Ľ��
BTNode* FindBTree(BTNode* root, ElemType item);

//��ת������
void InvertBiTree(BTNode *root);