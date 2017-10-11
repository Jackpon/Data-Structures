#include "SqStack.h"

//初始化空顺序栈
int InitStack(SqStack &S)
{
	S.top = -1;
	return 1;
}

//判栈空
int StackEmpty(SqStack &S)
{
	if (S.top == -1)
		return 1;
	else
		return 0;
}

//入栈
int Push(SqStack &S, ElemType item)
{
	if (S.top >= MaxSize - 1)
	{
		cout << "栈满" << endl;
		return 0;
	}
	S.top++;
	S.data[S.top] = item;
	return 1;
}

//出栈
int Pop(SqStack &S, ElemType &item)
{
	if (S.top <= -1) {
		cout << "栈空" << endl;
		return 0;
	}
	item = S.data[S.top];
	S.top--;
	return 1;
}

//取栈顶
int GetTop(SqStack &S, ElemType &item)
{
	if (S.top <= -1) {
		cout << "栈空" << endl;
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
//进制转换
void Convert(int num, int d)
{
	//num为待转换数，d为进制
	SqStack S; 
	ElemType result;  
	int r; //余数
	char ch[] = "0123456789ABCDEF"; //进制所使用的数字
	InitStack(S);
	while (num != 0) {
		r = num%d;       //取余数r
		Push(S, ch[r]);  //余数入栈
		num = num / d;   //利用商进行下一次运算
	}
	while (StackEmpty(S) != 1) {
		Pop(S, result); 
		cout << result-'0';
	}
}


