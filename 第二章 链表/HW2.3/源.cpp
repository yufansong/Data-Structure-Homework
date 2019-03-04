#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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
int  main()
{
	int ListInsert_L(Linklist &l, int i, ElemType e);//插入元素
	void MergeList_L(Linklist &la, Linklist &lb, Linklist &lc);//合并有序链表
	void PrintList_LC(Linklist l,int n);//循环链表的输出
	int OrderInsert_Sq(Linklist &l, ElemType x, int n);
	void CreaateList(Linklist &l, int n);
	Linklist la, lb, lc;
	int x, i, n1 = 1, n2 = 1;
	CreaateList(la, n1);
	cin >> x;
	while (x != 0)
	{
		OrderInsert_Sq(la, x, n1);
		n1++;
		cin >> x;
	}
	CreaateList(lb, n2);
	PrintList_LC(la,n1);
	cin >> x;
	while (x != 0)
	{
		OrderInsert_Sq(lb, x, n2);
		n2++;
		cin >> x;
	}
	cout << endl;
	MergeList_L(la, lb, lc);
	PrintList_LC(lc,n1+n2);
}
void CreaateList(Linklist &l, int n)   //建立链表（头插法建表）
{
	Linklist p;						//	为什么要用指针变量，如果用结点变量会怎么样
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
int ListInsert_L(Linklist &l, int i, ElemType e)//插入元素
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
	s->next = p->next;							//s与p的next的操作顺序不能变，变了会产生错误
	p->next = s;
	return OK;
}
int OrderInsert_Sq(Linklist &l, ElemType x, int n)//递增插入
{
	int i = 1;
	Linklist p = l->next;
	while (p->data < x&&i<n)i++;
	ListInsert_L(l, i, x);
	return i;
}

void MergeList_L(Linklist &la, Linklist &lb, Linklist &lc)//合并有序链表
{
	Linklist pa, pb, pc;
	pa = la->next;
	pb = lb->next;
	lc = pc = la;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		pc->next = pa ? pa : pb;
//		free(lb);
	}
}
void PrintList_LC(Linklist l,int n)//循环链表的输出
{
	Linklist p;
	p = l->next;
	for(int i=0;i<n;i++)
	{
		cout  << p->data << " ";
		p = p->next;
	}
}
