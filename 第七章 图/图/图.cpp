#include<iostream>
#include<iomanip>
#include<corecrt_math.h>
using namespace std;
#define MAX_VERTEX_NUM 20
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef char VertexType;
typedef int vVertexType;
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	int visited[MAX_VERTEX_NUM];
}MGraph;
typedef struct
{
	vVertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	int visited[MAX_VERTEX_NUM];
}mMGraph;
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	int info;
}ArcNode;
typedef struct VNode
{
	vVertexType data;
	int visited;
	ArcNode *firstarc;
}AdjList[MAX_VERTEX_NUM];
typedef struct {
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
void CreateGraph(MGraph &g, int choice, AlGraph &a)
{
	int i, j, k, w;
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
			cin >> v1 >> v2 >> w;
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
		else if (choice == 3)				//graph without direction
		{
			cin >> v1 >> v2;
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
	return;
}
void PrintALGraph(AlGraph g, int choice)
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
		int a, b, i, j;
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
int LocateVexM(mMGraph g, int u)
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
void CreateGraph(mMGraph &g)
{
	int i, j, k;
	int v1, v2;
	cin >> g.vexnum >> g.arcnum;	//input the number of vex and arc
	for (i = 0; i < g.vexnum; i++)		//input vexs
	{
		g.vexs[i] = i;
	}
	for (i = 0; i < g.arcnum; i++)
		for (j = 0; j < g.vexnum; j++)	//initial Matrix of arcs
			g.arcs[i][j] = 0;
	for (int i = 0; i<g.vexnum; i++)			//initial visited
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
void PrintMGraph(mMGraph g)
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
void visit(mMGraph &g, int i)
{
	cout << g.vexs[i];
	g.visited[i] = 1;
}
void DFS(mMGraph &g, int i)
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
void BFS(mMGraph &g, int s)
{
	int q[MAX_VERTEX_NUM];
	int front = 0;
	int rear = 0;
	int i, j;
	cout << g.vexs[s];
	g.visited[s] = 1;
	q[rear++] = s;
	while (front<rear)
	{
		i = q[front++];
		for (j = 0; j<g.vexnum; j++)
			if (!g.visited[j] && g.arcs[i][j] == 1)
			{
				cout << " " << g.vexs[j];
				g.visited[j] = 1;
				q[rear++] = j;
			}
	}
}
int main()
{
	int choose;
	cout << "请输入0：Problem 1 (图的存储结构)" << endl;
	cout << "请输入1：Problem 2 (图的遍历)" << endl;
	cout << "请输入其他：Problem 3 (图的遍历)" << endl;
	cout << "" << endl;
	cin >> choose;
	if (choose == 0)
	{
		cout << "	第1行输入一个数字1~4，1为有向图, 2为有向网, 3为无向图, 4为无向网" << endl;
		cout << "	第2行输入2个整数n m，分别表示顶点数和边数，空格分割" << endl;
		cout << "	第3行为n个字符的序列，一个字符表示一个顶点" << endl;
	}
	else if (choose == 1)
	{
		cout << "	第1行输出dfs的结果" << endl;
		cout << "	第2行输出bfs的结果" << endl;
		mMGraph g;
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
	else
	{
		cout << "第1行输入2个整数n m，分别表示顶点数和边数，空格分割" << endl;
		cout << "	后面m行，每行输入边的两个顶点编号，空格分割" << endl;
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
}
/*
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
*/