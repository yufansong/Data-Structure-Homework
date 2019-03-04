#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
void CreatBiTree(BiTree &t)
{
	int n;
	cin >> n;
	t->lchild = NULL;
	t->rchild = NULL;
	t->data = 0;
	for (int i = 0; i < n; i++)
	{
		int code = 0;
		string s;
		char c;
		cin >> s;
		if (s[1] >= '0'&&s[1] <= '9')
			c = ' ';
		else
		{
			c = s[0];
			cin >> s;
		}
		BiTree p=NULL,temp=t;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '0')
			{
				if (temp->lchild)
					temp = temp->lchild;
				else
				{
					p = (BiTree)malloc(sizeof(BiTNode));
					p->lchild = NULL;
					p->rchild = NULL;
					p->data = 0;
					temp->lchild = p;
					temp = p;
				}
			}
			else
			{
				if (temp->rchild)
					temp = temp->rchild;
				else
				{
					p = (BiTree)malloc(sizeof(BiTNode));
					p->lchild = NULL;
					p->rchild = NULL;
					p->data = 0;
					temp->rchild = p;
					temp = p;
				}
			}
		}
		p->data = c;
	}
}
void decode(BiTree t,string s)
{
	BiTree temp = (BiTree)malloc(sizeof(BiTNode));
	temp = t;
	for (int i = 0; i <= s.length(); i++)
	{
		if (!temp->lchild&&!temp->rchild)
		{
			cout << temp->data;
			temp = t;
			i--;
		}
		else
		{
			if (s[i] == '0')
				temp = temp->lchild;
			else
				temp = temp->rchild;
		}
	}
	cout << endl;
	return;
}
int main()
{
	BiTree t=(BiTree)malloc(sizeof(BiTNode));
	CreatBiTree(t);
	string s;
	cin >> s;
	decode(t,s);
	return 0;
}
