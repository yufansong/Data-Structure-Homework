#include<iostream>
#include<iomanip>
#include<limits.h>
using namespace std;
#define MAX_VERTEX_NUM 100
typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int ShortPathTable[MAX_VERTEX_NUM];
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef char VertexType;
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
}MGraph;
int LocateVexM(MGraph g, char u)
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
	int i, j, k;
	int v1, v2;
	cin >> g.vexnum >> g.arcnum;	//input the number of vex and arc
	for (i = 0; i < g.vexnum; i++)		//input vexs
		g.vexs[i] = i;								//vex_data=order
	for (i = 0; i < g.vexnum; i++)
		for (j = 0; j < g.vexnum; j++)	//initial Matrix of arcs
		{
			if (i == j)
				g.arcs[i][j] = 0;
			else
				g.arcs[i][j] = 99999;		//由于此处的arcs在后面会参加迪杰特斯拉的运算，所以如果用int_max会爆掉
		}
	for (k = 0; k < g.arcnum; k++)		//set arcs
	{
		cin >> v1 >> v2;
		v1--;
		v2--;
		i = LocateVexM(g, v1);
		j = LocateVexM(g, v2);
		g.arcs[i][j] = 1;
		g.arcs[j][i] = 1;
	}
	return;
}
void ShortestPath_DIJ(MGraph g, int v0, ShortPathTable &d)
{
	int final[MAX_VERTEX_NUM];
	for (int v = 0; v < g.vexnum; v++)
	{
		final[v] = false;
		d[v] = g.arcs[v0][v];
	}
	d[v0] = 0;
	final[v0] = true;
	for (int i = 0; i < g.vexnum; i++)
	{
		int v = 0;
		int min = 99999;
		for (int w = 0; w < g.vexnum; w++)
			if (!final[w])
				if (d[w] < min)
				{
					v = w;
					min = d[w];
				}
		final[v] = true;
		for (int w = 0; w < g.vexnum; w++)
			if (!final[w] && (min + g.arcs[v][w]) < d[w])
			{
				d[w] = min + g.arcs[v][w];
				if (d[w] < 0)
					cout <<" error";
			}
	}
	int num = 0;
	static int num_output=1;
	for (int i = 0; i < g.vexnum; i++)
		if (final[i]&&d[i]<=6&&d[i]>=0)
			num++;
	double rate = ((double)(num) / g.vexnum)*100;
	cout << num_output++<<": " << setiosflags(ios::fixed) << setprecision(2) << rate << "%" << endl;
}
int main()
{
	MGraph g;
	CreateGraph(g);
	ShortPathTable d;
	for (int i = 0; i < g.vexnum; i++)
		ShortestPath_DIJ(g, i, d);
}