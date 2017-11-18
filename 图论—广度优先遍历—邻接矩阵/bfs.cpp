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
	cout << "���붥�������";
	cin >> G->numVertexes;
	cout << "����ߵĸ�����";
	cin >> G->numEdges;
	/*���붥����Ϣ�����������*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "�����" << i + 1 << "�������ֵ��";
		cin >> G->vexs[i];
	}
	/*��ʼ���߱�*/
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
	/*����ߵ���Ϣ�������߱�*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "���루vi��vj�����±�i���±�j��Ȩֵw��";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*���������ͼ����ִ������Ĵ���*/
		G->arc[j][i] = w;
	}
}

Queue CreateQueue(void)
{
	Queue Q = new struct QueueRecord;
	Q->list = new struct ListRecord;
	if (Q->list == NULL || Q == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
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
			cout << "�ڴ����ʧ�ܣ�\n";
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

void DeQueue(Queue Q, int a)//��ɾ�������е�Ԫ��ʱ���ж϶����Ƿ�Ϊ�յķ�����������������Show�������еķ�����ͬ����Ϊ��Q->front==Q->rearʱ������һ��Ԫ��û�г���
{
	if (Q->front == NULL)
	{
		cout << "����Ϊ�գ�\n";
	}
	else
	{
		List temp = Q->front;
		Q->front = Q->front->next;
		a = temp->value;
		delete temp;
	}
}

/*�ڽӾ���Ĺ�ȱ����㷨*/
void BFSTraverse(MGraph G)
{
	int i, j, k = 0;
	/*�ȳ�ʼ��visited����*/
	for (i = 0;i < G.numVertexes;i++)
	{
		visited[i] = false;
	}
	Queue Q = CreateQueue();
	/*��ÿһ���������ѭ��*/
	for (i = 0;i < G.numVertexes;i++)
	{
		/*���û�з��ʹ�����ִ������Ĵ���*/
		if (!visited[i])
		{
			visited[i] = true;//����Ϊ�Ѿ����ʹ���
			cout << G.vexs[i] << " ";
			EnQueue(Q, i);//����ǰ�������
			while (!IsEmpty(Q))
			{
				DeQueue(Q, k);
				/*�Գ��ԵĶ�����б���*/
				for (j = 0;j < G.numVertexes;j++)
				{
					/*����ö��������ڽӵ���ڱ���δ������*/
					if (G.arc[i][j] != INFINITY && !visited[j])
					{
						visited[j] = true;//���øö���Ϊ�ѷ���
						cout << G.vexs[j] << " ";
						EnQueue(Q, j);
					}
				}
			}
		}
	}
}