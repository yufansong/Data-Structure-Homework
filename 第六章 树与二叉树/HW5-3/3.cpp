#include<iostream>
#include<string>
using namespace std;
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define MAXSIZE     100
typedef char  TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef BiTree SElemtype;
typedef struct
{
	SElemtype *base;
	SElemtype *top;
	int stacksize;
}Sqstack;
int InitStack(Sqstack &s)
{
	s.base = (SElemtype*)malloc(MAXSIZE * sizeof(SElemtype));
	if (!s.base)
		return (OVERFLOW);
	s.top = s.base;
	s.stacksize = MAXSIZE;
	return OK;
}
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
int Push(Sqstack &s, SElemtype e)
{
	if (s.top - s.base >= s.stacksize)
		return ERROR;
	*s.top = e;
	s.top = s.top + 1;
	return OK;
}
int Pop(Sqstack&s, SElemtype &e)
{
	if (s.top == s.base)
		return ERROR;
	s.top = s.top - 1;
	e = *s.top;
	return OK;
}
int InOrderTraverse(BiTree t)
{
	Sqstack s;
	InitStack(s);
	BiTree p=t;
	while (p||s.base!=s.top)
	{
		if (p)
		{
			Push(s, p);
			cout << "push " << p->data << endl;
			p = p->lchild;
		}
		else
		{
			Pop(s, p);
			if (!p->data)
				return ERROR;
			cout << "pop " << endl << p->data<<endl;
			p = p->rchild;
		}
	}
	return OK;
}
int main()
{
	BiTree t;
	CreateBiTree(t);
	InOrderTraverse(t);
	cout << endl;
	return OK;
}