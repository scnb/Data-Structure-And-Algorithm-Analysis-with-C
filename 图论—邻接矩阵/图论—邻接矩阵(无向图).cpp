// 图论—邻接矩阵.cpp : 定义控制台应用程序的入口点。
//邻接矩阵：顶点部分大小、主次，所以用一维数组来存储
//			边是顶点与顶点之间的关系，所以需要二维数组来存储
//权：每条边上的权值，即比重大小
//若边存在，则其对应的二维数组元素是其权值；若边不存在，则其对应的二维数组元素是INFINITY；其余的则为0
//本例中是无向图，构成的邻接矩阵是对称矩阵
//如果要输出某个顶点的邻边，则对该顶点对应的行进行遍历，若元素的值不为0或INFINITY则表明该边存在

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
	cout << "显示数组:";
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
		cout << "输入第" << i << "个顶点的值：";
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
		G->arc[j][i] = w;//因为是无向图，所以构成对称矩阵
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
