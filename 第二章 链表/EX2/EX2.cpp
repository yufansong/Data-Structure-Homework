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
	cout << "���������������������0" << endl;
	cout << "ѭ���������������������1" << endl;
	cout << "˫���������������������2" << endl;
	cout << "���������ظ������������3" << endl;
	cout << "�����������֣���Ĭ��Ϊ0" << endl;
	cin >> choice;
	if (choice == 0)
	{
		cout << "������Ҫ���������Ԫ�ظ���" << endl;
		cout << "Ȼ������Ԫ�أ�������ɺ����ʾ����Ԫ��" << endl;
		cout << "�����������Ԫ�صĸ�����λ��" << endl;
		cout << "����Ҫɾ��Ԫ�ص�λ�ã���һ��Ԫ��λ��Ϊ1" << endl;
		cout << "����Ҫ����������ϵͳ�᷵��Ԫ�ص�λ�ã������򷵻�-1.���᷵��������Ԫ���ܸ���" << endl;
		void CreaateList(Linklist &l, int n);   //��������ͷ�巨����
		int ListInsert_L(Linklist &l, int i, ElemType e);//����Ԫ��
		int ListDelete_L(Linklist &l, int i); /*ElemType &e*/			//ɾ����i��Ԫ��
		int LinkLocate_L(Linklist l, int x);	//���ң���ֵ���ң�
		void PrintList_LC(Linklist l, int n);//��������
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
		cout << "Ȼ������Ԫ�أ����������������ɺ����ʾѭ������Ԫ��" << endl;
		cout << "�����������Ԫ�صĸ�����λ��" << endl;
		cout << "����Ҫɾ��Ԫ�ص�λ�ã���һ��Ԫ��λ��Ϊ1" << endl;
		cout << "����Ҫ����������ϵͳ�᷵��Ԫ�ص�λ�ã������򷵻�-1.���᷵��������Ԫ���ܸ���" << endl;
		void LC_Creatlist(Linklist &l, int & n);//ѭ������Ľ����㷨
		int ListInsert_L(Linklist &l, int i, ElemType e);//����Ԫ��
		int ListDelete_L(Linklist &l, int i); /*ElemType &e*/			//ɾ����i��Ԫ��
		int LinkLocate_L(Linklist l, int x);	//���ң���ֵ���ң�
		void PrintList_LC(Linklist l, int n);//��������
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
		void DuL_Creatlist(DuLinkList &l,int &n);		//˫��ѭ������Ĵ���
		int GetElem_DuL(DuLinkList l, int i, DuLinkList &p);//����Ų���Ԫ��
		int ListInsert_Dul(DuLinkList &l, int i, ElemType e);//˫��ѭ������Ĳ���
		int ListDelete_DuL(DuLinkList &l, int i, ElemType &e);//˫��ѭ�������ɾ��
		int Dul_PrintList_LC(DuLinkList l, int n);			//���˫��ѭ������
		cout << "Ȼ������Ԫ�أ����������������ɺ����ʾѭ������Ԫ��" << endl;
		cout << "�����������Ԫ�صĸ�����λ��" << endl;
		cout << "����Ҫɾ��Ԫ�ص�λ�ã���һ��Ԫ��λ��Ϊ1" << endl;
		cout << "����Ҫ���������еĵڼ���Ԫ�أ������򷵻�Ԫ�أ����������-1,���᷵��������Ԫ���ܸ�" << endl;
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
		cout << "������Ҫ��������Ԫ�ظ���" << endl;
		cout << "����Ԫ��ֵ�������󣬻�������ظ�Ԫ��" << endl;
		void No_CreaateList(Linklist &l, int n);   //��������ͷ�巨����
		int ListInsert_L(Linklist &l, int i, ElemType e);//����Ԫ��
		int ListDelete_L(Linklist &l, ElemType e, int n); /*ElemType &e*/			//ɾ����i��Ԫ��
		int LinkLocate_L(Linklist l, int x);	//���ң���ֵ���ң�
		void No_PrintList_LC(Linklist l, int n);//��������
		int version(Linklist &l, int n);
		Linklist l;
		int n = 0, x = 0, i = 0, b = 0;
		cin >> n;
		No_CreaateList(l, n);
		version(l, n);
		No_PrintList_LC(l, n);//Ԫ�ز�Ϊ0�������
	}
	return 0;
}

void MergeList_L(Linklist &la, Linklist &lb, Linklist &lc)//�ϲ���������
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
void UnionList_L(Linklist &la, Linklist lb) //���ϲ�����
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
void LC_Creatlist(Linklist &l,int  & n)//ѭ������Ľ����㷨
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
void PrintList_LC(Linklist l)//ѭ����������
{
	Linklist p;
	p = l->next;
	while (p != l)
	{
		cout << "-->" << p->data << endl;
		p = p->next;
	}
}
void DuL_Creatlist(DuLinkList &l,int & n)		//˫��ѭ������Ĵ���
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
int Dul_PrintList_LC(DuLinkList l, int n)			//���˫��ѭ������
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
int ListDelete_L(Linklist &l, int i) /*ElemType &e*/			//ɾ����i��Ԫ��
{
	Linklist p, q;
	p = l;										//��ͷ��㿪ʼ��ͷ������������൱����-1������while����p��next��������i-1
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
void PrintList_LC(Linklist l, int n)//��������
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
void No_PrintList_LC(Linklist l, int n)//����������0Ԫ�ز����������ƥ����Ҫ������
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
void No_CreaateList(Linklist &l, int n)   //��������ͷ�巨�����ظ�Ԫ������
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

