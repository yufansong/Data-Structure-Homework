#include<iostream>
using namespace std;
typedef struct
{
    int weight;
    int parent, lchild, rchild;
	bool choice=0;
}HTNode,*HuffmanTree;
void Select(HuffmanTree &ht,int length,int &s1,int &s2)
{
	HuffmanTree p = ht;
	int tree1 =100000, tree2 = 100000;
	for (int i = 0; i <= length; i++, p++)
		if (p->weight < tree1&&p->choice==0)
		{
			tree1 = p->weight;
			s1 = i;
		}
	ht[s1].choice = 1;
	p = ht;
	for (int i = 0; i <= length; i++, p++)
		if (p->weight < tree2&&p->choice==0)
		{
			s2 = i;
			tree2 = p->weight;
		}
	ht[s2].choice = 1;
	return;
}
int main()
{
	HuffmanTree p;
	int i, s1=0, s2=0,n;
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
	for (i = n ; i < m; i++)
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
		while (n.parent!=-1)
		{
			sum += value;
			n = ht[n.parent];
		}
	}
	cout << sum << endl;
}