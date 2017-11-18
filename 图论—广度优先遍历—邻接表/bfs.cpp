#include "stdafx.h"
#include "bfs.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool visited[MAXVEX];

/*创建邻接表*/
void CreateGraph(GraphAdjList * G)
{
	int i, j, k, w;
	EdgeNode * e;
	cout << "输入顶点的个数：";
	cin >> G->numVertexes;
	cout << "输入边的个数：";
	cin >> G->numEdges;
	/*读入顶点信息，构建顶点表*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "输入第" << i + 1 << "个顶点的值：";
		cin >> G->adjlist[i].data;
		G->adjlist[i].firstedge = NULL;
	}
	/*读入边的信息，构建边表*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "输入边（vi，vj）的下标i，下标j和权值w：";
		cin >> i >> j >> w;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->weight = w;
		e->Next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = e;
		/*如果是无向图，则执行下面的代码*/
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->weight = w;
		e->Next = G->adjlist[j].firstedge;
		G->adjlist[i].firstedge = e;
	}
}

Queue CreateQueue(void)
{
	Queue Q = new struct QueueRecord;
	Q->list = new struct ListRecord;
	if (Q->list == NULL || Q == NULL)
	{
		cout << "内存分配失败！\n";
		exit(-1);
	}
	Q->list->next = NULL;
	Q->list->value = 0;
	Q->rear = Q->list;
	Q->front = Q->list;
}

void EnQueue(Queue Q, ElementType X)
{
	static int i = 1;
	if (i == 1)
	{
		Q->front->value = X;
		i++;
	}
	else
	{
		List temp = new struct ListRecord;
		if (temp == NULL)
		{
			cout << "内存分配失败！\n";
			exit(-1);
		}
		temp->value = X;
		temp->next = NULL;
		Q->rear->next = temp;
		Q->rear = temp;
	}
}

int IsEmpty(Queue Q)
{
	return Q->front == Q->rear;
}

ElementType Front(Queue Q)
{
	return Q->front->value;
}

void DeQueue(Queue Q, int *a)//在删除队列中的元素时，判断队列是否为空的方法与其他函数（如Show函数）中的方法不同，因为当Q->front==Q->rear时，还有一个元素没有出队
{
	if (Q->front == NULL)
	{
		cout << "队列为空！\n";
	}
	else
	{
		List temp = Q->front;
		Q->front = Q->front->next;
		*a = temp->value;
		delete temp;
	}
}

/*邻接表的广度优先遍历算法*/
void BFSTraverse(GraphAdjList G)
{
	int i,k;
	EdgeNode * p;
	/*初始化visited数组*/
	for (i = 0;i < G.numVertexes;i++)
	{
		visited[i] = false;
	}
	Queue Q = CreateQueue();
	/*对每一个顶点进行操作*/
	for (i = 0;i < G.numVertexes;i++)
	{
		/*如果该顶点还没有进行访问就执行下面的代码*/
		if (!visited[i])
		{
			visited[i] = true;//既然能进if里面，就表示被访问了
			cout << G.adjlist[i].data << " ";
			EnQueue(Q, i);//使当前顶点入队
			while (!IsEmpty(Q))
			{
				DeQueue(Q, &k);
				p = G.adjlist[i].firstedge;//得到当前顶点的第一个边的指针
				while (p != NULL)
				{
					if (!visited[p->adjvex])//若此顶点还没有被访问
					{
						visited[p->adjvex] = true;//对该顶点进行访问
						cout << G.adjlist[p->adjvex].data;
						EnQueue(Q, p->adjvex);
					}
					p = p->Next;
				}
			}
		}
	}
}