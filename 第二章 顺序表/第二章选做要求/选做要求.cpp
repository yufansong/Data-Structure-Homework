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
	ElemType  *elem;  //存储空间地址
	int length;       //当前结构体长度
	int listsize;     //当前结构体分配存储容量
}SqList;
int  main()
{
	int InitList_Sqlist(SqList &l);//构造线性表
	void Realloc(SqList &l);
	int ListInsert_sq(SqList &l, int i, ElemType e);//在线性表中第i个位置之前插入x
	int ListDelete_sq(SqList &l);            //在线性表中删除第i个元素
	int Multi_ListDelete_sq(SqList &l, int x);      //在线性表中删除指定所有重复元素
	int LocateElem_Sq(SqList l, ElemType e);        //在线性表中查找第一个等于x的元素位置
	void ShowSq(SqList l);                          //输出函数
	void Destoty_Sq(SqList &l);						//销毁顺序表
	int OrderInsert_Sq(SqList &l, ElemType x);      //递增插入
	void reverse(SqList &L);						//元素的逆转
	int ListDelete_sq(SqList &l, int i);			//元素的删除
	void Clear_Sq(SqList &l);						//顺序表的元素清空
	int operation = 0;
	cout << "";
	cout << "顺序顺序表的去重，输入0" << endl;
	cout << "顺序顺序表的删除，逆置，清空，输入1" << endl;
	cout << "输入其他数字则默认为1" << endl;
	cin >> operation;
	if (operation != 0 && operation != 1)operation = 1;
	if (operation == 0)
	{
		cout << "无重复元素顺序表"<<endl;
		cout << "初始化，请先输入元素个数，之后一次输入每个元素" << endl;
		SqList l;
		InitList_Sqlist(l);
		int n, x, i;
		cin >> n;
		for (int j = 1; j <= n; j++)//读入数据构造线性表
		{
			cin >> x;
			ListInsert_sq(l, j, x);
		}
		ListDelete_sq(l);
		for (int j = 0; j < l.length; j++)
		{
			if (l.elem[j] != 0)
				cout << l.elem[j] << " ";
		}
	}
	else
	{
		cout << "顺序顺序表的删除，元素逆置，清空" << endl;
		SqList l;
		InitList_Sqlist(l);
		int n, x, i;
		cout << "初始化，先输入顺序表元素个数，之后输入元素，结束后，会输入构建的顺序表" << endl;
		cin >> n;
		for (int j = 1; j <= n; j++)//读入数据构造线性表
		{
			cin >> x;
			OrderInsert_Sq(l, x);      //递增插入

		}
		ShowSq(l);
		cout << "输入值，删除顺序表中第一个为该值的元素" << endl;
		cin >> x;
		i = LocateElem_Sq(l, x);
		if (i == 0)cout << -1 << endl;
		else
		{
			ListDelete_sq(l, i);
			cout << i << endl;
		}
		ShowSq(l);
		cout << "输入值，删除顺序表中所有为该值的元素" << endl;
		cin >> x;
		if (Multi_ListDelete_sq(l, x) == 0)cout << -1 << endl;
		else
		{
			for (int j = 0; j < l.length; j++)
				if (l.elem[j] != 0)cout << l.elem[j] << " ";
		}
		cout << "逆转顺序表" << endl;
		reverse(l);
		ShowSq(l);
		cout << "清空顺序表" << endl;
		Clear_Sq(l);

	}
}
int Multi_ListDelete_sq(SqList &l, int x)//在线性表中删除元素
{
	bool flag = false;//判断是否找到元素，否则最后返回错误
	for (int i = 0; i < l.length; i++)
	{
		if (x == l.elem[i])
		{
			l.elem[i] = 0;
			flag = true;
		}
	}
	if (flag == false)return 0;
	else return 1;
}
int InitList_Sqlist(SqList &l)//读入数据构造线性表
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
	if (!newbase)exit(OVERFLOW);//存储分配失败
	l.elem = newbase;//新基址
	l.listsize += LISTINCREMENT;//更新存储容量
}
int ListInsert_sq(SqList &l, int i, ElemType e)//在线性表中第i个位置之前插入x
{
	if (i<1 || i>l.length + 1)return ERROR;
	if (l.length >= l.listsize)
		Realloc(l);//存储空间已满，申请开辟新的空间
	ElemType* q, *p;
	q = &(l.elem[i - 1]);
	for (p = &(l.elem[l.length - 1]); p >= q; p--)
		*(p + 1) = *p;
	*q = e;
	l.length++;
	return OK;

}
int ListDelete_sq(SqList &l)//在线性表中删除元素
{
	for (int i = 0; i < l.length; i++)
	{
		if (l.elem[i] != 0)
			for (int j = i + 1; j < l.length; j++)
			{
				if (l.elem[i] == l.elem[j])
				{
					l.elem[j] = 0;
				}
			}
	}
	return 1;
}
int LocateElem_Sq(SqList l, ElemType e)//在线性表中查找第一个等于x的元素位置
{
	int i = 1;
	while (i <= l.length&&e != l.elem[i - 1])i++;//找到则输出位置
	if (i <= l.length)return i; else return ERROR;//未找到，输出-1
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
void ShowSq(SqList l) //输出函数
{
	for (int i = 0; i < l.length; i++)
	{
		if (l.elem[i]!=0)
		cout << l.elem[i] << " ";
	}
	cout << endl;
}
void Destoty_Sq(SqList &l)
{
	free(l.elem);
	l.elem = NULL;
	l.length = 0;
	l.listsize = 0;
}
void Clear_Sq(SqList &l)
{
	InitList_Sqlist(l);
}
void reverse(SqList &L)
{
	int i, j, temp;
	for (i = 0, j = L.length-1; i<j; i++, j--) {
		temp = L.elem[i];
		L.elem[i] = L.elem[j];
		L.elem[j] = temp;
	}
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