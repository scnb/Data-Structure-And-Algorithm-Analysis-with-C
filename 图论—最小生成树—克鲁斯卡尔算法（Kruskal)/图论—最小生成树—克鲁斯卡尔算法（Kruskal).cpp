// 图论—最小生成树—克鲁斯卡尔算法（Kruskal).cpp : 定义控制台应用程序的入口点。
//令最小生成树的初始状态为只有n个顶点而无边的非连通图。在边集中选择代价最小的边，若该边
//依附的顶点落在连通图中不同的连通分量上，则将此边加入到连通图中，否则舍去此边而选择下一
//条代价最小的边，直至连通图中所有顶点都在同一连通分量上为止
//parent数组的作用：对于当前的权值最小的边，通过Find函数分别找出这两个顶点的
//邻接点的邻接点的……邻接点(即一直找到头）（n和m），如果这两个邻接点相同，就说明当前这条权
//值最小的边和当前的最小生成树形成了回路（画图能够很直观的看出）

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXVEX (3)
#define INFINITY (65536)
#define MAXEDGE (4)

typedef int VertexType;
typedef int EdgeNode;

/*边的结构*/
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeNode arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph * G);
void MiniSpanTree_Kruskal(MGraph G);
void Turn2Edges(MGraph G, Edge edges[MAXEDGE]);
int Find(int parent[MAXVEX], int f);
void test(int a[], int N);

int main()
{
	MGraph G;
	CreateMGraph(&G);
	cout << "生成最小生成树：\n";
	MiniSpanTree_Kruskal(G);
	getchar();
	getchar();
    return 0;
}

void CreateMGraph(MGraph * G)
{
	int i, j, k, w;
	cout << "输入顶点个数：";
	cin >> G->numVertexes;
	cout << "输入边的个数：";
	cin >> G->numEdges;
	/*读入顶点信息，构建顶点表*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "输入第" << i + 1 << "个顶点的值：";
		cin >> G->vexs[i];
	}
	/*初始化边表*/
	for (i = 0;i < G->numVertexes;i++)
	{
		for (j = 0;j < G->numVertexes;j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = INFINITY;
			}
		}
	}
	/*读入边的信息，构建边表*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "输入边（vi，vj）的下标i，下标j和权值w：";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*如果是无向图，则是对称的矩阵，执行下面的代码*/
		G->arc[j][i] = w;
	}
}

void Turn2Edges(MGraph G,Edge edges[MAXEDGE])
{
	int i, j,k=0;
	int min_weight;
	int min_i, min_j;
	/*先把所有的边转换到edges数组中*/
	for (i = 0;i < G.numVertexes;i++)
	{
		for (j = 0;j < G.numVertexes;j++)
		{
			if (i < j)
			{
				if (G.arc[i][j] != 0 && G.arc[i][j] < INFINITY)
				{
					edges[k].begin = i;
					edges[k].end = j;
					edges[k++].weight = G.arc[i][j];
				}
			}
		}
	}
	/*转换完成之后，再进行排序*/
	Edge temp;
	for (i = 0;i < G.numEdges;i++)
	{
		for (j = i;j < G.numEdges;j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
		}
	}
}

void test(int a[],int N)
{
	int i, j;
	int temp;
	for (i = 0;i < N;i++)
	{
		for (j = i;j < N;j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];//定义边集数组
	int parent[MAXVEX];//定义一个数组用来判断边与边是否形成回路，同时也是标记哪些顶点在生成树中
	/*将邻接矩阵G转化为边集数组edges，并且按权由小到大排序*/
	Turn2Edges(G,edges);
	/*经过上面的转化以及排序后，边的权值就是由小到大排序的了*/
	for (i = 0;i < G.numVertexes;i++)
	{
		parent[i] = 0;//初始化parent数组中的值为0
	}
	for (i = 0;i < G.numEdges;i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)/*如果n≠m，则认为该边没有与现有的生成树形成环路*/
		{
			parent[n] = m;/*将该边以起点为下标，以终点为值，存入parent中*/
			cout << "（" << edges[i].begin << "，" << edges[i].end << "）" << edges[i].weight << " ";
		}
	}
}

int Find(int parent[MAXVEX], int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}