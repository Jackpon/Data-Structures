#include <iostream>
using namespace std;

typedef   float  ElemType;

struct Grade  //NodeΪ���������
{
	int id;
	float score;
};
typedef Grade DataType;

struct Node  //NodeΪ���������
{
	DataType 	data;   //data��������Ԫ��

	struct Node	*next; //nextΪָ����һ����ָ��
};



//��ʼ��������
int InitList(Node * &H);

//�б��
int ListEmpty(Node * H);

//�������е�ǰԪ�صĸ���
int ListLength(Node * H);

//����������
void TraverseList(Node * H);

//���ص�һ����ָ��ֵƥ���Ԫ��λ��
//int Find_item(Node * H, ElemType item);
//
////��ȡ��������ָ��λ���ϵ�����Ԫ��
//int Find_pos(Node * H, int pos, ElemType *item);
//
////�����Ա�ָ��λ�ò���һ����Ԫ��
int ListInsert(Node *H, int pos, DataType item);

//�����Ա���ɾ����һ����ָ��ֵƥ���Ԫ��
int ListDelete(Node *H, int item);

//����������
void DestroyList(Node * &H);

//��������ĵ�����H�в����µ�Ԫ��item�������������Ȼ����
//int ListInsert_order(Node *H, ElemType item);
