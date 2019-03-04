#include<iostream>
#include<string>
using namespace std;
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define MAXSQ     100
typedef char  TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode ,*BiTree;
typedef struct seqqueue {
	BiTree data[MAXSQ];
	int front;
	int rear;
}seqqueue;
int CreateBiTree(BiTree &t)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		t = NULL;
	else
	{
		if (!(t = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		t->data = ch;
		CreateBiTree(t->lchild);
		CreateBiTree(t->rchild);
	}
	return OK;
}
int PreOrderTraverse(BiTree t)
{
	if (t)
	{
		cout << t->data;
		PreOrderTraverse(t->lchild);
		PreOrderTraverse(t->rchild);
	}
	return OK;
}
int InOrderTraverse(BiTree t)
{
	if (t)
	{
		InOrderTraverse(t->lchild);
		cout << t->data;
		InOrderTraverse(t->rchild);
	}
	return OK;
}
int PostOderTraverse(BiTree t)
{
	if (t)
	{
		PostOderTraverse(t->lchild);
		PostOderTraverse(t->rchild);
		cout << t->data;
	}
	return OK;
}
int Sq_enter(seqqueue &q, BiTree t)
{
	if (q.rear == MAXSQ)
		cout << "QUEUE FULL"<< endl;
	else
	{
		q.data[q.rear] = t;
		q.rear++;
	}
	return OK;
}
int Sq_del(seqqueue &q,BiTree &t)
{
	if (q.front == q.rear)
		return ERROR;
	else
	{
		t = q.data[q.front];
		q.front++;
	}
	return OK;
}
int HieOrderTraverse(BiTree t)
{
	seqqueue q;
	q.front = q.rear = 0;
	if (!t)
	{
		cout << "tree is empty";
		return ERROR;
	}
	Sq_enter(q, t);
	while (q.front!=q.rear)
	{
		 Sq_del(q,t);
		 cout << t->data;
		 if (t->lchild)
			 Sq_enter(q, t->lchild);
		 if (t->rchild)
			 Sq_enter(q, t->rchild);
	}

	return OK;
}
int transoutput(BiTree t,int &i)
{
	i++;
	if (t)
	{
		transoutput(t->rchild,i);
		for (int j = 0; j < i; j++)
		{
			cout << "     ";
		}
		cout << t->data<<endl;
		transoutput(t->lchild,i);
	}
	i--;
	return OK;
}
int main()
{
	BiTree t;
	CreateBiTree(t);
	PreOrderTraverse(t);
	cout <<endl;
	InOrderTraverse(t);
	cout << endl;
	PostOderTraverse(t);
	cout << endl;
	HieOrderTraverse(t);
	cout << endl;
	int depth = -1;
	transoutput(t, depth);
	cout << endl;
	return OK;
}