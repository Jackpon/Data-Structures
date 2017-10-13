#include "Linear_List.h"

void InitList(SqList & L)
{
	L.length = 0;
}

int ListEmpty(SqList & L)
{
	if (L.length <= 0)
		return 1;
	else
		return 0;

}

int ListLength(SqList & L)
{
	return L.length;
}

int GetElem(SqList & L, int i, DataType &e)
{
	if (i < 1 || i > L.length)
	{
		cout << "输入的位置无效" << endl;
		return 0;	//在此return 0表示执行成功，结束函数调用
	}
	*e = L.data[i - 1];
	return 1;		//return 1表示执行交由外部函数
}

int LocateElem(SqList & L, DataType e)
{
	int i = 0;
	if (ListEmpty(L)) {
		cout << "线性表为空" << endl;
		return 0;
	}
	while (i < L.length && L.data[i] != e)
		++i;
	if (i < L.length)
		return i + 1;
	else
		return 0;

}

int ListInsert(SqList & L, int i, DataType e)
{
	if (L.length >= MaxSize) {                  //判表满
		cout << "顺序表满，无法插入！" << endl;
		return 0;
	}

	if (i <= 0 || i>L.length + 1)
	{
		cout << "插入位置无效" << endl;
		return 0;
	}

	for (int j = L.length - 1; j >= i - 1; j--) //从最后位置开始后移，不然元素会被覆盖
	{
		L.data[j + 1] = L.data[j];
	}
	L.data[i - 1] = e;
	L.length++;
	return 1;
}

int ListDelete(SqList & L, int i, DataType &e)
{
	if (ListEmpty(L)) {                  //判表满
		cout << "空表，无法删除" << endl;
		return 0;
	}

	if (i<1 || i>L.length)
	{
		cout << "删除位置无效" << endl;
		return 0;
	}
	*e = L.data[i - 1];
	for (int j = i; j < L.length; j++) //从删除位置下一个开始前移，不然元素会被覆盖
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return 1;
}
/*
void ClearList(SqList * L)
{
free(L);
}
*/
int TraverseList(SqList & L)
{
	int i;
	for (i = 0; i<L.length; i++)    //从头到尾输出线性表的每一个元素
		cout << L.data[i] << "  ";
	cout << endl;
	return 1;
}