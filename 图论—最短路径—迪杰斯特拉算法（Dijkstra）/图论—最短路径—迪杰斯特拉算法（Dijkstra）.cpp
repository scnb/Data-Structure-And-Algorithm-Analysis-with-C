// 图论—最短路径—迪杰斯特拉算法（Dijkstra）.cpp : 定义控制台应用程序的入口点。
//迪杰斯特拉算法：寻找从某个源点到其余各顶点的最短路径问题，是一种按路径长度递增的次序产生最短路径的算法。
//思路为：先从某一个源点开始，扫描它的所有邻边，找到最小的那一个，选中它，再从该邻接点开始扫描它的所有
//		  邻边，找到最小的那一个……依此类推
//该算法最终将结果保存在两个数组中，数组P：保存最短路径的顶点顺序，P中的每一个元素的值都是对应顶点的前驱顶点
//比如P={0，0，1，4，2，4，3，6，7}，则V8的前驱顶点是V7，而V7的前驱顶点是V6……
//数组D：保存从源点到每一个顶点的最短路径，如D={0，1，4，7，5，8，10，12，16}，假如V0是源点，则V0到V1的最短路径是1，
//到V2的最短路径是4，到V3的最短路径是7……

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXVEX (9)
#define INFINITY (65535)
typedef int Patharc[MAXVEX];//用于存储最短路径的下标
typedef int ShortPathTable[MAXVEX];//用于存储到各点最短路径的权值和

typedef int VertexType;
typedef int EdgeNode;
typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeNode arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph * G);
void shortestPath_Dijkstra(MGraph G, int v0, Patharc * P, ShortPathTable * D);

int main()
{
	MGraph G;
	Patharc P;
	ShortPathTable D;
	CreateMGraph(&G);
	cout << "最短路径：\n";
	shortestPath_Dijkstra(G,0, &P, &D);
	for (int i = 0;i < MAXVEX;i++)
	{
		cout << D[i] << " ";
	}
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

void shortestPath_Dijkstra(MGraph G, int v0, Patharc * P, ShortPathTable * D)
{
	int v, w, k, min;
	int final[MAXVEX];//final[w]=1表示已经求得V0到Vw的最短路径
	for (v = 0;v < G.numVertexes;v++)
	{
		final[v] = 0;//全部顶点初始化为未知最短路径状态
		(*D)[v] = G.arc[v0][v];//将与V0点有邻接边的顶点权值保存在D数组中
		(*P)[v] = 0;//初始化路径数组为0
	}
	(*D)[v0] = 0;//v0到v0的路径为0
	final[v0] = 1;//因为v0到v0不需要求路径
	/*开始主循环，每次求得V0到某个v顶点的最短路径*/
	for (v = 1;v < G.numVertexes;v++)
	{
		min = INFINITY;//当前所知离V0顶点的最近距离
		for (w = 0;w < G.numVertexes;w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];//Vw顶点离V0顶点更近
			}
		}
		final[k] = 1;//将目前找到的最近的顶点对应元素置1
		/*以上边找到的最近的顶点为新的起点，对它的所有邻接顶点进行循环，寻找最小的邻接边*/
		for (w = 0;w < G.numVertexes;w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}