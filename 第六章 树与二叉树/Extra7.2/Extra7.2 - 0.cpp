#include<iostream>
#include<string.h>
#pragma warning(disable : 4996)
using namespace std;
typedef struct
{
	int weight;
	int parent, lchild, rchild;//从0开始计算
}HTNode, *HuffmanTree;
typedef char **HuffmanCode;
int main()
{
	HuffmanTree p;
	int i, s1 = 0, s2 = 0, n;
	cin >> n;
	int m = 2 * n - 1;
	HuffmanTree ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for (p = ht, i = 1; i <= m; i++, p++)
	{
		p->parent = -1;
		p->lchild = -1;
		p->rchild = -1;
	}
	for (p = ht, i = 0; i < m; i++, p++)
	{
		cin >> p->weight;
		int parent = -1;
		cin >> parent;
		p->parent = parent - 1;
		int choice = 0;
		cin >> choice;
		if (choice == 0)
			ht[p->parent].lchild = i;
		else
			ht[p->parent].rchild = i;
//		cout << i << "   " << ht[i].parent << "  " << ht[i].lchild << "  " << ht[i].rchild << "  " << ht[i].weight << endl;
//		cout << endl;
	}
	char* cd = (char*)malloc(n * sizeof(char));
	HuffmanCode	hc = (HuffmanCode)malloc((n) * sizeof(char*));
	cd[n - 1] = '\0';
	for (i = 0; i < n; i++)
	{
		int start = n-1;
		int parent;
		for (int j = i, parent = ht[j].parent; parent !=-1; j=parent,parent = ht[parent].parent)
		{
			if (ht[parent].lchild == j)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		hc[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);
		cout << i + 1 << " " << hc[i]<<endl;
	}
}