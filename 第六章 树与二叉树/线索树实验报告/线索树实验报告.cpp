#include<iostream>
using namespace std;
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
typedef  char TElemtype;
typedef enum {
	Link, Thread
}PointerTag;
typedef struct BiThrNode {
	TElemtype data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
}*BiThrTree;
int PreThreading(BiThrTree &p, BiThrNode* (&pre))
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
			PreThreading(p->lchild, pre);
		if (p->RTag == Link)
			PreThreading(p->rchild, pre);
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
		if (CreatBiThrTree(t->lchild) == OK)
			t->LTag = Link;
		if (CreatBiThrTree(t->rchild) == OK)
			t->RTag = Link;
	}
	return OK;
}
int InOrderTraverse(BiThrTree t, int deep)
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
		cout << t->data << t->LTag << t->RTag << endl;
		if (t->LTag == Link)
			InOrderTraverse(t->lchild, deep);
	}
	deep--;
	cout << endl;
	return OK;
}
int InThreading(BiThrTree &p, BiThrNode* (&pre))
{
	if (p)
	{
		InThreading(p->lchild, pre);
		if (!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!p->rchild)
			p->RTag = Thread;
		if (pre&&pre->RTag == Thread)
			pre->rchild = p;
		pre = p;
		InThreading(p->rchild, pre);
	}
	return OK;
}
int inorder_Thr(BiThrTree t)
{
	BiThrTree p = t;
	while (p->LTag == Link)
		p = p->lchild;
	cout << p->data;
	while (p->rchild)
	{
		if (p->RTag == Link)
		{
			p = p->rchild;
			while (p->LTag == Link)
				p = p->lchild;
		}
		else
			p = p->rchild;
		cout << p->data;
	}
	return OK;
}
void In_Order_Visit(BiThrTree t, char c, BiThrTree&n, BiThrTree &pre, BiThrTree &succ)
{
	if (!t)
		return;
	while (t)
	{
		while (t->LTag == Link)
			t = t->lchild;
		//   cout << t->data;
		if (n && !succ)
			succ = t;
		if (t->data == c)
			n = t;
		if (!n)
			pre = t;
		while (t->rchild&&t->RTag == Thread)
		{
			t = t->rchild;
			//	cout << t->data;
			if (n && !succ)
				succ = t;
			if (t->data == c)
				n = t;
			if (!n)
				pre = t;
		}
		t = t->rchild;
	}
	return;
}
int main()
{
	cout << "先序遍历，输入0，中序遍历输入1"<<endl;
	int choice = 0;
	cin >> choice;
	if (choice==0)
	{
		cout << "先序线索化，先序遍历线索二叉树、输出二叉树"<<endl;
		cout << "一行，输入先序序列，内部结点用一个字符表示，空结点用#表示"<<endl;
		BiThrTree t;
		int deep = -1;
		BiThrNode *pre = NULL;
		CreatBiThrTree(t);
		pre = NULL;
		PreThreading(t, pre);
		InOrderTraverse(t, deep);
		preoder_Thr(t);
		cout << endl;
	}
	else
	{
		cout << "中序遍历线索二叉树的基本操作，包括中序线索化，中序遍历线索二叉树、查找某元素的中序遍历的后继结点，前驱结点"<<endl;
		cout << "第1行，输入先序序列，内部结点用一个字符表示，空结点用#表示"<<endl;
		cout<<"第2行，输入一个字符c，查找该字符的后继结点元素和前驱结点元素"<<endl;
		BiThrTree t;
		char ch = NULL;
		BiThrNode *pre = NULL;
		CreatBiThrTree(t);
		cin >> ch;
		InThreading(t, pre);
		inorder_Thr(t);
		cout << endl;
		BiThrTree n = NULL, prev = NULL, succ = NULL;
		In_Order_Visit(t, ch, n, prev, succ);
		if (n)
		{
			if (succ)
				cout << "succ is " << succ->data << succ->RTag << endl;
			else
				cout << "succ is NULL" << endl;
			if (prev)
				cout << "prev is " << prev->data << prev->LTag << endl;
			else
				cout << "prev is NULL" << endl;
		}
		else
			cout << "Not found";
		return 0;
	}
}