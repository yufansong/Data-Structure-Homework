#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#define MAX_VERTEX_NUM 20
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int VertexType;
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	int visited[MAX_VERTEX_NUM];
}MGraph;
int LocateVexM(MGraph g, int u)
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
	{
		 g.vexs[i]=i;
	}
	for (i = 0; i < g.arcnum; i++)
		for (j = 0; j < g.vexnum; j++)	//initial Matrix of arcs
			g.arcs[i][j] = 0;
	for (int i=0;i<g.vexnum;i++)			//initial visited
		g.visited[i] = 0;
	for (k = 0; k < g.arcnum; k++)		//set arcs
	{
			cin >> v1 >> v2;
			i = LocateVexM(g, v1);
			j = LocateVexM(g, v2);
			g.arcs[i][j] = 1;
			g.arcs[j][i] = 1;
	}
	return;
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
			cout << setw(4) << setprecision(ios::right) << g.arcs[i][j];
		cout << endl;
	}
}
void visit(MGraph &g, int i)
{
	cout << g.vexs[i];
	g.visited[i] = 1;
}
void DFS(MGraph &g, int i)
{
	visit(g, i);
	for (int j = 0; j < g.vexnum; j++)
	{
		if (g.arcs[i][j] && !g.visited[j])
		{
			cout << " ";
			DFS(g, j);
		}
	}
}
void BFS(MGraph &g, int s)
{
	int q[MAX_VERTEX_NUM];
	int front = 0;
	int rear = 0;
	int i, j;
	cout<<g.vexs[s];
	g.visited[s] = 1;
	q[rear++] = s;
	while (front<rear)
	{
		i = q[front++];
		for (j=0;j<g.vexnum;j++)
			if (!g.visited[j] && g.arcs[i][j] == 1)
			{
				cout << " "<<g.vexs[j];
				g.visited[j] = 1;
				q[rear++] = j;
			}
	}
}
int main()
{
	MGraph g;
	CreateGraph(g);
	for (int i = 0; i < g.vexnum; i++)
	{
		if (!g.visited[i])
		{
			cout << "{";
			DFS(g, i);
			cout << "}";
		}
	}
	cout << endl;
	for (int i = 0; i < g.vexnum; i++)
		g.visited[i] = 0;
	for (int i = 0; i < g.vexnum; i++)
	{
		if (!g.visited[i])
		{
			cout << "{";
			BFS(g, i);
			cout << "}";
		}
	}
}