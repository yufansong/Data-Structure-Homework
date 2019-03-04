#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW     -2
#define STACK_INIT_SIZE 100
#define SElemType int 
#define STACKINCREMENT 100

//============================================
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &s, int n)   //��ʼ��ջ
{
	s.base = (SElemType *)malloc((n) * sizeof(SElemType));
	if (!s.base)return (OVERFLOW);
	s.top = s.base;
	s.stacksize = n;
	return OK;
}
int GetTop(SqStack s, SElemType &e)  //��ȡջ��Ԫ��
{
	if (s.top == s.base)return ERROR;
	e = *(s.top - 1);
	return OK;
}

int Push(SqStack &s, SElemType e)   //��ջ����
{
	if (s.top - s.base >= s.stacksize) return ERROR;
	*s.top = e;
	s.top = s.top + 1;
	return OK;
}

int Pop(SqStack &s, SElemType &e)   //��ջ����
{
	if (s.top == s.base)return ERROR;
	s.top = s.top - 1;
	e = *s.top;
	return OK;
}

int PrintStack(SqStack s)//ջ�ı�����ȫ��Ԫ�س�ջ
{
	int e = 0;
	int i = s.top - s.base;
	for (int j = 0; j < i; j++)
	{
		Pop(s, e);
		cout << e << " ";
	}
	cout << endl;
	return OK;
}

//==================================================

int InitStack_Trans(SqStack &s)   //��ʼ��ջ
{
	s.base = (SElemType *)malloc((STACK_INIT_SIZE) * sizeof(SElemType));
	if (!s.base)return (OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return OK;
}
int trans(int pre, int &n, string s1)
{
	int a = n, t;
	return OK;
	n = 0;

	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= '0'&&s1[i] <= '9') {
			t = s1[i] - '0';
		}
		else t = s1[i] - 'A' + 10;
		n = n*pre + t;
	}
}
int PrintStack_Trans(SqStack s)//ջ�ı�����ȫ��Ԫ�س�ջ
{
	int e = 0;
	int i = s.top - s.base;
	for (int j = 0; j < i; j++)
	{
		Pop(s, e);
		if (e < 10)
			cout << e;
		else
		{
			char b = 'A' - 10 + e;
			cout << b;
		}
	}
	cout << endl;
	return OK;
}
//===============================================================
typedef struct SNode
{
	SElemType data;
	struct SNode *next;
}SNode, *LinkStack;
int InitStack_Link(LinkStack &s)
{
	s = (LinkStack)malloc(sizeof(SNode));
	s->next = NULL;
	return OK;
}
int Push_L(LinkStack &s, SElemType e)
{
	LinkStack p = (LinkStack)malloc(sizeof(SNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = s;
	s = p;
	return OK;
}
int Pop_L(LinkStack &s, SElemType &e)
{
	if (!s || !s->next)return ERROR;
	e = s->data;
	LinkStack p = s;
	s = s->next;
	free(p);
	return OK;
}

int PrintStack_Link(LinkStack s)//ջ�ı�����ȫ��Ԫ�س�ջ
{
	int e = 0;
	while (Pop_L(s, e))
	{
		cout << e << " ";
	}
	cout << endl;
	return OK;
}


//===============================================================
int main()
{
	int choice = 0;
	cout << "˳��ջ����������0����ջջ����1����ֵת��2������������ֵĬ��Ϊ��ֵת��"<<endl;
	cin >>choice;
	if (choice == 0)
	{
		cout << "��1��1��������n, ��ʾջ������"<<endl;
			cout << "���Ŷ�����У�ÿһ��ִ��һ��������" << endl;
			cout << "������ Pop ����ʾ��ջ����ջ��ʱ�����һ�� Stack is Empty ���������ջ��Ԫ��" << endl;
			cout << "������ Push 10����ʾ��Ԫ��10��ջ, ��ջ��ʱ�����Stack is Full�����򣬲����" << endl;
			cout<<"������Quit, ���ջ������Ԫ�أ��Կո�ָ"<<endl;
		string operation;
		int n = 0;
		cin >> n;
		SqStack s;
		InitStack(s, n);
		cin >> operation;
		while (operation != "quit")
		{
			if (operation == "pop")
			{
				int e = 0;
				bool flag = false;
				flag = Pop(s, e);
				if (flag == 0)
					cout << "Stack is Empty" << endl;
				else
					cout << e << endl;
			}
			else if (operation == "push")
			{
				int e = 0;
				cin >> e;
				bool flag = false;
				flag = Push(s, e);
				if (!flag)
					cout << "Stack is Full" << endl;
			}
			cin >> operation;
		}
		PrintStack(s);
	}
	else if (choice==1)
	{
		cout << "���Ŷ�����У�ÿһ��ִ��һ��������" << endl;
		cout << "������ Pop ����ʾ��ջ����ջ��ʱ�����һ�� Stack is Empty ���������ջ��Ԫ��" << endl;
		cout << "������ Push 10����ʾ��Ԫ��10��ջ, ��ջ��ʱ�����Stack is Full�����򣬲����" << endl;
		cout << "������Quit, ���ջ������Ԫ�أ��Կո�ָ" << endl;

		LinkStack s;
		InitStack_Link(s);

		string operation;
		cin >> operation;
		while (operation != "quit")
		{
			if (operation == "pop")
			{
				int e = 0;
				bool flag = false;
				flag = Pop_L(s, e);
				if (flag == 0)
					cout << "Stack is Empty" << endl;
				else
					cout << e << endl;
			}
			else if (operation == "push")
			{
				int e = 0;
				cin >> e;
				bool flag = false;
				flag = Push_L(s, e);
				if (!flag)
					cout << "Stack is Full" << endl;
			}
			cin >> operation;
		}
		PrintStack_Link(s);
	}
	else 
	{
		cout << "��1����������ת��ǰ������ ת��������ƣ��Կո�ָ� ,��2�� ��ת������" << endl;
		int pre, last, n = 0, t = 0;
		SqStack s;
		string s1;
		InitStack_Trans(s);
		cin >> pre >> last >> s1;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] >= '0'&&s1[i] <= '9') {
				t = s1[i] - '0';
			}
			else t = s1[i] - 'A' + 10;
			n = n*pre + t;
		}

		while (n)
		{
			int a = n % last;
			Push(s, a);
			n = n / last;
		}
		PrintStack_Trans(s);
	}
	return 0;
}