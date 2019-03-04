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
}BiTNode, *BiTree;
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
		cout << "QUEUE FULL" << endl;
	else
	{
		q.data[q.rear] = t;
		q.rear++;
	}
	return OK;
}
int Sq_del(seqqueue &q, BiTree &t)
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
	while (q.front != q.rear)
	{
		Sq_del(q, t);
		cout << t->data;
		if (t->lchild)
			Sq_enter(q, t->lchild);
		if (t->rchild)
			Sq_enter(q, t->rchild);
	}

	return OK;
}
int transoutput(BiTree t, int &i)
{
	i++;
	if (t)
	{
		transoutput(t->rchild, i);
		for (int j = 0; j < i; j++)
		{
			cout << "     ";
		}
		cout << t->data << endl;
		transoutput(t->lchild, i);
	}
	i--;
	return OK;
}
//======================================
int CreateBiTree(BiTree &t, int &leaves, int &sum, int &depth, int &maxdep)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		t = NULL;
		return ERROR;
	}
	else
	{
		depth++;
		if (depth > maxdep)
			maxdep = depth;
		if (!(t = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		t->data = ch;
		sum++;
		bool flag1 = 0, flag2 = 0;
		flag1 = CreateBiTree(t->lchild, leaves, sum, depth, maxdep);
		flag2 = CreateBiTree(t->rchild, leaves, sum, depth, maxdep);
		if (flag1 == 0 && flag2 == 0)
			leaves++;
	}
	depth--;
	return OK;
}
int Tr_CreateBiTree(BiTree &t, string s, int &i)
{
	char ch;
	i++;
	ch = s[i];
	if (ch == '#')
		t = NULL;
	else
	{
		if (!(t = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		t->data = ch;
		Tr_CreateBiTree(t->rchild, s, i);
		Tr_CreateBiTree(t->lchild, s, i);
	}
	return OK;
}
int Trs_PreOrderTraverse(BiTree t, string &s)
{
	if (t)
	{
		s += t->data;
		Trs_PreOrderTraverse(t->lchild, s);
		Trs_PreOrderTraverse(t->rchild, s);
	}
	else
		s += '#';
	return OK;
}
int PreOrderTraverse(BiTree t, string &s)
{
	if (t)
	{
		s += t->data;
		PreOrderTraverse(t->lchild, s);
		PreOrderTraverse(t->rchild, s);
	}
	else
		s += '#';
	return OK;
}
//===================================
int main()
{
	int choice = 0;
	cout << "二叉树的创建、先序、中序、后序、层序遍历以及转置输出请输入0" << endl;
	cout << "二叉树的深度，节点数，叶数，对称二叉树的转置输出请输入1" << endl;
	cin >> choice;
	if (choice == 0)
	{
		cout << "输入先序序列，内部结点用一个字符表示，空结点用#表示" << endl;
		BiTree t;
		CreateBiTree(t);
		PreOrderTraverse(t);
		cout << endl;
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
	else 
	{
		cout << "输入先序序列，内部结点用一个字符表示，空结点用#表示" << endl;
		BiTree t;
		int leaves = 0, sum = 0, depth = 0, maxdep = 0;
		CreateBiTree(t, leaves, sum, depth, maxdep);
		cout << leaves << endl << sum << endl << maxdep << endl;
		depth = -1;
		transoutput(t, depth);
		cout << endl;
		cout << endl;
		string s = "";
		PreOrderTraverse(t, s);
		int i = -1;
		BiTree transtree;
		Tr_CreateBiTree(transtree, s, i);
		depth = -1;
		transoutput(transtree, depth);
		return OK;

	}
}