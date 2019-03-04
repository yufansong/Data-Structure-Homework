#include<iostream>
#include<iomanip>
#include<corecrt_math.h>
using namespace std;
#define MAX_VERTEX_NUM 20
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef char VertexType;
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
}MGraph;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	int info;
}ArcNode;
typedef struct VNode {
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList vertices;
	int vexnum, arcnum;
}AlGraph;
int LocateVexAL(AlGraph g, char u)
{
	int i;
	for (i = 0; i < g.vexnum; i++)
	{
		if (u == g.vertices[i].data)
			return i;
	}
	if (i == g.vexnum)
	{
		cout << "Error" << endl;
		exit(1);
	}
	return 0;
}
int LocateVexM(MGraph g, char u)
{
	int i;
	for ( i = 0; i < g.vexnum; i++)
	{
		if (u == g.vexs[i])
			return i;
	}
	if (i == g.vexnum)
	{
		cout << "Error" << endl;
		exit(0);
	}
	return 0;
}
void CreateGraph(MGraph &g,int choice,AlGraph &a)
{
	int i,j,k,w;
	ArcNode *p;
	char v1, v2;
	cin >> g.vexnum >> g.arcnum;	//input the number of vex and arc
	a.vexnum = g.vexnum;
	a.arcnum = a.arcnum;
	for (i = 0; i < g.vexnum; i++)		//input vexs
	{
		cin >> g.vexs[i];
		a.vertices[i].data = g.vexs[i];
		a.vertices[i].firstarc = NULL;
	}
	for (i = 0; i < g.arcnum; i++)
		for (j = 0; j < g.vexnum; j++)	//initial Matrix of arcs
			g.arcs[i][j] = 0;
	for (k = 0; k < g.arcnum; k++)		//set arcs
	{
		if (choice == 1)					//graph with direction
		{
			cin >> v1 >> v2;
			i = LocateVexM(g, v1);
			j = LocateVexM(g, v2);
			g.arcs[i][j] = 1;
			i = LocateVexAL(a, v1);
			j = LocateVexAL(a, v2);
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = j;
			p->info = 1;
			p->nextarc = a.vertices[i].firstarc;
			a.vertices[i].firstarc = p;
		}
		else if (choice == 2)				//net (graph with weight )with direction
		{
			cin >> v1 >> v2>>w;
			i = LocateVexM(g, v1);
			j = LocateVexM(g, v2);
			g.arcs[i][j] = w;
			i = LocateVexAL(a, v1);
			j = LocateVexAL(a, v2);
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = j;
			p->info = w;
			p->nextarc = a.vertices[i].firstarc;
			a.vertices[i].firstarc = p;
		}
		else if (choice==3)				//graph without direction
		{
			cin >> v1 >> v2 ;
			i = LocateVexM(g, v1);
			j = LocateVexM(g, v2);
			g.arcs[i][j] = 1;
			g.arcs[j][i] = 1;
			i = LocateVexAL(a, v1);
			j = LocateVexAL(a, v2);
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = j;
			p->info = 1;
			p->nextarc = a.vertices[i].firstarc;
			a.vertices[i].firstarc = p;
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = i;
			p->info = 1;
			p->nextarc = a.vertices[j].firstarc;
			a.vertices[j].firstarc = p;
		}
		else										//net without direction
		{
			cin >> v1 >> v2 >> w;
			i = LocateVexM(g, v1);
			j = LocateVexM(g, v2);
			g.arcs[i][j] = w;
			g.arcs[j][i] = w;
			i = LocateVexAL(a, v1);
			j = LocateVexAL(a, v2);
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = j;
			p->info = w;
			p->nextarc = a.vertices[i].firstarc;
			a.vertices[i].firstarc = p;
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = i;
			p->info = w;
			p->nextarc = a.vertices[j].firstarc;
			a.vertices[j].firstarc = p;
		}
	}
	return ;
}
void PrintMGraph(MGraph g)
{
	int i, j;
	for (i = 0; i < g.vexnum; i++)
		cout << g.vexs[i] << " ";
	cout << endl;
	for (i = 0; i < g.vexnum; i++)
	{
		for (j = 0; j < g.vexnum; j++)
			cout << setw(4)<<setprecision(ios::right)<<g.arcs[i][j];
		cout << endl;
	}
}
void PrintALGraph(AlGraph g,int choice)
{
//	for (int i = 0; i < g.vexnum; i++)
//		cout << g.vertices[i].data <<" ";
//	cout << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cout << g.vertices[i].data << "-->";
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
		p = g.vertices[i].firstarc;
		while (p)
		{
			if (choice == 2 || choice == 4)
				cout << p->adjvex << "," << p->info << " ";
			else
				cout << p->adjvex << " ";
			p = p->nextarc;
		}
		cout << endl;
	}
}
int main ()
{
	int choice;
	MGraph g;
	AlGraph al;
	cin >> choice;
	CreateGraph(g, choice, al);
	PrintMGraph(g);
	PrintALGraph(al,choice);
}
