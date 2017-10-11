#include "LinkStack.h"

//初始化空链栈
int InitStack(SNode *&top)
{
	top = new SNode;
	if (top == NULL)
	{
		cout << "初始化错误";
		return 0;
	}
	top->next = NULL;
	return 1;
}

//判栈空
int StackEmpty(SNode *top)
{
	if (top->next == NULL)
		return 1;
	else
		return 0;
}

//入栈
int Push(SNode* top, ElemType item)
{ //带头结点单链表的表头插入法

	SNode *t = new SNode; //①生成新结点
	if (t == NULL) { cout << "出错"; return 0; }
	t->data = item;

	//②在栈顶插入新结点
	t->next = top->next;
	top->next = t;
	return 1;
}

//出栈
int Pop(SNode *top, ElemType &item)
{  //删除单链表的第一个结点

   //①判断栈是否为空
	if (top->next == NULL) { cout << "栈空"; return 0; }

	//②删除栈顶元素
	SNode *t = top->next;
	top->next = t->next;
	item = t->data;
	delete t;
	return 1;
}

//取栈顶
int GetTop(SNode *top, ElemType &item)
{
	//①判断栈是否为空
	if (top->next == NULL) { cout << "栈空"; return 0; }

	//②取栈顶元素
	item = top->next->data;
	return 1;
}

//释放链栈
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
