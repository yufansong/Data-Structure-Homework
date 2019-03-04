#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
using namespace std;
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LBnode, *Linklist;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;
int main()
{
	void CreaateList(Linklist &l, int n);   //��������ͷ�巨����
	int ListInsert_L(Linklist &l, int i, ElemType e);//����Ԫ��
	int ListDelete_L(Linklist &l, ElemType e,int n); /*ElemType &e*/			//ɾ����i��Ԫ��
	int LinkLocate_L(Linklist l, int x);	//���ң���ֵ���ң�
	void PrintList_LC(Linklist l, int n);//��������
	int version(Linklist l, int n);
	Linklist l;
	int n = 0, x = 0, i = 0, b = 0;
	cin >> n;
	CreaateList(l, n);
	version(l, n);
	cin >> x;
    i=ListDelete_L(l, x,n);//������ƥ�䵽��Ԫ����0
	if (!i)
		cout << "-1" << endl;
	else PrintList_LC(l, n);//Ԫ�ز�Ϊ0�������
}
int version(Linklist l, int n)
{
	{
		int a[100000];
		Linklist p = l->next;
		for (int i = 0; i<n; i++)
		{
			a[i] = p->data;
			p = p->next;
		}
		p = l->next;
		for (int i = 0; i<n; i++)
		{
			p->data = a[n - 1 - i];
			p = p->next;
		}
		return 1;
	}
}
void CreaateList(Linklist &l, int n)   //��������ͷ�巨����
{
	Linklist p;
	l = (Linklist)malloc(sizeof(LNode));
	l->next = NULL;
	for (int i = n; i > 0; i--)
	{
		p = (Linklist)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = l->next;
		l->next = p;
	}
}
int ListInsert_L(Linklist &l, int i, ElemType e)//����Ԫ��
{
	Linklist p, s;
	p = l;
	int j = 0;
	while (p&&j<i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)return ERROR;
	s = (Linklist)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;							//s��p��next�Ĳ���˳���ܱ䣬���˻��������
	p->next = s;
	return OK;
}
int ListDelete_L(Linklist &l, ElemType e,int n) /*ElemType &e*/			//ɾ������ֵΪe��Ԫ��
{
	Linklist p ;
	p = l->next;										//��ͷ��㿪ʼ��ͷ������������൱����-1������while����p��next��������i-1;
	bool flag=false;
	for (int j=0;j<n;j++)
	{
		if (p->data == e)
		{
			p->data = 0;
			flag = true;
		}
		p = p->next;
	}
	if (flag==false)return 0;
	return OK;
}
int LinkLocate_L(Linklist l, int x)		//���ң���ֵ���ң�
{
	int i;
	Linklist p;
	p = l->next;
	i = 1;
	while (p&&p->data != x)			//p��=NULL��p�ȼ�
	{
		p = p->next;
		i++;
	}
	if (!p) return ERROR;
	else
	{
		return i;
	}
}
int version(Linklist &l, int n)
{
	int a[1000000];
	Linklist p = l->next;
	for (int i = 0; i<n; i++)
	{
		a[i] = p->data;
		p = p->next;
	}
	p = l->next;
	for (int i = 0; i<n; i++)
	{
		p->data = a[n - 1 - i];
		p = p->next;
	}
	return 1;
}
void PrintList_LC(Linklist l, int n)//��������
{
	Linklist p;
	p = l->next;
	for (int i = 0; i<n; i++)
	{
		if (p->data!= 0)
			cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

