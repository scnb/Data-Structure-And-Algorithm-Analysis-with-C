#include "stdafx.h"
#include <iostream>
#include "bfs.h"

using std::cin;
using std::cout;
using std::endl;


bool visited[MAXVEX];

void CreateGraph(MGraph * G)
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
		cout << "输入（vi，vj）的下表i，下表j和权值w：";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*如果是无向图，则执行下面的代码*/
		G->arc[j][i] = w;
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

void DeQueue(Queue Q, int a)//在删除队列中的元素时，判断队列是否为空的方法与其他函数（如Show函数）中的方法不同，因为当Q->front==Q->rear时，还有一个元素没有出队
{
	if (Q->front == NULL)
	{
		cout << "队列为空！\n";
	}
	else
	{
		List temp = Q->front;
		Q->front = Q->front->next;
		a = temp->value;
		delete temp;
	}
}

/*邻接矩阵的广度遍历算法*/
void BFSTraverse(MGraph G)
{
	int i, j, k = 0;
	/*先初始化visited数组*/
	for (i = 0;i < G.numVertexes;i++)
	{
		visited[i] = false;
	}
	Queue Q = CreateQueue();
	/*对每一个顶点进行循环*/
	for (i = 0;i < G.numVertexes;i++)
	{
		/*如果没有访问过，就执行下面的代码*/
		if (!visited[i])
		{
			visited[i] = true;//设置为已经访问过了
			cout << G.vexs[i] << " ";
			EnQueue(Q, i);//将当前顶点入队
			while (!IsEmpty(Q))
			{
				DeQueue(Q, k);
				/*对出对的顶点进行遍历*/
				for (j = 0;j < G.numVertexes;j++)
				{
					/*如果该顶点与其邻接点存在边且未被访问*/
					if (G.arc[i][j] != INFINITY && !visited[j])
					{
						visited[j] = true;//设置该顶点为已访问
						cout << G.vexs[j] << " ";
						EnQueue(Q, j);
					}
				}
			}
		}
	}
}