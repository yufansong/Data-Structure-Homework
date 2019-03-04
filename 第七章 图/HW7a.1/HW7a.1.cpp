#include<iostream>
#include<limits.h>
using namespace std;
#define MAX_VERTEX_NUM 1000
#define VertexType int 
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
		int a, b, i, j,w;
		cin >> a >> b>>w;
		a--;			//didn't follow the web's requirement
		b--;
		i = LocateVex(g, a);
		j = LocateVex(g, b);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = w;
		p->nextarc = g.vertices[i].firstarc;
		g.vertices[i].firstarc = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = w;
		p->nextarc = g.vertices[j].firstarc;
		g.vertices[j].firstarc = p;
	}
	return;
}
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int VRtype;
struct {
	VertexType adjvex;
	VRtype lowcost;
}closedge[MAX_VERTEX_NUM];
void MinSpanTree_Prim(ALGraph g)
{
	for (int i = 0; i < g.vexnum - 1; i++)			//initial closedge=0
		closedge[i].lowcost = 99999;
	closedge[0].lowcost = 0;		//select the start
	closedge[0].adjvex = g.vertices[0].data;
	g.vertices[0].visited = 1;
	int close_num = 1;
	for (int i = 1; i < g.vexnum; i++)						//each loop add one vex
	{
		int value = INT_MAX;
		int temp = -1;
		for (int j = 0; j < close_num; j++)
		{
			ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
			int k = closedge[j].adjvex;
			p = g.vertices[k].firstarc;
			while (p)
			{
				if (p->info < value&&g.vertices[p->adjvex].visited == 0)
				{
					value = p->info;
					temp = p->adjvex;
				}
				p = p->nextarc;
			}
		}
		if (temp == -1)
		{
			cout << "-1";
			exit(0);
		}
		g.vertices[temp].visited = 1;
		closedge[i].adjvex = temp;
		closedge[i].lowcost = value;
		close_num++;
	}
	int sum = 0;
	for (int i = 0; i < close_num; i++)
		sum += closedge[i].lowcost;
	cout << sum << endl;
	return;
}
void PrintALGraph(ALGraph g, int choice)
{
	//	for (int i = 0; i < g.vexnum; i++)
	//		cout << g.vertices[i].data <<" ";
	//	cout << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cout << g.vertices[i].data+1 << "-->";
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
		p = g.vertices[i].firstarc;
		while (p)
		{
			if (choice == 2 || choice == 4)
				cout << p->adjvex+1 << "," << p->info << " ";
			else
				cout << p->adjvex +1<< " ";
			p = p->nextarc;
		}
		cout << endl;
	}
}
int main()
{
	ALGraph g;
	CreatALGraph_adjlist(g);
//	PrintALGraph(g,2);
	MinSpanTree_Prim(g);
}