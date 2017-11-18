// 图论—最小生成树—普里姆（Prim）算法.cpp : 定义控制台应用程序的入口点。
//最小生成树：构造连通网（带权值的连通图）的最小代价生成树
//连通网：对于图G中任意两个顶点都是连通的（存在路径），则称为连通图。
//一个连通图的生成树是一个极小的连通子图，它含有图中全部的n个顶点，但只有足以构成一棵树的n-1条边
//在本例中，以邻接矩阵为例
//普里姆算法：以后顶点为起点，逐步找各顶点上最小权值的边来构建最小生成树

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXVEX (100)
#define INFINITY (65536)
typedef int VertexType;
typedef int EdgeNode;

typedef struct
{
	int numVertexes, numEdges;
	VertexType vexs[MAXVEX];
	EdgeNode arc[MAXVEX][MAXVEX];
}MGraph;

void CreateMGraph(MGraph * G);
void MiniSpanTree_Prim(MGraph G);

int main()
{
	MGraph G;
	CreateMGraph(&G);
	cout << "显示最小生成树：\n";
	MiniSpanTree_Prim(G);
	getchar();
	getchar();
    return 0;
}


void CreateMGraph(MGraph * G)
{
	int i, j, w, k;
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
			G->arc[i][j] = INFINITY;
		}
	}
	/*读入边的信息，构建边表*/
	for(k=0;k<G->numEdges;k++)
	{
		cout << "输入边（vi，vj）的下标i，下标j和权值w：";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*如果是无向图，则执行下面的代码*/
		G->arc[j][i] = w;
	}
}

void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];//存储当前顶点的最小权值邻边的邻接点
	int lowcost[MAXVEX];//保存当前顶点的邻边权值
	/*下面两条语句是默认从v0顶点开始寻找最小生成树，所以是对V0顶点的操纵*/
	lowcost[0] = 0;//初始化第一个权值为0，即表示将v0加入生成树
	adjvex[0] = 0;//初始化第一个顶点的下标为0
	for (i = 1;i < G.numVertexes;i++)//循环除下标0外的全部顶点
	{
		lowcost[i] = G.arc[0][i];//将V0的邻边权值存入lowcost数组中
		adjvex[i] = 0;//都初始化为V0的下标
	}
	/*以下整个循环过程就是最小生成树的产生过程*/
	for (i = 1;i < G.numVertexes;i++)
	{
		min = INFINITY;//初始化最小权值为∞，方便一会儿和别的权值进行比较，取得最小权值
		j = 1;
		k = 0;
		while (j < G.numVertexes)//循环除V0外的所有顶点，目的是找出最小的权值
		{
			if (lowcost[j] != 0 && lowcost[j] < min)//第一个≠0说明，该顶点还没有纳入生成树中，第二个小于min说明该邻边的权值小于目前的最小权值
			{
				min = lowcost[j];//更新最小权值
				k = j;//k是用来存储当前顶点的最小权值邻边的邻接点下标
			}
			j++;
		}
		cout << "（" << adjvex[k] << "，" << k << "）" << " ";//输出当前顶点的所有邻接边中的权值最小路径
		lowcost[k] = 0;//将当前顶点与k顶点之间的路径权值设置为0，表明k顶点已经被纳入生成树
		for (j = 1;j < G.numVertexes;j++)//循环所有顶点，并已k对应的顶点为当前定点
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])//第一个判断j对应的顶点是否已被纳入生成树中；第一个寻找k顶点的邻接边中权值比较小的
			{
				lowcost[j] = G.arc[k][j];//将k顶点比较小的邻接边权值存入lowcost中，其实就是找到新顶点(k)后把lowcost更新一下
				adjvex[j] = k;//把上面修改了的地方对应的adjvex中相同的下标换成k顶点的下标
			}
		}
	}
}
