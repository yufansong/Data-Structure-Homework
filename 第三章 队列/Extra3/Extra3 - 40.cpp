#include<iostream>
#include<string>
using namespace std;
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define ElemType string
#define MAXSIZE 100
int m = 0,n=0;
typedef struct
{
	ElemType data="";
	int cur=NULL;
}component,SLinkList[MAXSIZE];
void InitialSpace_SL(SLinkList & space,int m)
{
	for (int i = 1; i < m - 1; i++)
		space[i].cur = i + 1;
	space[0].data = "N/A";
	space[1].data = "N/A";
	space[m-1].data = "N/A";
	space[0].cur = -1;
	space[m - 1].cur = -1;
	return;
}
int Malloc_SL(SLinkList &space)
{
	int i = space[1].cur;
	if (i == -1)
	{
		cout << "FULL";
		return ERROR;
	}
	if ((space[1].cur != -1&&space[1].cur)||(i==m-1))
	{
		if (i!=m-1)
			space[1].cur = space[i].cur;
		else
			space[1].cur=-1;
		return i;
	}
	else
	{
		cout << "FULL";
		return ERROR;
	}
}
void Print_SL(SLinkList space)
{
	for (int i = 0; i < m; i++)
	{
		cout << i << " : " << space[i].data << " : " << space[i].cur;
		if ((i + 1) % 3 == 0)
			cout << endl;
		else
			cout << "		";
	}
}
void Insert_SL(SLinkList &space,int position)
{
	if (position > n+1)
		cout << -1<<endl;
	else
	{
		int cur = 0;
		for(int i=1;i<position;i++)
		{
			cur = space[cur].cur;
		}
		int i = Malloc_SL(space);
		cin >> space[i].data;
		n++;
		space[i].cur = space[cur].cur;
		space[cur].cur = i;
		cur = space[0].cur;
		for (int j = 0; j < n; j++)
		{
			cout << space[cur].data << " ";
			cur = space[cur].cur;
		}
		cout <<endl;
	}
}
void Free_SL(SLinkList &space, int k)
{
	space[k].cur = space[1].cur;
	space[1].cur = k;
}
void Delet_SL(SLinkList &space)
{
	int position = 0;
	cin >> position;
	if (position > n)
		cout << -1;
	if (space[0].cur == -1)
		cout << "EMPTY";
	else
	{
		int cur = 0;
		int i = 1;
		for (i = 1; i < position; i++)
		{
			cur = space[cur].cur;
		}
		i = space[cur].cur;
		cout << space[i].data<<endl;
		space[cur].cur = space[space[cur].cur].cur;
		Free_SL(space, i);
		cur = space[0].cur;
		n--;
	}
}
void Search_SL(SLinkList &space)
{
	string s;
	cin >> s;
	int cur = space[0].cur;
	bool flag = false;
	for (int j = 0; j < n; j++)
	{
		if (space[cur].data == s)
		{
			cout << j + 1<<endl;
			flag = true;
		}
		cur = space[cur].cur;
	}
	if (flag == false)
		cout << -1<<endl;
}
int main()
{
	SLinkList space;
	cin >> m >> n;
	InitialSpace_SL(space,m);
	int r = 0;
	for (int j = 0; j < n; j++)
	{
		int i = Malloc_SL(space);
		cin >> space[i].data;
		space[r].cur = i;
		r = i;
	}
	space[r].cur = -1;
	for (int j = r+1; j < m; j++)
		space[j].data = "N/A";
	Print_SL(space);
	int position = 1;
	cin >> position;
	Insert_SL(space,position);
	Delet_SL(space);
	Search_SL(space);
	position = n+1;
	Insert_SL(space, position);
	Print_SL(space);
}