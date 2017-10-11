#include "LinkStack.h"

//��ʼ������ջ
int InitStack(SNode *&top)
{
	top = new SNode;
	if (top == NULL)
	{
		cout << "��ʼ������";
		return 0;
	}
	top->next = NULL;
	return 1;
}

//��ջ��
int StackEmpty(SNode *top)
{
	if (top->next == NULL)
		return 1;
	else
		return 0;
}

//��ջ
int Push(SNode* top, ElemType item)
{ //��ͷ��㵥����ı�ͷ���뷨

	SNode *t = new SNode; //�������½��
	if (t == NULL) { cout << "����"; return 0; }
	t->data = item;

	//����ջ�������½��
	t->next = top->next;
	top->next = t;
	return 1;
}

//��ջ
int Pop(SNode *top, ElemType &item)
{  //ɾ��������ĵ�һ�����

   //���ж�ջ�Ƿ�Ϊ��
	if (top->next == NULL) { cout << "ջ��"; return 0; }

	//��ɾ��ջ��Ԫ��
	SNode *t = top->next;
	top->next = t->next;
	item = t->data;
	delete t;
	return 1;
}

//ȡջ��
int GetTop(SNode *top, ElemType &item)
{
	//���ж�ջ�Ƿ�Ϊ��
	if (top->next == NULL) { cout << "ջ��"; return 0; }

	//��ȡջ��Ԫ��
	item = top->next->data;
	return 1;
}

//�ͷ���ջ
void Destroy(SNode *&top)
{
	SNode *p;
	while (top != NULL)
	{
		p = top;
		top = top->next;
		delete p;
	}
}

int TraverseStack(SNode * top)
{
	SNode* p = top->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}

int IsReverse(char * s)
{
	SNode* top ;
	InitStack(top);
	char t;
	for (int i = 0; i < strlen(s); i++)
		Push(top, s[i]);
	int i = 0;
	while (StackEmpty(top)!=1)
	{
		Pop(top, t);
		if (t != s[i])
			return 0;
		else
			i++;
	}
	
	return 1;
}
