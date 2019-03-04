#include<iostream>
#include<string>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define SElemType int 
typedef struct SNode
{
	SElemType data;
	struct SNode *next;
}SNode, *LinkStack;
int InitStack(LinkStack &s)
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
	if (!s||!s->next)return ERROR;
	e = s->data;
	LinkStack p = s;
	s = s->next;
	free(p);
	return OK;
}

int PrintStack(LinkStack s)//栈的遍历。全部元素出栈
{
	int e = 0;
	while (Pop_L(s, e))
	{
		cout << e << " ";
	}
	cout << endl;
	return OK;
}

int main()
{
	LinkStack s;
	InitStack(s);

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
	PrintStack(s);
}
