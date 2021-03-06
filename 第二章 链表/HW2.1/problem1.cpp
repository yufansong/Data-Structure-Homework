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
	void CreaateList(Linklist &l, int n);   //建立链表（头插法建表）
	int ListInsert_L(Linklist &l, int i, ElemType e);//插入元素
	int ListDelete_L(Linklist &l, int i); /*ElemType &e*/			//删除第i个元素
	int LinkLocate_L(Linklist l, int x);	//查找（按值查找）
	void PrintList_LC(Linklist l ,int n);//链表的输出
	int version(Linklist &l, int n);
	Linklist l;
	int n = 0,x=0,i=0,b=0;
	cin >> n;
	CreaateList(l, n);
	version(l, n);
	PrintList_LC(l,n);
	cin >> i>> x;
	n++;
	if (!ListInsert_L(l, i, x))
	{
		cout << -1<<endl;
		n--;
	}
	else
		PrintList_LC(l,n);
	cin >> i;
	n--;
	if (!ListDelete_L(l, i))
	{
		cout << -1<<endl;
		n++;
	}
	else
		PrintList_LC(l,n);
	cin >> x;
	b = LinkLocate_L(l, x);
	if (!b)
		cout << -1<<endl;
	else
		cout << b << endl;
	cout << n;
}
int version(Linklist &l, int n)
{
	int a[10000];
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
void CreaateList(Linklist &l, int n)   //建立链表（头插法建表）
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
int ListDelete_L(Linklist &l, int i) /*ElemType &e*/			//删除第i个元素
{
	Linklist p, q;
	p = l;										//从头结点开始，头结点在数组中相当于是-1，所以while里是p的next，而且是i-1
	int j = 0;
	while (p->next&&j<i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)return ERROR;
	q = p->next;
	p->next = q->next;
	//	e = q->data;
	free(q);
	return OK;
}
int LinkLocate_L(Linklist l, int x)		//查找（按值查找）
{
	int i;
	Linklist p;
	p = l->next;
	i = 1;
	while (p&&p->data != x)			//p！=NULL和p等价
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

void PrintList_LC(Linklist l,int n)//链表的输出
{
	Linklist p;
	p = l->next;
	for(int i=0;i<n;i++)
	{
		cout << p->data <<" ";
		p = p->next;
	}
	cout << endl;
}




