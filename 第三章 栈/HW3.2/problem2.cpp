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

int InitStack(SqStack &s)   //初始化栈
{
	s.base = (SElemType *)malloc((STACK_INIT_SIZE) * sizeof(SElemType));
	if (!s.base)return (OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
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
	/*
	if (s.top - s.base >= s.stacksize)
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
		if (e < 10)
			cout << e;
		else
		{
			char b = 'A' - 10 +e;
			cout << b;
		}
	}
	cout << endl;
	return OK;
}
int trans(int pre, int &n,string s1)
{
	int a = n,t;
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
int main()
{

	int pre, last,n=0,t=0;
	SqStack s;
	string s1;
	InitStack(s);
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
	PrintStack(s);
	
	return 0;
}