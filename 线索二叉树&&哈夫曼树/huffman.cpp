#include <iostream>
using namespace std;

//Huffman���Ĵ洢�ṹ
#define n 5						//Ҷ����Ŀ
#define m 2*n-1					//���н������

typedef struct					//�������
{
	double weight;				//Ȩֵ��������Ȩֵ��������
	int lchild, rchild, parent;	//���Һ��Ӽ�˫��ָ��
}HTNode;
typedef HTNode HuffmanTree[m];	//HuffmanTree����������

typedef struct
{
	char ch;					//�洢�ַ�
	char bits[n];				//��ű���λ��
}CodeNode;
typedef CodeNode HuffmanCode[n];

void InitHuffmanTree(HuffmanTree T);	//��ʼ��Huffman��
void InputWeight(HuffmanTree T);		//����Ȩֵ
void CreateHuffmanTree(HuffmanTree T);  //����Huffman����T[m-1]Ϊ������
void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H);//����Huffman��T��Huffman�����H

int main()
{
	HuffmanTree T;
	HuffmanCode H;
	CreateHuffmanTree(T);
	CharSetHuffmanEncoding(T, H);
}

void CreateHuffmanTree(HuffmanTree T)
{ 	//����Huffman����T[m-1]Ϊ������
	int i, j;
	double min1, min2;      //��СȨֵmin1, ��СȨֵmin2, min1<min2
	int lnode, rnode;       //����(ȨֵΪmin1)���lnode, �ҽ��(ȨֵΪmin2)���rnode

	InitHuffmanTree(T);		//��T��ʼ��
	InputWeight(T);			//����Ҷ��Ȩֵ��T[0..n-1]��weight��

	for (i = n; i<m; i++)		//������n-1�κϲ����½�����δ���T[i]��
	{
		//��T[0..i-1]��ѡ������Ȩ��С�ĸ���㣬����ŷֱ�Ϊlnode��rnode

		min1 = min2 = 65535; //min1,min2�ĳ�ʼֵ��Ϊ�������п���Ȩֵ�����ֵ
		lnode = rnode = -1;

		for (j = 0; j <= i - 1; j++)
			if (T[j].parent == -1)   //Ѱ��û��ѡȡ���Ľ��
			{
				if (T[j].weight<min1)  //����ҵ����ȨֵС��min1��˵���ҵ���min1,min2��С��Ȩֵ
				{
					min2 = min1;        //ԭmin1ֵת�Ƶ�min2
					rnode = lnode;      //ԭ�������ת�Ƶ��ҽ��

					min1 = T[j].weight; //����min1Ϊ�ҵ��ĸ�С��Ȩֵ
					lnode = j;          //�����������Ϊ�ҵ��ĸý������
				}
				else
					if (T[j].weight<min2) //���min1<=���Ȩֵ<min2����Ӱ��min1
					{
						min2 = T[j].weight; //����min2
						rnode = j;          //�����ҽ�����
					}
			}

		T[i].weight = T[lnode].weight + T[rnode].weight;  //�µ�˫�׽�����iλ�ã���ȨֵΪ���ҽ��Ȩֵ֮��
		T[i].lchild = lnode;		//��СȨ�ĸ�������½�������
		T[i].rchild = rnode;		//��СȨ�ĸ�������½����Һ���
		T[lnode].parent = T[rnode].parent = i;  //���ҽ���˫�׾�Ϊ�½��
	}
}

void InitHuffmanTree(HuffmanTree T)
{	//��ʼ��Huffman��
	int i;
	for (i = 0; i<m; i++)
	{
		T[i].weight = 0;
		T[i].lchild = T[i].rchild = T[i].parent = -1;
	}
}

void InputWeight(HuffmanTree T)
{	//����Ȩֵ
	int i;
	for (i = 0; i<n; i++)
	{
		cout << "�������" << i + 1 << "��Ȩֵ��";
		cin >> T[i].weight;
	}
}

void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H)
{	//����Huffman��T��Huffman�����H
	int i, c, f;				//c��f�ֱ�ָʾT�к��Ӻ�˫�׵�λ��
	char cd[n];			    //��ʱ��ű���
	char str[n + 1];          //��������ַ���
	int start;				//ָʾ������cd�е���ʼλ��
	cd[n - 1] = '\0';			//���������

	cout << "�������ַ�����";
	cin >> str;
	for (i = 0; i<n; i++)		//������Ҷ��T[i]�ı���
	{
		H[i].ch = str[i];	    //����Ҷ��T[i]��Ӧ���ַ�
		start = n - 1;			//������ʼλ�õĳ�ֵ
		c = i;				//��Ҷ��T[i]��ʼ����
		while ((f = T[c].parent) != -1)//ֱ�����ݵ�T[c]������Ϊֹ
		{	//��T[c]��T[f]�����ӣ������ɴ���0���������ɴ���1
			cd[--start] = (T[f].lchild == c) ? '0' : '1';
			c = f;			//��������
		}
		strcpy_s(H[i].bits, &cd[start]);		//���Ʊ���λ��
	}
	for (i = 0; i<n; i++)
		cout << "��" << i + 1 << "���ַ�" << H[i].ch << "�ı���Ϊ" << H[i].bits << endl;
}
