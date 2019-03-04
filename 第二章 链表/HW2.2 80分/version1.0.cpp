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
#define ElemType int
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
	int LinkLocate_L(DuLinkList l, int x, int n);	//���ң���ֵ���ң�
	void PrintList_LC(DuLinkList l, int n);//ѭ����������
	void DuL_Creatlist(DuLinkList &l, int n);		//˫��ѭ������Ĵ���
	int ListInsert_Dul(DuLinkList &l, int i, ElemType e);//˫��ѭ������Ĳ���
	int ListDelete_DuL(DuLinkList &l, int i);//˫��ѭ�������ɾ��
	DuLinkList l;
	int n = 0, x = 0, i = 0, b = 0;
	cin >> n;
	DuL_Creatlist(l, n);
	PrintList_LC(l, n);
	cin >> i >> x;
	if (i>n)
	{
		cout << -1 << endl;
	}
	else
	{
		ListInsert_Dul(l, i, x);
		n++;
		PrintList_LC(l, n);

	}
	cin >> i;
	if (i>n)
	{
		cout << -1 << endl;
	}
	else
	{
		ListDelete_DuL(l, i);
		n--;
		PrintList_LC(l, n);
	}
	cin >> x;
	b = LinkLocate_L(l, x, n);
	if (!b)
		cout << -1 << endl;
	else
		cout << b << endl;
	cout << n;
}
void DuL_Creatlist(DuLinkList &l, int n)		//˫��ѭ������Ĵ���
{
	DuLinkList p;
	int x;
	l = p = (DuLinkList)malloc(sizeof(DuLinkList));
	l->next = l;
	l->prior = l;
	for (int i = 0; i <n; i++)
	{
		cin >> x;
		p->next = (DuLinkList)malloc(sizeof(DuLNode));
		p->next->prior = p;
		p = p->next;
		p->data = x;
	}
	p->next = l;
	l->prior = p;
}
int LinkLocate_L(DuLinkList l, int x, int n)		//���ң���ֵ���ң�
{
	int i;
	DuLinkList p;
	p = l->next;
	i = 1;
	while (p&&p->data != x&&i <= n)			//p��=NULL��p�ȼ�
	{
		p = p->next;
		i++;
	}
	if (!p || i > n) return ERROR;
	else
	{
		return i;
	}
}
int GetElem_DuL(DuLinkList l, int i, DuLinkList &p)//����Ų���Ԫ��
{
	p = l->next;
	int j = 1;
	int m = 0;
	while (p&&m<1 && j<i)
	{
		p = p->next;
		j++;
		if (p == l->next)
			m++;

	}
	if (p == l->next || j > i || m == 1)return ERROR;
	//e = p->data;
	return OK;
}
int ListInsert_Dul(DuLinkList &l, int i, ElemType e)
{
	DuLinkList p=l->next;
	DuLinkList s;
	for (int j=1;j<i;j++)
	{
		p = p->next;
	}
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
int ListDelete_DuL(DuLinkList &l, int i)
{
	DuLinkList p=l->next;
	for (int j = 1; j<i; j++)
	{
		p = p->next;
	}
	int e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}

void PrintList_LC(DuLinkList l, int n)//��������
{
	DuLinkList p;
	p = l->next;
	for (int i = 0; i<n; i++)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
