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
	int ListInsert_sq(SqList &l, int i, ElemType e);//�����Ա��е�i��λ��֮ǰ����x
	int ListDelete_sq(SqList &l);            //�����Ա���ɾ����i��Ԫ��
	int Multi_ListDelete_sq(SqList &l, int x);      //�����Ա���ɾ��ָ�������ظ�Ԫ��
	int LocateElem_Sq(SqList l, ElemType e);        //�����Ա��в��ҵ�һ������x��Ԫ��λ��
	void ShowSq(SqList l);                          //�������
	void Destoty_Sq(SqList &l);						//����˳���
	int OrderInsert_Sq(SqList &l, ElemType x);      //��������
	void reverse(SqList &L);						//Ԫ�ص���ת
	int ListDelete_sq(SqList &l, int i);			//Ԫ�ص�ɾ��
	void Clear_Sq(SqList &l);						//˳����Ԫ�����
	int operation = 0;
	cout << "";
	cout << "˳��˳����ȥ�أ�����0" << endl;
	cout << "˳��˳����ɾ�������ã���գ�����1" << endl;
	cout << "��������������Ĭ��Ϊ1" << endl;
	cin >> operation;
	if (operation != 0 && operation != 1)operation = 1;
	if (operation == 0)
	{
		cout << "���ظ�Ԫ��˳���"<<endl;
		cout << "��ʼ������������Ԫ�ظ�����֮��һ������ÿ��Ԫ��" << endl;
		SqList l;
		InitList_Sqlist(l);
		int n, x, i;
		cin >> n;
		for (int j = 1; j <= n; j++)//�������ݹ������Ա�
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
		cout << "˳��˳����ɾ����Ԫ�����ã����" << endl;
		SqList l;
		InitList_Sqlist(l);
		int n, x, i;
		cout << "��ʼ����������˳���Ԫ�ظ�����֮������Ԫ�أ������󣬻����빹����˳���" << endl;
		cin >> n;
		for (int j = 1; j <= n; j++)//�������ݹ������Ա�
		{
			cin >> x;
			OrderInsert_Sq(l, x);      //��������

		}
		ShowSq(l);
		cout << "����ֵ��ɾ��˳����е�һ��Ϊ��ֵ��Ԫ��" << endl;
		cin >> x;
		i = LocateElem_Sq(l, x);
		if (i == 0)cout << -1 << endl;
		else
		{
			ListDelete_sq(l, i);
			cout << i << endl;
		}
		ShowSq(l);
		cout << "����ֵ��ɾ��˳���������Ϊ��ֵ��Ԫ��" << endl;
		cin >> x;
		if (Multi_ListDelete_sq(l, x) == 0)cout << -1 << endl;
		else
		{
			for (int j = 0; j < l.length; j++)
				if (l.elem[j] != 0)cout << l.elem[j] << " ";
		}
		cout << "��ת˳���" << endl;
		reverse(l);
		ShowSq(l);
		cout << "���˳���" << endl;
		Clear_Sq(l);

	}
}
int Multi_ListDelete_sq(SqList &l, int x)//�����Ա���ɾ��Ԫ��
{
	bool flag = false;//�ж��Ƿ��ҵ�Ԫ�أ�������󷵻ش���
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
int ListInsert_sq(SqList &l, int i, ElemType e)//�����Ա��е�i��λ��֮ǰ����x
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
int ListDelete_sq(SqList &l)//�����Ա���ɾ��Ԫ��
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
int LocateElem_Sq(SqList l, ElemType e)//�����Ա��в��ҵ�һ������x��Ԫ��λ��
{
	int i = 1;
	while (i <= l.length&&e != l.elem[i - 1])i++;//�ҵ������λ��
	if (i <= l.length)return i; else return ERROR;//δ�ҵ������-1
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
void ShowSq(SqList l) //�������
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