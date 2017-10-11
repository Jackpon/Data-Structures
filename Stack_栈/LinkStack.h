#include <iostream>
using namespace std;

typedef char ElemType;
struct SNode
{ //��ջ�����������
	ElemType	data; //������
	struct SNode	*next; //��̽��ָ��
};


//��ʼ������ջ
int InitStack(SNode* &top);

//����ջ��
int StackEmpty(SNode *top);

//��ջ
int Push(SNode *top, ElemType item);

//��ջ
int Pop(SNode *top, ElemType &item);

//ȡջ��
int GetTop(SNode *top, ElemType &item);

//�ͷ���ջ
void Destroy(SNode *&top);

//�������
int TraverseStack(SNode *top);

//����
int IsReverse(char *s);