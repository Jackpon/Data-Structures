//建立顺序表
#include <iostream>
using namespace std;

#define MaxSize 100
typedef char DataType;

typedef struct {
	DataType data[MaxSize];
	int length;
}SqList;

//初始化
void InitList(SqList &L);

//判断是否为空
int ListEmpty(SqList &L);

//返回长度
int ListLength(SqList &L);

//返回i位置的值
int GetElem(SqList &L, int i, DataType *e);

//返回e的位置
int LocateElem(SqList &L, DataType e);

//插入数据
int ListInsert(SqList &L, int i, DataType e);

//删除数据
int ListDelete(SqList &L, int i, DataType *e);

//清空线性表
//void ClearList(SqList * L);

//遍历线性表
int TraverseList(SqList &L);
