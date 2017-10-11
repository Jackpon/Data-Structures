#include "SqStack.h"

//��ʼ����˳��ջ
int InitStack(SqStack &S)
{
	S.top = -1;
	return 1;
}

//��ջ��
int StackEmpty(SqStack &S)
{
	if (S.top == -1)
		return 1;
	else
		return 0;
}

//��ջ
int Push(SqStack &S, ElemType item)
{
	if (S.top >= MaxSize - 1)
	{
		cout << "ջ��" << endl;
		return 0;
	}
	S.top++;
	S.data[S.top] = item;
	return 1;
}

//��ջ
int Pop(SqStack &S, ElemType &item)
{
	if (S.top <= -1) {
		cout << "ջ��" << endl;
		return 0;
	}
	item = S.data[S.top];
	S.top--;
	return 1;
}

//ȡջ��
int GetTop(SqStack &S, ElemType &item)
{
	if (S.top <= -1) {
		cout << "ջ��" << endl;
		return 0;
	}
	item = S.data[S.top];
	return 1;
}

int TraverseStack(SqStack & S)
{
	for (int i = S.top; i >= 0; i--)
	{
		cout << S.data[i] << " ";
	}
	return 0;
}
//����ת��
void Convert(int num, int d)
{
	//numΪ��ת������dΪ����
	SqStack S; 
	ElemType result;  
	int r; //����
	char ch[] = "0123456789ABCDEF"; //������ʹ�õ�����
	InitStack(S);
	while (num != 0) {
		r = num%d;       //ȡ����r
		Push(S, ch[r]);  //������ջ
		num = num / d;   //�����̽�����һ������
	}
	while (StackEmpty(S) != 1) {
		Pop(S, result); 
		cout << result-'0';
	}
}


