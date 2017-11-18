// 图论—邻接表.cpp : 定义控制台应用程序的入口点。
//邻接表：Adjacency List
//在这个例子中，以无向图为例
//还可以增添权值

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define MAXVEX 100

typedef char VertexType;//顶点类型
typedef int EdgeType;//边上的权值类型

typedef struct EdgeNode//边表，还可以在边表内增添权值这个域
{
	int adjvex;//存储邻接点的下标
	EdgeType weight;//存储边上的权值
	struct EdgeNode *Next;//指向下一个邻接点
}EdgeNode;

typedef struct VertexNode//顶点表
{
	VertexType data;//存储顶点的数据
	EdgeNode *firstedge;//存储第一个邻接点的指针
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;//图中当前顶点数和边数
}GraphAdjList;

void CreateALGraph(GraphAdjList * G);
void ShowGraph(GraphAdjList G);

int main()
{
	GraphAdjList G;
	CreateALGraph(&G);
	cout << "显示图：\n";
	ShowGraph(G);
	getchar();
	getchar();
    return 0;
}

void CreateALGraph(GraphAdjList * G)//在本例中，以无向图为例
{
	int i, j, k;
	EdgeNode *e;//创建边表结点
	cout << "输入顶点数：\n";
	cin >> G->numVertexes; 
	cout << "请输入边数：\n";
	cin>> G->numEdges;
	/*读入顶点信息，建立顶点表*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "输入第" << i + 1 << "个顶点的值:";
		cin >> G->adjList[i].data;//输入顶点信息
		G->adjList[i].firstedge = NULL;//把每一个顶点表的边表指针设置为空
	}
	/*建立边表*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "输入边(vi,vj)上的顶点序号:\n";
		cin >> i >> j;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));//申请边表结点的空间
		e->adjvex = j;//邻接序号为j
		e->Next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;//将顶点表的指针设置为当前边表结点的地址

		/*因为是无向图，对称的，(vj,vi)也有同样的操作*/
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->Next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}

void ShowGraph(GraphAdjList G)
{
	/*按照每个结点来显示其边*/
	for (int i = 0;i < G.numVertexes;i++)
	{
		cout << "第" << i+1 << "个结点的边有：";
		EdgeNode * temp = G.adjList[i].firstedge;
		while (temp != NULL)
		{
			cout << "（" <<i << "," << temp->adjvex << "）" << " ";
			temp = temp->Next;
		}
	}
	cout << endl;
}