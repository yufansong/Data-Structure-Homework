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
	int choice = 0;
	cout << "单链表基本操作，则输入0" << endl;
	cout << "循环链表基本操作，则输入1" << endl;
	cout << "双向链表基本操作，则输入2" << endl;
	cout << "单链表无重复输出，则输入3" << endl;
	cout << "输入其他数字，则默认为0" << endl;
	cin >> choice;
	if (choice == 0)
	{
		cout << "先输入要建立链表的元素个数" << endl;
		cout << "然后输入元素，输入完成后会显示链表元素" << endl;
		cout << "依次输入插入元素的个数和位置" << endl;
		cout << "输入要删除元素的位置，第一个元素位置为1" << endl;
		cout << "输入要查找整数，系统会返回元素的位置，错误则返回-1.最后会返回链表中元素总个数" << endl;
		void CreaateList(Linklist &l, int n);   //建立链表（头插法建表）
		int ListInsert_L(Linklist &l, int i, ElemType e);//插入元素
		int ListDelete_L(Linklist &l, int i); /*ElemType &e*/			//删除第i个元素
		int LinkLocate_L(Linklist l, int x);	//查找（按值查找）
		void PrintList_LC(Linklist l, int n);//链表的输出
		int version(Linklist &l, int n);
		Linklist l;
		int n = 0, x = 0, i = 0, b = 0;
		cin >> n;
		if (n != 0 && n != 1 && n != 2 && n != 3)
			n = 0;
		CreaateList(l, n);
		version(l, n);
		PrintList_LC(l, n);
		cin >> i >> x;
		n++;
		if (!ListInsert_L(l, i, x))
		{
			cout << -1 << endl;
			n--;
		}
		else
			PrintList_LC(l, n);
		cin >> i;
		n--;
		if (!ListDelete_L(l, i))
		{
			cout << -1 << endl;
			n++;
		}
		else
			PrintList_LC(l, n);
		cin >> x;
		b = LinkLocate_L(l, x);
		if (!b)
			cout << -1 << endl;
		else
			cout << b << endl;
		cout << n;
	}
	else  if (choice==1)
	{
		cout << "然后输入元素，以零结束，输入完成后会显示循环链表元素" << endl;
		cout << "依次输入插入元素的个数和位置" << endl;
		cout << "输入要删除元素的位置，第一个元素位置为1" << endl;
		cout << "输入要查找整数，系统会返回元素的位置，错误则返回-1.最后会返回链表中元素总个数" << endl;
		void LC_Creatlist(Linklist &l, int & n);//循环链表的建立算法
		int ListInsert_L(Linklist &l, int i, ElemType e);//插入元素
		int ListDelete_L(Linklist &l, int i); /*ElemType &e*/			//删除第i个元素
		int LinkLocate_L(Linklist l, int x);	//查找（按值查找）
		void PrintList_LC(Linklist l, int n);//链表的输出
		int version(Linklist &l, int n);
		Linklist l;
		int n = 0, x = 0, i = 0, b = 0;
		LC_Creatlist( l, n);
		PrintList_LC(l, n);
		cin >> i >> x;
		n++;
		if (!ListInsert_L(l, i, x))
		{
			cout << -1 << endl;
			n--;
		}
		else
			PrintList_LC(l, n);
		cin >> i;
		n--;
		if (!ListDelete_L(l, i))
		{
			cout << -1 << endl;
			n++;
		}
		else
			PrintList_LC(l, n);
		cin >> x;
		b = LinkLocate_L(l, x);
		if (!b)
			cout << -1 << endl;
		else
			cout << b << endl;
		cout << n;
	}
	else if (choice==2)
	{
		void DuL_Creatlist(DuLinkList &l,int &n);		//双向循环链表的创建
		int GetElem_DuL(DuLinkList l, int i, DuLinkList &p);//按序号查找元素
		int ListInsert_Dul(DuLinkList &l, int i, ElemType e);//双向循环链表的插入
		int ListDelete_DuL(DuLinkList &l, int i, ElemType &e);//双向循环链表的删除
		int Dul_PrintList_LC(DuLinkList l, int n);			//输出双向循环链表
		cout << "然后输入元素，以零结束，输入完成后会显示循环链表元素" << endl;
		cout << "依次输入插入元素的个数和位置" << endl;
		cout << "输入要删除元素的位置，第一个元素位置为1" << endl;
		cout << "输入要查找链表中的第几个元素，存在则返回元素，不存在输出-1,最后会返回链表中元素总个" << endl;
		DuLinkList l;
		int n = 0, x = 0, i = 0, b = 0;
		DuL_Creatlist(l,n);
		Dul_PrintList_LC(l, n);
		cin >> i >> x;
		n++;
		if (!ListInsert_Dul(l, i, x))
		{
			cout << -1 << endl;
			n--;
		}
		else
			Dul_PrintList_LC(l, n);
		cin >> i;
		n--;
		if (!ListDelete_DuL (l, i,b))
		{
			cout << -1 << endl;
			n++;
		}
		else
			Dul_PrintList_LC(l, n);
		cin >> i;
		DuLinkList p;
		b = GetElem_DuL(l, i, p);
		if (!b)
			cout << -1 << endl;
		else
			cout << p->data << endl;
		cout << n;
	}
	else if (choice==3)
	{
		cout << "请输入要建立链表元素个数" << endl;
		cout << "输入元素值，结束后，会输出无重复元素" << endl;
		void No_CreaateList(Linklist &l, int n);   //建立链表（头插法建表）
		int ListInsert_L(Linklist &l, int i, ElemType e);//插入元素
		int ListDelete_L(Linklist &l, ElemType e, int n); /*ElemType &e*/			//删除第i个元素
		int LinkLocate_L(Linklist l, int x);	//查找（按值查找）
		void No_PrintList_LC(Linklist l, int n);//链表的输出
		int version(Linklist &l, int n);
		Linklist l;
		int n = 0, x = 0, i = 0, b = 0;
		cin >> n;
		No_CreaateList(l, n);
		version(l, n);
		No_PrintList_LC(l, n);//元素不为0，则输出
	}
	return 0;
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
		free(lb);
	}
}
void UnionList_L(Linklist &la, Linklist lb) //集合并运算
{
	Linklist p, q, first;
	int x;
	first = la->next;
	p = lb->next;
	while (p)
	{
		x = p->data;
		p = p->next;
		q = first;
		while (q&&q->data != x)
		{
			q = q->next;
		}
		if (!p)
		{
			q = (Linklist)malloc(sizeof(LNode));
			q->data = x;
			q->next = la->next;
			la->next = q;
		}
	}
}
void LC_Creatlist(Linklist &l,int  & n)//循环链表的建立算法
{
	Linklist p;
	int x;
	l = (Linklist)malloc(sizeof(LNode));
	l->next = l;
	while (cin >> x, x != 0)
	{
		n++;
		p = (Linklist)malloc(sizeof(LNode));
		p->data = x;
		p->next = l->next;
		l->next = p;
	}
}
void PrintList_LC(Linklist l)//循环链表的输出
{
	Linklist p;
	p = l->next;
	while (p != l)
	{
		cout << "-->" << p->data << endl;
		p = p->next;
	}
}
void DuL_Creatlist(DuLinkList &l,int & n)		//双向循环链表的创建
{
	DuLinkList p;
	int x;
	l = p = (DuLinkList)malloc(sizeof(DuLinkList));
	l->next = l;
	l->prior = l;
	while (cin >> x, x != 0)
	{
		n++;
		p->next = (DuLinkList)malloc(sizeof(DuLNode));
		p->next->prior = p;
		p = p->next;
		p->data = x;
	}
	p->next = l;
	l->prior = p;
}
int GetElem_DuL(DuLinkList l, int i, DuLinkList &p)//按序号查找元素
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
	DuLinkList p;
	DuLinkList s;
	if (!(GetElem_DuL(l, i, p)))
		return  ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
