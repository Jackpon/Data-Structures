#include "Link_List.h"

//初始化单链表
int InitList(Node *&H)
{  //H为指向单链表的头指针
	H = new Node;
	if (!H)
	{
		cout << "初始化错误" << endl;
		return 0;
	}
	H->next = NULL;
	return 1;
}

//判表空
int ListEmpty(Node * H)
{  //H为指向单链表的头指针
	if (H->next)
		return 0;
	else //头结点指针域为空
		return 1;
}

//求单链表中当前元素的个数
int ListLength(Node * H)
{  //H为指向单链表的头指针
	Node* p = H->next;
	int total = 0;
	while (p) {
		total++;      //计数器+1 
		p = p->next; //指针后移
	}
	return total;
}

//遍历单链表
void TraverseList(Node * H)
{  //H为指向单链表的头指针
	Node* p = H->next;
	while (p)
	{
		cout << p->data.id << "  " << p->data.score << endl;
		p = p->next;
	}
	cout << endl;
}

//返回第一个与指定值匹配的元素位置
//int Find_item(Node * H, ElemType item)
//{  //H为指向单链表的头指针
//	Node *p = H->next;
//	int pos = 0; //结点位序
//	while (p)
//	{ //从单链表第一个结点开始顺序查找所有结点
//		pos++;
//		if (p->data == item) break;
//		p = p->next;
//	}
//	if (p) return pos; //返回位置编号
//	else  return 0;
//}

//获取单链表中指定位置上的数据元素
//int Find_pos(Node * H, int pos, ElemType *item)
//{  //H为指向单链表的头指针
//	Node *p = H->next;
//	int i = 1; //结点位序
//	while (p && i != pos) {
//		p = p->next; i++;
//	}
//	if (p == NULL) { //查找不成功，退出运行
//		cout << "位置无效" << endl;
//		return 0;
//	}
//	*item = p->data;
//	return 1;
//}

//向线性表指定位置插入一个新元素
int ListInsert(Node* H, int pos, DataType item)
{
	Node* p = H;  int i = 0;//H为头指针，它指向头结点，这里不能定义Node* p = H->next(为null);
	while (p) { //查找pos的前驱
		if (i + 1 == pos) break;
		p = p->next; i++;
	}
	if (p == NULL) { //查找不成功，退出运行
		cout << "插入位置无效" << endl;
		return 0;
	}
	Node *t = new Node;	t->data.score = item.score; t->data.id = item.id; //①
	t->next = p->next; //②
	p->next = t; //③
	return 1;
}

//从线性表中删除第一个与指定值匹配的元素
int ListDelete(Node *H, int number)
{
	Node* p = H, *t;
	while (p->next) { //查找pos的前驱
		if (p->next->data.id == number) break;
		p = p->next;
	}
	if (p->next == NULL) { //查找不成功，退出运行
		cout << "删除元素不存在" << endl;
		return 0;
	}
	t = p->next;	    //①t为被删除结点
	p->next = t->next; //②删除t的链接关系
	delete t;		   //③释放被删结点
	return 1;
}

//撤销单链表
void DestroyList(Node * &H)
{  //H为指向单链表的头指针
	Node *p = H;
	while (H) {
		p = H;
		H = H->next;
		delete p;
	}
}

//递增有序的单链表H中插入新的元素item，插入后单链表仍然有序。

//int ListInsert_order(Node* H, ElemType item)
//{
//	Node* p = H;
//	while (p->next->data < item) {
//		p = p->next;
//	}
//	Node* t = new Node;	t->data = item; //①
//	t->next = p->next; //②
//	p->next = t; //③
//	return 1;
//}


