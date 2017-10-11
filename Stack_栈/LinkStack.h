#include <iostream>
using namespace std;

typedef char ElemType;
struct SNode
{ //链栈结点数据类型
	ElemType	data; //数据域
	struct SNode	*next; //后继结点指针
};


//初始化空链栈
int InitStack(SNode* &top);

//判链栈空
int StackEmpty(SNode *top);

//入栈
int Push(SNode *top, ElemType item);

//出栈
int Pop(SNode *top, ElemType &item);

//取栈顶
int GetTop(SNode *top, ElemType &item);

//释放链栈
void Destroy(SNode *&top);

//遍历输出
int TraverseStack(SNode *top);

//回文
int IsReverse(char *s);