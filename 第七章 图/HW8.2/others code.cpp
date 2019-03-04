#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
using namespace std;

#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2

typedef struct BiTNode
{
	int data;
	struct BiTNode *lc, *rc;  //左右孩子指针
}BiTNode, *BiTree;

int n;
int num,sum;

int Search_BST(BiTree T, int key, BiTree f, BiTree &p)
{
	if (!T)
	{
		p = f;
		return FALSE;
	}
	else if (key == T->data)
	{
		p = T;
		return TRUE;
	}
	else if (key<T->data)
		return Search_BST(T->lc, key, T, p);
	else
		return Search_BST(T->rc, key, T, p);
}

int Insert_BST(BiTree &T, int x)
{
	BiTree p;
	if (!Search_BST(T, x, NULL, p))
	{
		BiTree s = (BiTree)malloc(sizeof(BiTNode));
		s->data = x;
		s->lc = s->rc = NULL;
		if (!p)
			T = s;
		else if (x<p->data)
			p->lc = s;
		else
			p->rc = s;
		return TRUE;
	}
	else
		return FALSE;
}

int Delete(BiTree &p)
{
	if (!p->rc)
	{
		BiTree q = p;
		p = p->lc;
		free(q);
	}
	else if (!p->lc)
	{
		BiTree q = p;
		p = p->rc;
		free(q);
	}
	else
	{
		BiTree q = p;
		BiTree s = p->lc;
		while (s->rc)
		{
			q = s;
			s = s->rc;
		}
		p->data = s->data;
		if (q != p)
			q->rc = s->lc;
		else
			q->lc = s->lc;
		free(s);
	}
	return TRUE;
}

int Delete_BST(BiTree &T, int key)
{
	if (!T)
		return FALSE;
	else
	{
		if (key == T->data)
			return Delete(T);
		else if (key<T->data)
			return Delete_BST(T->lc, key);
		else
			return Delete_BST(T->rc, key);
	}
}

void Pre_Order_Traverse(BiTree T,int i)  //先序遍历
{
	if (!T)return;
	cout << T->data << ' ';
	num++;
	sum+=i;
	Pre_Order_Traverse(T->lc,i+1);
	Pre_Order_Traverse(T->rc,i+1);
	return;
}

int main()
{
	BiTree T = NULL;
	cin >> n;
	int x;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		Insert_BST(T, x);
	}
	cin >> x;
	cout << Delete_BST(T, x) << endl;
	cout << !Insert_BST(T, x) << endl;
	Pre_Order_Traverse(T,1);
	cout << endl;
	cout<<fixed<<setprecision(2)<<double(sum)/double(num);
	return 0;
}
