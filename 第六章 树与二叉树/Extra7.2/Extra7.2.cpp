#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
typedef struct
{
	unsigned int wight;
	unsigned int parent, lchild, rchild;
}HNode,*HuffmanTree;
typedef char **HuffmanCode;
int main()
{
	HuffmanTree p;
	int i, s1 = 0, s2 = 0, n;
	cin >> n;
	int m = 2 * n - 1;
	HuffmanTree ht = (HuffmanTree)malloc((m+1)*sizeof(HNode));
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
		int  end=0;
		int c = i;
		int f = ht[c-1].parent;
		while(f)
		{
			if (ht[f-1].lchild == c)
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
			f = ht[f-1].parent;
		}
		cout << i << " ";
		int j;
		for ( j = end-1; j>=0; j--)
		{
			cout << cd[j];
		}
		cout << endl;
	}
}