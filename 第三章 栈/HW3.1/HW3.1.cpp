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
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &s,int n)   //初始化栈
{
	s.base = (SElemType *)malloc((n) * sizeof(SElemType));
	if (!s.base)return (OVERFLOW);
	s.top = s.base;
	s.stacksize = n;
	return OK;
}
int GetTop(SqStack s, SElemType &e)  //获取栈顶元素
{ 
	if (s.top == s.base)return ERROR;
	e = *(s.top - 1);
	return OK;
}

int Push(SqStack &s, SElemType e)   //入栈操作
{
/*	if (s.top - s.base >= s.stacksize)
	{
		s.base = (SElemType*)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!s.base)
			return (OVERFLOW);
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
*/
	if (s.top - s.base >= s.stacksize) return ERROR;
	*s.top = e;
	s.top = s.top + 1;
	return OK;
}

int Pop(SqStack &s, SElemType &e)   //出栈操作
{
	if (s.top == s.base)return ERROR;
	s.top = s.top - 1;
	e = *s.top;
	return OK;
}

int PrintStack(SqStack s)//栈的遍历。全部元素出栈
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
int main()
{
	string operation;
	int n=0;
	cin >> n;
	SqStack s;
	InitStack(s, n);
	cin >> operation;
	while (operation!="quit")
	{
		if (operation == "pop")
		{
			int e = 0;
			bool flag = false;
			flag=Pop(s, e);
			if (flag == 0)
				cout << "Stack is Empty" << endl;
			else
				cout << e<<endl;
		}
		else if(operation=="push")
		{
			int e=0;
			cin >> e;
			bool flag = false;
			flag = Push(s, e);
			if (!flag)
				cout << "Stack is Full" << endl;
		}
		cin >> operation;
	}
	PrintStack(s);
	
	return 0;
}