// 图论—深度优先遍历—邻接矩阵.cpp : 定义控制台应用程序的入口点
//深度优先遍历：Deep_First_Search，又称深度优先搜索。
//对图的深度优先遍历，和树的前序遍历是一样的，都是基于递归的思想
//一个关键的要素是要标记好已经访问过的顶点，防止图中的回路导致重复访问，
//解决办法是创建一个专门的数组用来记录顶点是否被标记，在每次访问顶点前可以先判断一个visited数组中对应元素的值
//本例是基于无向图的，如果想进行有向图的示范，则只需把CreateGraph函数中对应的代码删去即可

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

bool visited[MAXVEX];//记录每一个顶点是否被访问

typedef struct
{
	int numVertexes, numEdges;
	VertexType vexs[MAXVEX];//存储顶点
	EdgeType arc[MAXVEX][MAXVEX];//存储边
}MGraph;

void CreateMGraph(MGraph * G);
void DFS(MGraph G, int i);
void DFSTraverse(MGraph G);


int main()
{
	MGraph G;
	CreateMGraph(&G);
	DFSTraverse(G);
	getchar();
	getchar();
    return 0;
}

void CreateMGraph(MGraph * G)
{
	int i, j,k,w;
	cout << "输入顶点个数：";
	cin >> G->numVertexes;
	cout << "输入边的个数：";
	cin >> G->numEdges;
	/*构建顶点表*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "输入第" << i + 1 << "个顶点的值：";
		cin >> G->vexs[i];
	}
	/*先初始化边表矩阵*/
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
	/*构建边表矩阵*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "输入（vi，vj）的下标i，下标j和权值w：\n";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*对于无向图，需要下面这句*/
		G->arc[j][i] = w;
	}
}

/*邻接矩阵的深度优先递归算法*/
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = true;
	cout << G.vexs[i];
	for (j = 0;j < G.numVertexes;j++)
	{
		if (G.arc[i][j] != 0 && G.arc[i][j] != INFINITY && !visited[j])
		{
			DFS(G, j);//向下进行递归
		}
	}
}

/*邻接矩阵的深度遍历操作*/
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0;i < G.numVertexes;i++)
	{
		visited[i] = false;
	}
	for (i = 0;i < G.numVertexes;i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
		}
	}
}