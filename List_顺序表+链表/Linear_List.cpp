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
		cout << "�����λ����Ч" << endl;
		return 0;	//�ڴ�return 0��ʾִ�гɹ���������������
	}
	*e = L.data[i - 1];
	return 1;		//return 1��ʾִ�н����ⲿ����
}

int LocateElem(SqList & L, DataType e)
{
	int i = 0;
	if (ListEmpty(L)) {
		cout << "���Ա�Ϊ��" << endl;
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
	if (L.length >= MaxSize) {                  //�б���
		cout << "˳��������޷����룡" << endl;
		return 0;
	}

	if (i <= 0 || i>L.length + 1)
	{
		cout << "����λ����Ч" << endl;
		return 0;
	}

	for (int j = L.length - 1; j >= i - 1; j--) //�����λ�ÿ�ʼ���ƣ���ȻԪ�ػᱻ����
	{
		L.data[j + 1] = L.data[j];
	}
	L.data[i - 1] = e;
	L.length++;
	return 1;
}

int ListDelete(SqList & L, int i, DataType &e)
{
	if (ListEmpty(L)) {                  //�б���
		cout << "�ձ��޷�ɾ��" << endl;
		return 0;
	}

	if (i<1 || i>L.length)
	{
		cout << "ɾ��λ����Ч" << endl;
		return 0;
	}
	*e = L.data[i - 1];
	for (int j = i; j < L.length; j++) //��ɾ��λ����һ����ʼǰ�ƣ���ȻԪ�ػᱻ����
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
	for (i = 0; i<L.length; i++)    //��ͷ��β������Ա��ÿһ��Ԫ��
		cout << L.data[i] << "  ";
	cout << endl;
	return 1;
}