int ListDelete_DuL(DuLinkList &l, int i, ElemType &e)
{
	DuLinkList p;
	if (!(GetElem_DuL(l, i, p)))
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}
int Dul_PrintList_LC(DuLinkList l, int n)			//输出双向循环链表
{
	DuLinkList p;
	p = l->next;
	for (int i = 0; i<n; i++)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return 1;
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
void PrintList_LC(Linklist l, int n)//链表的输出
{
	Linklist p;
	p = l->next;
	for (int i = 0; i<n; i++)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void No_PrintList_LC(Linklist l, int n)//链表的输出，0元素不输出，用于匹配有要求的输出
{
	Linklist p;
	p = l->next;
	for (int i = 0; i<n; i++)
	{
		if (p->data != 0)
			cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void No_CreaateList(Linklist &l, int n)   //建立链表（头插法建表）重复元素置零
{
	Linklist p;
	int j = 1, x = 0;
	l = (Linklist)malloc(sizeof(LNode));
	l->next = NULL;
	for (int i = n; i > 0; i--)
	{
		p = (Linklist)malloc(sizeof(LNode));
		cin >> x;
		int flag = LinkLocate_L(l, x);
		if (!flag)
		{
			p->data = x;
			p->next = l->next;
			l->next = p;
		}
		else
		{
			p->data = 0;
			p->next = l->next;
			l->next = p;
		}
	}
}

