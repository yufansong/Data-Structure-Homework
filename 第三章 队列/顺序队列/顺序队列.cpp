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
#define QElemType int 
#define MAXQSIZE 100
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
int InitQueue(SqQueue &q )
{
	q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!q.base)exit(OVERFLOW);
	q.front = q.rear = 0;
	return OK;
}
int EnQueue(SqQueue &q, QElemType e)
{
	if ((q.rear + 1) % MAXQSIZE == q.front)return ERROR;
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % MAXQSIZE;
	return OK;
}
int DeQueue(SqQueue &q, QElemType &e)
{
	if (q.front == q.rear)return ERROR;
	e = q.base[q.front];
	q.front = (q.front + 1) % MAXQSIZE;
	return OK;
}


int PrintQueue(SqQueue q)
{
	int e = 0;
	while (DeQueue(q, e))
	{
		cout << e << " ";
	}
	return OK;
}
int main()
{
	string operation;
	SqQueue q;
	InitQueue(q);
	cin >> operation;
	while (operation != "quit")
	{
		if (operation == "dequeue")
		{
			int e = 0;
			if (!DeQueue(q,e))
				cout << "Queue is Empty" << endl;
			else
			{
				cout << e << endl;
			}
		}
		else if (operation == "enqueue")
		{
			int e = 0;
			cin >> e;
			if (!EnQueue(q,e))
				cout << "Queue is Full" << endl;
		}
		cin >> operation;
	}
	PrintQueue(q);

	return 0;
}