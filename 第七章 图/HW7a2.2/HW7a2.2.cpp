#include<iostream>
#include<limits.h>
using namespace std;
#define MAX_VERTEX_NUM 1000
#define VertexType int 
#define STACK_INIT_SIZE 100
#define SElemType int 
#define STACKINCREMENT 100
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW     -2
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
int InitStack(SqStack &s, int n)   //初始化栈
{
	s.base = (SElemType *)malloc((n) * sizeof(SElemType));
	if (!s.base)return (OVERFLOW);
	s.top = s.base;
	s.stacksize = n;
	return OK;
}
int Push(SqStack &s, SElemType e)   //入栈操作
{
	if (s.top - s.base >= s.stacksize) return ERROR;
	*s.top = e;
	s.top = s.top + 1;
	return OK;
}
int Pop(SqStack &s, SElemType &e)   //出栈操作
{
	if (s.top == s.base)return ERROR;
	s.top = s.top - 1;
	e = *s.top;
	return OK;
}
//============================================
typedef struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
	int info;
}ArcNode;
typedef struct VNode
{
	VertexType data;
	int visited;
	ArcNode *firstarc;
}AdjList[MAX_VERTEX_NUM];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;
int LocateVex(ALGraph g, int x)
{
	int i = 0;
	for (i = 0; i < g.vexnum; i++)
		if (x == g.vertices[i].data)
			return i;
	cout << "Error" << endl;
	return 0;
}
void CreatALGraph_adjlist(ALGraph &g)
{
	ArcNode *p;
	cin >> g.vexnum >> g.arcnum;
	for (int i = 0; i < g.vexnum; i++)
	{
		g.vertices[i].visited = 0;
		g.vertices[i].data = i;
		g.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k<g.arcnum; k++)
	{
		int a, b, i, j, w;
		cin >> a >> b >> w;
		a--;			//didn't follow the web's requirement
		b--;
		i = LocateVex(g, a);
		j = LocateVex(g, b);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;							
		p->info = w;
		p->nextarc = g.vertices[i].firstarc;
		g.vertices[i].firstarc = p;
	}
	return;
}
//=================================
void FindInDegree(ALGraph g, int indegree[])		//根据不同的邻接表有区别，这个函数为逆邻接表
{
	for (int i = 0; i < g.vexnum; i++)
		indegree[i] = 0;
	for (int i = 0; i < g.vexnum; i++)
	{
		ArcNode* p = g.vertices[i].firstarc;
		while (p)
		{
			indegree[p->adjvex]++;					
			p = p->nextarc;
		}
	}
	return;
}
int topo_sort(ALGraph g,SqStack &t,int ve[])
{
	int indegree[MAX_VERTEX_NUM];
	int count = 0;
	SqStack s;
	InitStack(s, g.vexnum);
	FindInDegree(g, indegree);
	for (int i = 0; i < g.vexnum; i++)
		ve[i] = 0;
	for (int i = 0; i < g.vexnum; i++)
		if (!indegree[i])
			Push(s, i);
	while (s.base != s.top)
	{
		int i;
		Pop(s, i);
		Push(t, i);
		count++;
		ArcNode* p = g.vertices[i].firstarc;
		for (; p; p = p->nextarc)
		{
			int k = p->adjvex;
			indegree[k]--;
			if (!indegree[k])
				Push(s, k);
			if (ve[i] + p->info > ve[k])
				ve[k] = ve[i] + p->info;
		}
	}
	if (count < g.vexnum)
		return 0;
	else
		return ve[g.vexnum];
}
void CriticalPath(ALGraph g)
{
	SqStack t;
	int ve[MAX_VERTEX_NUM],vl[MAX_VERTEX_NUM];
	InitStack(t, g.vexnum);
	if (!topo_sort(g, t, ve))
	{
		cout << "0" << endl;
		return;
	}
	cout << ve[g.vexnum - 1] << endl;;
	for (int i = 0; i < g.vexnum; i++)
		vl[i] = ve[g.vexnum-1];
	int k = 0;
	while (t.base!=t.top)
	{
		ArcNode *p = NULL;
		int j = 0;
		for (Pop(t, j), p = g.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			if (vl[k] - p->info < vl[j])
				vl [j] = vl[k] - p->info;
		}
	}
	for (int j = 0; j < g.vexnum; j++)
	{
		ArcNode *p = NULL;
		for (p = g.vertices[j].firstarc;p; p = p->nextarc)
		{
			int k = p->adjvex, weight = p->info;
			if (ve[j] == vl[k] - weight)
				cout << j + 1 << "->" << k + 1<<endl;
		}
	}
	return;
}
int main()
{
	ALGraph g;
	CreatALGraph_adjlist(g);
	CriticalPath(g);
}