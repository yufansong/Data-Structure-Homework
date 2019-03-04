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
#define QElemType int 
#define STACKINCREMENT 100
typedef struct QNode//元素结点
{
	QElemType data;
	struct QNode *next;
}QNode ,*QueuePtr;
typedef struct//特殊结点，指向队头队尾
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
int InitQueue(LinkQueue &q)//初始化队列
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front)exit(OVERFLOW);
	q.front->next = NULL;
	return OK;
}
int DeQueue(LinkQueue &q, QElemType &e)//出队
{
	if (q.front == q.rear)return ERROR;
	QueuePtr p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	if (q.rear == p)
		q.rear = q.front;
	free(p);
	return OK;
}
int EnQueue(LinkQueue &q, QElemType e)//入队
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return OK;
}
int PrintQueue(LinkQueue &q)
{
	int e = 0;
	while (DeQueue(q,e))
	{
		cout << e << " ";
	}
	return OK;
}
int main()
{
	string operation;
	int n = 0,m=0;
	cin >> n;
	LinkQueue q;
	InitQueue(q);
	cin >> operation;
	while (operation != "quit")
	{
		if (operation == "dequeue")
		{
			int e = 0;
			if (m<=0)
				cout << "Queue is Empty" << endl;
			else
			{
				DeQueue(q, e);
				m--;
				cout << e << endl;
			}
		}
		else if (operation == "enqueue")
		{
			int e = 0;
			cin >> e;
			if (m>=n)
				cout << "Queue is Full" << endl;
			else
			{
				EnQueue(q, e);
				m++;
			}
		}
		cin >> operation;
	}
	PrintQueue(q);

	return 0;
}