#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
//#define OVERFLOW        -2
#define LIST_INIT_SIZE  100  //线性表存储空间的初始分配量
#define LISTINCREMENT   10   //线性表存储空间的分配增量
typedef int ElemType;
typedef struct {
	int *elem;  //存储空间基址
	int length;  //当前长度
	int listsize;  //当前分配存储容量
}SqList;
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
void ShowSq(SqList l)
{
	for (int i = 0; i < l.length; i++)cout << l.elem[i] << " ";
	cout << endl;
}
int  main()
{
	SqList l;
	InitList_Sqlist(l);
	int n, x,i;
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		cin >> x;
		ListInsert_sq(l, j, x);
	}
	ShowSq(l);
	cin >> i >> x;
	if (ListInsert_sq(l, i, x) == 0)cout << -1 << endl;
	else ShowSq(l);
	cin >> i;
	if (ListDelete_sq(l,i) == 0)cout << -1 << endl;
	else ShowSq(l);
	cin >> x;
	i = LocateElem_Sq(l, x);
	if (i == 0)cout << -1 << endl;
	else cout<< i;

}