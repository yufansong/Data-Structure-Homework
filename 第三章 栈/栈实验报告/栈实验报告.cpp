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

int InitStack(SqStack &s, int n)   //初始化栈
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

//==================================================

int InitStack_Trans(SqStack &s)   //初始化栈
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
int PrintStack_Trans(SqStack s)//栈的遍历。全部元素出栈
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

int PrintStack_Link(LinkStack s)//栈的遍历。全部元素出栈
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
	cout << "顺序栈操作请输入0，链栈栈操作1，数值转换2，输入其他数值默认为数值转化"<<endl;
	cin >>choice;
	if (choice == 0)
	{
		cout << "第1行1个正整数n, 表示栈的容量"<<endl;
			cout << "接着读入多行，每一行执行一个动作。" << endl;
			cout << "若输入 Pop ，表示出栈，当栈空时，输出一行 Stack is Empty 否则，输出出栈的元素" << endl;
			cout << "若输入 Push 10，表示将元素10入栈, 当栈满时，输出Stack is Full，否则，不输出" << endl;
			cout<<"若输入Quit, 输出栈中所有元素，以空格分割。"<<endl;
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
		cout << "接着读入多行，每一行执行一个动作。" << endl;
		cout << "若输入 Pop ，表示出栈，当栈空时，输出一行 Stack is Empty 否则，输出出栈的元素" << endl;
		cout << "若输入 Push 10，表示将元素10入栈, 当栈满时，输出Stack is Full，否则，不输出" << endl;
		cout << "若输入Quit, 输出栈中所有元素，以空格分割。" << endl;

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
		cout << "第1行两个数，转换前的数制 转换后的数制，以空格分割 ,第2行 待转换的数" << endl;
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