// 图论—深度优先遍历—邻接表.cpp : 定义控制台应用程序的入口点。
//深度优先遍历：Deep_First_Search，又称深度优先搜索
//同对邻接矩阵的深度优先遍历一样，同样需要visited数组来标识每个元素的访问是否被访问
//本例是基于无向图的，如果想进行有向图的示范，则只需把CreateGraph函数中相应的部分代码删去即可

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100

typedef struct EdgeNode//边表
{
	int adjvex;//存储邻接点的下标
	EdgeType weight;//存储权值
	struct EdgeNode * Next;//指向下一个边
}EdgeNode;

typedef struct VertexNode//顶点表
{
	VertexType data;//存储顶点的值
	EdgeNode * firstedge;//存储顶点的第一个邻边
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;//顶点表
	int numVertexes, numEdges;//图中当前顶点数和边数
}GraphAdjList;

bool visited[MAXVEX];

void CreateGraph(GraphAdjList * G);
void DFS(GraphAdjList G, int i);
void DFSTraverse(GraphAdjList G);

int main()
{
	GraphAdjList G;
	CreateGraph(&G);
	cout << "显示图：\n";
	DFSTraverse(G);
	getchar();
	getchar();
    return 0;
}

void CreateGraph(GraphAdjList * G)
{
	int i, j, k,w;
	EdgeNode * e;
	cout << "输入顶点数：";
	cin >> G->numVertexes;
	cout << "输入边数：";
	cin >> G->numEdges;
	/*读入顶点信息，建立顶点表*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "输入第" << i + 1 << "个顶点的值：";
		cin >> G->adjlist[i].data;
		G->adjlist[i].firstedge = NULL;//先把每个顶点的第一个边指针设为空
	}
	/*读入边的信息，建立边表*/
	for (k = 0;k < G->numEdges;k++)
	{
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		if (e == NULL)
		{
			cout << "内存分配失败！\n";
			getchar();
			exit(-1);
		}
		cout << "输入边（vi,vj）的下标i，下标j和权值w：";
		cin >> i >> j >> w;
		e->adjvex = j;
		e->weight = w;
		e->Next = G->adjlist[k].firstedge;
		G->adjlist[k].firstedge = e;
		/*因为无向图，所以对称的操作如下：*/
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		if (e == NULL)
		{
			cout << "内存分配失败！\n";
			getchar();
			exit(-1);
		}
		e->adjvex = i;
		e->weight = w;
		e->Next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = e;
	}
}

/*邻接表的深度优先递归算法*/
void DFS(GraphAdjList G, int i)
{
	EdgeNode * p;
	visited[i] = true;
	cout << G.adjlist[i].data << " ";
	p = G.adjlist[i].firstedge;
	while (p!=NULL)
	{
		if (!visited[i])//如果该顶点还没有被访问，则进行递归调用
		{
			DFS(G, p->adjvex);
		}
		p = p->Next;
	}
}

/*邻接表的深度遍历操作*/
void DFSTraverse(GraphAdjList G)
{
	int i;
	/*先将visited数组进行初始化*/
	for (i = 0;i < G.numVertexes;i++)
	{
		visited[i] = false;
	}
	/*对每一个顶点进行访问*/
	for (i = 0;i < G.numVertexes;i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
		}
	}
}