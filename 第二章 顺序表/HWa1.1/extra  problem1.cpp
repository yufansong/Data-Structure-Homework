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
#define LIST_INIT_SIZE  1000000  //线性表存储空间的初始分配量
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
//	void Realloc(SqList &l);
	int ListInsert_sq(SqList &l, int i, ElemType e);//在线性表中第i个位置之前插入x
	int ListDelete_sq(SqList &l, int x);            //在线性表中删除元素
//	int LocateElem_Sq(SqList l, ElemType e);        //在线性表中查找第一个等于x的元素位置
//	void ShowSq(SqList l);                          //输出函数
	SqList l;
	InitList_Sqlist(l);
	int n, x, i;
	cin >> n;
	for (int j = 1; j <= n; j++)//读入数据构造线性表
	{
		cin >> x;
		ListInsert_sq(l, j, x);
	}
	cin >> x;
	if (ListDelete_sq(l, x) == 0)cout << -1 << endl;
	else
	{
		for (int j = 0; j < l.length; j++)
			if(l.elem[j]!=0)cout << l.elem[j]<<" ";
	}
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
	int j=0;
	for (j = l.length - 1; j >= i - 1; j--)l.elem[j + 1] = l.elem[j];  //插入位置及以后位置元素后移
	l.elem[i - 1] = e;  //插入e
	l.length++;
	return OK;

}
int ListDelete_sq(SqList &l, int x)//在线性表中删除元素
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
int LocateElem_Sq(SqList l, ElemType e)//在线性表中查找第一个等于x的元素位置
{
	int i = 1;
	while (i <= l.length&&e != l.elem[i - 1])i++;//找到则输出位置
	if (i <= l.length)return i; else return ERROR;//未找到，输出-1
}
void ShowSq(SqList l) //输出函数
{
	for (int i = 0; i < l.length; i++)cout << l.elem[i] << " ";
	cout << endl;
}
