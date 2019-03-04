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
#define LIST_INIT_SIZE  100  //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT   10   //���Ա�洢�ռ�ķ�������
typedef int ElemType;
typedef struct {
	int *elem;  //�洢�ռ��ַ
	int length;  //��ǰ����
	int listsize;  //��ǰ����洢����
}SqList;
int  main()
{
	int InitList_Sqlist(SqList &l);//�������Ա�
	void Realloc(SqList &l);       //�ռ䲻��ʱ����ռ�
	int ListInsert_sq(SqList &l, int i, ElemType e);//�����Ա��е�i��λ��֮ǰ����x
	int ListDelete_sq(SqList &l, int i);            //�����Ա���ɾ����i��Ԫ��
	int LocateElem_Sq(SqList l, ElemType e);        //�����Ա��в��ҵ�һ������x��Ԫ��λ��
	void ShowSq(SqList l);                          //�������
	int OrderInsert_Sq(SqList &l, ElemType x);      //��������
	void Destoty_Sq(SqList &l);						//˳��������
	int operation = 0;
	cout << "����˳���ĳ�ʼ�������룬ɾ�������ң�����������0" << endl;
	cout << "����˳���Ĳ��빦��������1" << endl;
	cout << "�������ĺϲ������µ���������������2" << endl;
	cout << "�������������֣���Ĭ��Ϊ��������" << endl;
	cin >> operation;
	if (operation != 0 && operation != 1 && operation != 2)operation = 0;
	if (operation == 0)
	{
		cout << "����˳���ĳ�ʼ���������������Ԫ�ظ�����֮��һ������Ԫ��ֵ" << endl;
		cout << "�����ɺ󣬳����չʾ������˳���" << endl;
		SqList l;
		InitList_Sqlist(l);
		int n, x, i;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			ListInsert_sq(l, j, x);
		}
		ShowSq(l);
		cout << "˳���Ĳ��룬�������������Ԫ�ص�λ���Լ�Ԫ�ص�ֵ" << endl;
		cout << "�����ɺ󣬳����չʾ�������µ�˳��������벻�Ϸ������-1" << endl;
		cin >> i >> x;
		if (ListInsert_sq(l, i, x) == 0)cout << -1 << endl;
		else ShowSq(l);
		cout << "˳����ɾ����������ɾ��Ԫ�ص�λ��" << endl;
		cout << "�����ɺ󣬳����չʾ�������µ�˳��������벻�Ϸ������-1" << endl;
		cin >> i;
		if (ListDelete_sq(l, i) == 0)cout << -1 << endl;
		else ShowSq(l);
		cout << "˳���Ĳ��ң����������Ԫ�ص�ֵ" << endl;
		cout << "�����ɺ󣬳����չʾ�������µ�˳��������벻�Ϸ������-1" << endl;
		cin >> x;
		i = LocateElem_Sq(l, x);
		if (i == 0)cout << -1 << endl;
		else cout << i << endl;
		cout << "˳��������";
		Destoty_Sq(l);
	}
	else if (operation == 1)
	{
		cout << "�����Ĳ���" << endl;
		int InitList_Sqlist(SqList &l);//�������Ա�
		void Realloc(SqList &l);
		void ShowSq(SqList l);                          //�������
		int OrderInsert_Sq(SqList &l, ElemType x);      //��������
		SqList l;
		InitList_Sqlist(l);
		int x, i;
		cout << "������˳���ĸ���Ԫ�أ�����0ʱ����" << endl;
		cin >> x;
		while (x != 0)
		{
			OrderInsert_Sq(l, x);
			cin >> x;
		}
		cout << "�����Ĳ��룬������Ҫ�����ֵ" << endl;
		cin >> x;
		cout << OrderInsert_Sq(l, x) + 1 << endl;
		ShowSq(l);
		cout << "˳��������";
		Destoty_Sq(l);
	}
	else
	{
		cout << "������˳���ĺϲ�������������Ԫ�ص�ֵ" << endl;
		int InitList_Sqlist(SqList &l);//�������Ա�
		void Realloc(SqList &l);
		void ShowSq(SqList l);                          //�������
		int OrderInsert_Sq(SqList &l, ElemType x);      //��������
		SqList l;
		InitList_Sqlist(l);
		int x;
		cout << "�������һ��˳�������0ʱ����" << endl;
		cin >> x;
		while (x != 0)
		{
			OrderInsert_Sq(l, x);
			cin >> x;
		}
		cout << "������ڶ���˳�������0ʱ����" << endl;
		cin >> x;
		while (x != 0)
		{
			OrderInsert_Sq(l, x);
			cin >> x;
		}
		cout << endl;
		cout << "����ϲ�����" << endl;
		ShowSq(l);
		cout << "˳��������";
		Destoty_Sq(l);
	}
}
int InitList_Sqlist(SqList &l)
{
	l.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!l.elem)exit(OVERFLOW);
	l.length = 0;
	l.listsize = LIST_INIT_SIZE;
	return OK;
}
void Realloc(SqList &l)
{
	ElemType* newbase = (ElemType*)realloc(l.elem, (l.listsize + LISTINCREMENT) * sizeof(ElemType));
	if (!newbase)exit(OVERFLOW);
	l.elem = newbase;
	l.listsize += LISTINCREMENT;
}
int ListInsert_sq(SqList &l, int i, ElemType e)
{
	if (i<1 || i>l.length + 1)return ERROR;
	if (l.length >= l.listsize)
		Realloc(l);
	ElemType* q, *p;
	q = &(l.elem[i - 1]);
	for (p = &(l.elem[l.length - 1]); p >= q; p--)
		*(p + 1) = *p;
	*q = e;
	l.length++;
	return OK;

}
int ListDelete_sq(SqList &l, int i)
{
	if (i<1 || i>l.length)return ERROR;
	ElemType* q, *p;
	p = &(l.elem[i - 1]);
	q = l.elem + l.length - 1;
	for (p++; p <= q; p++)
		*(p - 1) = *p;
	l.length--;
	return OK;
}
int LocateElem_Sq(SqList l, ElemType e)
{
	int i = 1;
	while (i <= l.length&&e != l.elem[i - 1])i++;
	if (i <= l.length)return i; else return ERROR;
}
int OrderInsert_Sq(SqList &l, ElemType x)//��������
{
	int i = 0;
	if (l.length >= l.listsize)Realloc(l);//�洢�ռ����������뿪���µĿռ�
	while (i < l.length&&l.elem[i] < x)i++;
	for (int j = l.length - 1; j >= i; j--)l.elem[j + 1] = l.elem[j];
	l.elem[i] = x;
	l.length++;
	return i;
}
void ShowSq(SqList l)
{
	for (int i = 0; i < l.length; i++)cout << l.elem[i] << " ";
	cout << endl;
}
void Destoty_Sq(SqList &l)
{
	free(l.elem);
	l.elem = NULL;
	l.length = 0;
	l.listsize = 0;
}
