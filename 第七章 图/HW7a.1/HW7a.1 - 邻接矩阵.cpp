#include<iostream>
#include<iomanip>
using namespace std;
#define MAX_VERTEX_NUM 100
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int VertexType;
typedef int VRtype;
struct {
	VertexType adjvex;
	VRtype lowcost;
}closedge[MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
}MGraph;
int LocateVex(MGraph g, char u)
{
	int i;
	for (i = 0; i < g.vexnum; i++)
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
void CreateGraph(MGraph &g)
{
	int i, j, k, w;
	int v1, v2;
	cin >> g.vexnum >> g.arcnum;	//input the number of vex and arc
	for (i = 0; i < g.vexnum; i++)		//input vexs
		g.vexs[i] = i + 1;
	for (i = 0; i < g.arcnum; i++)
		for (j = 0; j < g.vexnum; j++)	//initial Matrix of arcs
			g.arcs[i][j] = 0;
	for (k = 0; k < g.arcnum; k++)		//set arcs
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(g, v1);
		j = LocateVex(g, v2);
		g.arcs[i][j] = w;
		g.arcs[j][i] = w;
	}
	return;
}
void MiniSpanTree_Prim(MGraph g, VertexType u)
{
	int i, j, k;
	int minCost;
	k = LocateVex(g, u);
	for (j = 0; j < g.vexnum; j++)
		if (j != k)
		{
			closedge[j].adjvex = u;
			closedge[j].lowcost = g.arcs[k][j];
		}
	closedge[k].lowcost = 0;
	for (i = 1; i < g.vexnum; i++)
	{
		minCost = INFINITY;
		for (j = 0; j < g.vexnum; j++)
			if (closedge[j].lowcost < minCost&&closedge[j].lowcost != 0)
			{
				minCost = closedge[j].lowcost;
				k = j;
			}
		closedge[k].lowcost = 0;
		for (j = 0; j < g.vexnum; j++)
			if (g.arcs[k][j] < closedge[j].lowcost)
			{
				closedge[j].adjvex = g.vexs[k];
				closedge[j].lowcost = g.arcs[k][j];
			}
	}
}
int main()
{
	MGraph g; 
	CreateGraph(g);
	MiniSpanTree_Prim(g, 1);
	int sum = 0;
	for (int i = 0; i < g.vexnum; i++)
		sum += closedge[i].lowcost;
	cout << sum << endl;
}
