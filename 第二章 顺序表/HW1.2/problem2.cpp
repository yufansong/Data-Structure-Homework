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
	ElemType  *elem;  //�洢�ռ��ַ
	int length;       //��ǰ�ṹ�峤��
	int listsize;     //��ǰ�ṹ�����洢����
}SqList;
int  main()
{
	int InitList_Sqlist(SqList &l);//�������Ա�
	void Realloc(SqList &l);
//	int ListInsert_sq(SqList &l, int i, ElemType e);//�����Ա��е�i��λ��֮ǰ����x
	int ListDelete_sq(SqList &l, int i);            //�����Ա���ɾ����i��Ԫ��
	int LocateElem_Sq(SqList l, ElemType e);        //�����Ա��в��ҵ�һ������x��Ԫ��λ��
	void ShowSq(SqList l);                          //�������
	int OrderInsert_Sq(SqList &l, ElemType x);      //��������
	SqList l;
	InitList_Sqlist(l);
	int x,i;
	cin >> x;
	while (x!=0)
	{
		OrderInsert_Sq(l, x);
		cin >> x;
	}
	cin >> x;
	cout<<OrderInsert_Sq(l, x)+1<<endl;
	cin >> x;
	i = LocateElem_Sq(l, x);
	if (i == 0)cout << -1<<endl;
	else
	{
		ListDelete_sq(l, i);
		cout << i << endl;
	}
	ShowSq(l);
}
int InitList_Sqlist(SqList &l)//�������ݹ������Ա�
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
	if (!newbase)exit(OVERFLOW);//�洢����ʧ��
	l.elem = newbase;//�»�ַ
	l.listsize += LISTINCREMENT;//���´洢����
}
/*int ListInsert_sq(SqList &l, int i, ElemType e)//�����Ա��е�i��λ��֮ǰ����x
{
	if (i<1 || i>l.length + 1)return ERROR;
	if (l.length >= l.listsize)
		Realloc(l);//�洢�ռ����������뿪���µĿռ�
	ElemType* q, *p;
	q = &(l.elem[i - 1]);
	for (p = &(l.elem[l.length - 1]); p >= q; p--)
		*(p + 1) = *p;
	*q = e;
	l.length++;
	return OK;

}
*/
int ListDelete_sq(SqList &l, int i)//�����Ա���ɾ����i��Ԫ��
{
	if (i<1 || i>l.length)return ERROR;
	for (int j = i - 1; j<l.length - 1; j++)l.elem[j] = l.elem[j + 1];//ɾ����Ԫ��ǰ��
	l.length--;
	return OK;
}
int LocateElem_Sq(SqList l, ElemType e)//�����Ա��в��ҵ�һ������x��Ԫ��λ��
{
	int i = 1;
	while (i <= l.length&&e != l.elem[i - 1])i++;//�ҵ������λ��
	if (i <= l.length)return i; else return ERROR;//δ�ҵ������-1
}
void ShowSq(SqList l) //�������
{
	for (int i = 0; i < l.length; i++)cout << l.elem[i] << " ";
	cout << endl;
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