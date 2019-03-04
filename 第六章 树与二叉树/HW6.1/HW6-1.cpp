#include<iostream>

using namespace std;
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
typedef  char TElemtype ;
typedef enum {
 Link, Thread
}PointerTag;
typedef struct BiThrNode {
	TElemtype data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
}*BiThrTree;
int PreThreading(BiThrTree &p,BiThrNode* (&pre))
{
	if (p)
	{
		if (!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!p->rchild)
			p->RTag = Thread;			//分成两步写，是为了防止pre不存在的情况
		if (pre&&pre->RTag == Thread)
			pre->rchild = p;
		pre = p;
		if (p->LTag == Link)
			PreThreading(p->lchild,pre);
		if (p->RTag == Link)
			PreThreading(p->rchild,pre);
	}
	return OK;
}
int preoder_Thr(BiThrTree t)
{
	BiThrTree p = t;
	cout << p->data;
	while (p->rchild)
	{
		if (p->LTag == Link)
			p = p->lchild;
		else
			p = p->rchild;
		cout << p->data;
	}
	return OK;
}
int CreatBiThrTree(BiThrTree &t)
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
		if (!(t = (BiThrNode*)malloc(sizeof(BiThrNode))))
		exit(OVERFLOW);
		t->data = ch;
		if (CreatBiThrTree(t->lchild)==OK)
			t->LTag=Link;
		if (CreatBiThrTree(t->rchild)==OK)
			t->RTag=Link;
	}
	return OK;
}
int InOrderTraverse(BiThrTree t,int deep)
{
	deep++;
	if (t)
	{
		if (t->RTag == Link)
			InOrderTraverse(t->rchild, deep);
		for (int i = 0; i < deep; i++)
		{
			cout << "     ";
		}
		cout << t->data << t->LTag << t->RTag<<endl;
		if (t->LTag == Link)
			InOrderTraverse(t->lchild, deep);
	}
	deep--;
	cout << endl;
	return OK;
}
int main()
{
	BiThrTree t;
	int deep = -1;
	BiThrNode *pre = NULL;
	CreatBiThrTree(t);
	pre = NULL;
	PreThreading(t, pre);
	InOrderTraverse(t, deep);
	preoder_Thr(t);
}