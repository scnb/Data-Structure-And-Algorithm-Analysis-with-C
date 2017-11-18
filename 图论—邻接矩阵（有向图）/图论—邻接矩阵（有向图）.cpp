// 图论—邻接矩阵（有向图）.cpp : 定义控制台应用程序的入口点。
//本例以有向图为例

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

typedef struct
{
	VertexType vexs[MAXVEX];//存储顶点
	EdgeType arc[MAXVEX][MAXVEX];//存储边
	int numVertexes, numEdges;//分别为顶点个数、边数
}MGraph;

void CreateMGraph(MGraph * G);
void ShowMGraph(MGraph G);

int main()
{
	MGraph G;
	CreateMGraph(&G);
	cout << "显示数组:\n";
	ShowMGraph(G);
	getchar();
	getchar();
	return 0;
}


/*以无向图为例*/
void CreateMGraph(MGraph * G)
{
	int i, j, k, w;
	cout << "输入顶点数：";
	cin >> G->numVertexes;
	cout << "输入边数：";
	cin >> G->numEdges;
	/*建立顶点表*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "输入第" << i+1 << "个顶点的值：";
		cin >> G->vexs[i];
	}
	/*建立二维数组—边表*/
	/*首先把二维数组初始化*/
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
	/*读入numEdges条边，建立邻接矩阵*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "输入边（vi,vj)的下标i，下标j和权w:\n";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*因为是有向图，所以下面的操作不用进行*/
		//G->arc[j][i] = w;//因为是无向图，所以构成对称矩阵
	}
}

void ShowMGraph(MGraph G)
{
	for (int i = 0;i < G.numVertexes;i++)
	{
		cout << "第" << i + 1 << "个顶点的邻边有：";
		for (int j = 0;j < G.numVertexes;j++)
		{
			if (G.arc[i][j] != 0 && G.arc[i][j] != INFINITY)
			{
				cout << "（" << i << "," << j << "）" << " ";
			}
		}
	}
	cout << endl;
}