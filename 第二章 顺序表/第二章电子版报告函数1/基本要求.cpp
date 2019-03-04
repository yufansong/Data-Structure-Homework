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
#define LIST_INIT_SIZE  100  //线性表存储空间的初始分配量
#define LISTINCREMENT   10   //线性表存储空间的分配增量
typedef int ElemType;
typedef struct {
	int *elem;  //存储空间基址
	int length;  //当前长度
	int listsize;  //当前分配存储容量
}SqList;
int  main()
{
	int InitList_Sqlist(SqList &l);//构造线性表
	void Realloc(SqList &l);       //空间不足时分配空间
	int ListInsert_sq(SqList &l, int i, ElemType e);//在线性表中第i个位置之前插入x
	int ListDelete_sq(SqList &l, int i);            //在线性表中删除第i个元素
	int LocateElem_Sq(SqList l, ElemType e);        //在线性表中查找第一个等于x的元素位置
	void ShowSq(SqList l);                          //输出函数
	int OrderInsert_Sq(SqList &l, ElemType x);      //递增插入
	void Destoty_Sq(SqList &l);						//顺序表的销毁
	int operation = 0;
	cout << "无序顺序表的初始化，插入，删除，查找，操作请输入0" << endl;
	cout << "有序顺序表的插入功能请输入1" << endl;
	cout << "两有序表的合并生成新的有序表操作请输入2" << endl;
	cout << "如输入其他数字，则默认为无序表操作" << endl;
	cin >> operation;
	if (operation != 0 && operation != 1 && operation != 2)operation = 0;
	if (operation == 0)
	{
		cout << "无序顺序表的初始化，请先输入表中元素个数，之后一次输入元素值" << endl;
		cout << "输出完成后，程序会展示产生的顺序表" << endl;
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
		cout << "顺序表的插入，请依次输入插入元素的位置以及元素的值" << endl;
		cout << "输出完成后，程序会展示产生的新的顺序表，若输入不合法则输出-1" << endl;
		cin >> i >> x;
		if (ListInsert_sq(l, i, x) == 0)cout << -1 << endl;
		else ShowSq(l);
		cout << "顺序表的删除，请输入删除元素的位置" << endl;
		cout << "输出完成后，程序会展示产生的新的顺序表，若输入不合法则输出-1" << endl;
		cin >> i;
		if (ListDelete_sq(l, i) == 0)cout << -1 << endl;
		else ShowSq(l);
		cout << "顺序表的查找，请输入查找元素的值" << endl;
		cout << "输出完成后，程序会展示产生的新的顺序表，若输入不合法则输出-1" << endl;
		cin >> x;
		i = LocateElem_Sq(l, x);
		if (i == 0)cout << -1 << endl;
		else cout << i << endl;
		cout << "顺序表的销毁";
		Destoty_Sq(l);
	}
	else if (operation == 1)
	{
		cout << "有序表的插入" << endl;
		int InitList_Sqlist(SqList &l);//构造线性表
		void Realloc(SqList &l);
		void ShowSq(SqList l);                          //输出函数
		int OrderInsert_Sq(SqList &l, ElemType x);      //递增插入
		SqList l;
		InitList_Sqlist(l);
		int x, i;
		cout << "请输入顺序表的各个元素，输入0时结束" << endl;
		cin >> x;
		while (x != 0)
		{
			OrderInsert_Sq(l, x);
			cin >> x;
		}
		cout << "有序表的插入，请输入要插入的值" << endl;
		cin >> x;
		cout << OrderInsert_Sq(l, x) + 1 << endl;
		ShowSq(l);
		cout << "顺序表的销毁";
		Destoty_Sq(l);
	}
	else
	{
		cout << "两有序顺序表的合并，请依次输入元素的值" << endl;
		int InitList_Sqlist(SqList &l);//构造线性表
		void Realloc(SqList &l);
		void ShowSq(SqList l);                          //输出函数
		int OrderInsert_Sq(SqList &l, ElemType x);      //递增插入
		SqList l;
		InitList_Sqlist(l);
		int x;
		cout << "请输入第一个顺序表，输入0时结束" << endl;
		cin >> x;
		while (x != 0)
		{
			OrderInsert_Sq(l, x);
			cin >> x;
		}
		cout << "请输入第二个顺序表，输入0时结束" << endl;
		cin >> x;
		while (x != 0)
		{
			OrderInsert_Sq(l, x);
			cin >> x;
		}
		cout << endl;
		cout << "两表合并后结果" << endl;
		ShowSq(l);
		cout << "顺序表的销毁";
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
int OrderInsert_Sq(SqList &l, ElemType x)//递增插入
{
	int i = 0;
	if (l.length >= l.listsize)Realloc(l);//存储空间已满，申请开辟新的空间
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
