#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
typedef struct
{
	int weight;
	int parent, lchild, rchild;
	bool choice = 0;
}HTNode, *HuffmanTree;
typedef struct
{
	unsigned int wight;
	unsigned int parent, lchild, rchild;
}hHNode, *hHuffmanTree;
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
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
		BiTree p = NULL, temp = t;
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
void decode(BiTree t, string s)
{
	BiTree temp = (BiTree)malloc(sizeof(BiTNode));
	temp = t;
	for (int i = 0; i <= s.length(); i++)
	{
		if (!temp->lchild && !temp->rchild)
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
void Select(HuffmanTree &ht, int length, int &s1, int &s2)
{
	HuffmanTree p = ht;
	int tree1 = 100000, tree2 = 100000;
	for (int i = 0; i <= length; i++, p++)
		if (p->weight < tree1&&p->choice == 0)
		{
			tree1 = p->weight;
			s1 = i;
		}
	ht[s1].choice = 1;
	p = ht;
	for (int i = 0; i <= length; i++, p++)
		if (p->weight < tree2&&p->choice == 0)
		{
			s2 = i;
			tree2 = p->weight;
		}
	ht[s2].choice = 1;
	return;
}
int main()
{
	int choice;
	cout << "������0�������������ֳ�����������һ���Ȩ·��������̵�����"<<endl;
	cout << "������1��˫�ױ�ʾ����������������������������롣" << endl;
	cout << "�������������Թ���������������롣" << endl;
	cin >> choice;
	if (choice == 0)
	{
		cout << "��1��һ��������n, ��ʾҶ�ӽ����" << endl;
		cout << "��2��n��������, ��ʾҶ�ӽ���Ȩֵ" << endl;
		HuffmanTree p;
		int i, s1 = 0, s2 = 0, n;
		cin >> n;
		int m = 2 * n - 1;
		HuffmanTree ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
		for (p = ht, i = 1; i <= n; i++, p++)
		{
			cin >> p->weight;
			p->parent = 0;
			p->lchild = 0;
			p->rchild = 0;
			p->choice = 0;
		}
		for (; i < m; i++, p++)
		{
			p->weight = 0;
			p->parent = 0;
			p->lchild = 0;
			p->rchild = 0;
			p->choice = 0;
		}
		for (i = n; i < m; i++)
		{
			Select(ht, i - 1, s1, s2);
			ht[s1].parent = i;
			ht[s2].parent = i;
			ht[i].lchild = s1;
			ht[i].rchild = s2;
			ht[i].weight = ht[s1].weight + ht[s2].weight;
			ht[i].parent = -1;
			//		cout << s1 << "   " << ht[s1].parent << "  " << ht[s1].lchild << "  " << ht[s1].rchild << "  " << ht[s1].weight << "  " << ht[s1].choice << endl;
			//		cout << s2 << "   " << ht[s2].parent << "  " << ht[s2].lchild << "  " << ht[s2].rchild << "  " << ht[s2].weight << "  " << ht[s2].choice << endl;
			//		cout << i << "   " << ht[i].parent << "  " << ht[i].lchild << "  " << ht[i].rchild << "  " << ht[i].weight << "  " << ht[i].choice << endl;
			//		cout << endl;

		}
		int sum = 0;
		for (i = 0; i < n; i++)
		{
			HTNode n = ht[i];
			int value = n.weight;
			while (n.parent != -1)
			{
				sum += value;
				n = ht[n.parent];
			}
		}
		cout << sum << endl;
	}
	else if (choice == 1)
	{
		cout << "��1��һ��������n, ��ʾҶ�ӽ����" << endl;
		cout << "��������2*n-1�У�ÿ��3����wi,pi,li(i��1��ʼ)�ֱ������������н���Ȩֵ,��˫�׽��ı��,����˫�׵�������liΪ0������Ϊ1";
		cout<<"������˫����0��ʾ��" << endl;
		hHuffmanTree p;
		int i, s1 = 0, s2 = 0, n;
		cin >> n;
		int m = 2 * n - 1;
		hHuffmanTree ht = (hHuffmanTree)malloc((m + 1) * sizeof(hHNode));
		for (p = ht, i = 1; i < m; i++, p++)
		{
			p->parent = 0;
			p->lchild = 0;
			p->rchild = 0;
		}
		for (p = ht, i = 0; i < m; i++, p++)
		{
			cin >> p->wight;
			cin >> p->parent;
			int choice;
			cin >> choice;
			//if (p->parent!=0)
			if (choice == 0)
				ht[p->parent - 1].lchild = i + 1;
			else
				ht[p->parent - 1].rchild = i + 1;
		}
		char cd[100];
		for (i = 1; i <= n; i++)
		{
			int  end = 0;
			int c = i;
			int f = ht[c - 1].parent;
			while (f)
			{
				if (ht[f - 1].lchild == c)
				{
					cd[end] = '0';
					end++;
				}
				else
				{
					cd[end] = '1';
					end++;
				}
				c = f;
				f = ht[f - 1].parent;
			}
			cout << i << " ";
			int j;
			for (j = end - 1; j >= 0; j--)
			{
				cout << cd[j];
			}
			cout << endl;
		}
	}
	else
	{
		cout << "��1��һ��������n, ��ʾ�ַ�������" << endl;
		cout << "����n�У�ÿ�е�һ�����ַ�����2���Ǹ��ַ��Ĺ��������룬������ַ�֮����һ���ո�ָ" << endl;
		cout << "���һ����һ���ı��Ĺ���������" << endl;
		BiTree t = (BiTree)malloc(sizeof(BiTNode));
		CreatBiTree(t);
		string s;
		cin >> s;
		decode(t, s);
		return 0;
	}
}