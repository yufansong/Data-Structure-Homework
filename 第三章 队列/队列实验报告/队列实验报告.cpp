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


//===============================================================
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
int InitQueue(SqQueue &q)
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

//===============================================================

typedef struct QNode//元素结点
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct//特殊结点，指向队头队尾
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
int InitQueue_L(LinkQueue &q)//初始化队列
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front)exit(OVERFLOW);
	q.front->next = NULL;
	return OK;
}
int DeQueue_L(LinkQueue &q, QElemType &e)//出队
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
int EnQueue_L(LinkQueue &q, QElemType e)//入队
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return OK;
}
int PrintQueue_L(LinkQueue &q)
{
	int e = 0;
	while (DeQueue_L(q, e))
	{
		cout << e << " ";
	}
	return OK;
}


//===============================================================
int main()
{
	int choice = 0;
	cout << "顺序队列操作请输入0，链队列操作1，输入其他数值默认链队列" << endl;
	cin >> choice;
	if (choice == 0)
	{
		cout << "接着读入多行，每一行执行一个动作。" << endl;
		cout << "若输入dequeue，表示出队，当队空时，输出一行Queue is Empty否则，输出出队的元素；" << endl;
		cout << "若输入enqueue 10，表示将元素10入队,当队满时，输出Queue is Full，否则，不输出" << endl;
		cout << "若输入Quit,输出队列中所有元素，以空格分割" << endl;
		string operation;
		SqQueue q;
		InitQueue(q);
		cin >> operation;
		while (operation != "quit")
		{
			if (operation == "dequeue")
			{
				int e = 0;
				if (!DeQueue(q, e))
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
				if (!EnQueue(q, e))
					cout << "Queue is Full" << endl;
			}
			cin >> operation;
		}
		PrintQueue(q);
	}
	else
	{
		cout << "第1行1个正整数n, 表示队列的容量" << endl;
		cout << "接着读入多行，每一行执行一个动作。" << endl;
		cout << "若输入dequeue，表示出队，当队空时，输出一行Queue is Empty否则，输出出队的元素；" << endl;
		cout << "若输入enqueue 10，表示将元素10入队,当队满时，输出Queue is Full，否则，不输出" << endl;
		cout << "若输入Quit,输出队列中所有元素，以空格分割" << endl;
		string operation;
		int n = 0, m = 0;
		cin >> n;
		LinkQueue q;
		InitQueue_L(q);
		cin >> operation;
		while (operation != "quit")
		{
			if (operation == "dequeue")
			{
				int e = 0;
				if (m <= 0)
					cout << "Queue is Empty" << endl;
				else
				{
					DeQueue_L(q, e);
					m--;
					cout << e << endl;
				}
			}
			else if (operation == "enqueue")
			{
				int e = 0;
				cin >> e;
				if (m >= n)
					cout << "Queue is Full" << endl;
				else
				{
					EnQueue_L(q, e);
					m++;
				}
			}
			cin >> operation;
		}
		PrintQueue_L(q);

	}
	return 0;
}