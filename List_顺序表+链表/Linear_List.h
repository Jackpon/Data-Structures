//����˳���
#include <iostream>
using namespace std;

#define MaxSize 100
typedef char DataType;

typedef struct {
	DataType data[MaxSize];
	int length;
}SqList;

//��ʼ��
void InitList(SqList &L);

//�ж��Ƿ�Ϊ��
int ListEmpty(SqList &L);

//���س���
int ListLength(SqList &L);

//����iλ�õ�ֵ
int GetElem(SqList &L, int i, DataType *e);

//����e��λ��
int LocateElem(SqList &L, DataType e);

//��������
int ListInsert(SqList &L, int i, DataType e);

//ɾ������
int ListDelete(SqList &L, int i, DataType *e);

//������Ա�
//void ClearList(SqList * L);

//�������Ա�
int TraverseList(SqList &L);
