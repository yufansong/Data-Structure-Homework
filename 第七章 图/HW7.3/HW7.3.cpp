#include<iostream>
using namespace std;
#define MAX_VERTEX_NUM 20
#define VertexType int 
typedef struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
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
	for (int k=0;k<g.arcnum;k++)
	{
		int a, b,i,j;
		cin >> a >> b;
		i = LocateVex(g, a);
		j = LocateVex(g, b);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = g.vertices[i].firstarc;
		g.vertices[i].firstarc = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = g.vertices[j].firstarc;
		g.vertices[j].firstarc = p;
	}
	return;
}
void DFS(ALGraph &g, int v)
{
	ArcNode *p;
	cout << g.vertices[v].data;
	g.vertices[v].visited = 1;
	p = g.vertices[v].firstarc;
	while (p)
	{
		if (!g.vertices[p->adjvex].visited)
		{
			cout << " ";
			DFS(g, p->adjvex);
		}
		p = p->nextarc;
	}
}
void BFS(ALGraph &g, int v)
{
	ArcNode *p;
	int rear = 0, front = 0;
	VertexType q[MAX_VERTEX_NUM];
	for (int i = 0; i < MAX_VERTEX_NUM; i++)
		q[i] = -1;
	cout << g.vertices[v].data;
	g.vertices[v].visited = 1;
	q[rear++] = v;
	while (rear != front)
	{
		v = q[front++];
		p = g.vertices[v].firstarc;
		while (p)
		{
			if (!g.vertices[p->adjvex].visited)
			{
				cout << " " << g.vertices[p->adjvex].data;
				g.vertices[p->adjvex].visited = 1;
				q[rear++] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}
int main()
{
	ALGraph g;
	CreatALGraph_adjlist(g);
	for (int v = 0; v < g.vexnum; v++)
		g.vertices[v].visited = 0;
	for (int v = 0; v < g.vexnum; v++)
		if (!g.vertices[v].visited)
		{
			cout << "{";
			DFS(g, v);
			cout << "}";
		}
	cout << endl;
	for (int v = 0; v < g.vexnum; v++)
		g.vertices[v].visited = 0;
	for (int v = 0; v < g.vexnum; v++)
		if (!g.vertices[v].visited)
		{
			cout << "{";
			BFS(g, v);
			cout << "}";
		}
}