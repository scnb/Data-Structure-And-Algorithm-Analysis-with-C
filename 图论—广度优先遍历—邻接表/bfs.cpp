#include "stdafx.h"
#include "bfs.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool visited[MAXVEX];

/*�����ڽӱ�*/
void CreateGraph(GraphAdjList * G)
{
	int i, j, k, w;
	EdgeNode * e;
	cout << "���붥��ĸ�����";
	cin >> G->numVertexes;
	cout << "����ߵĸ�����";
	cin >> G->numEdges;
	/*���붥����Ϣ�����������*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "�����" << i + 1 << "�������ֵ��";
		cin >> G->adjlist[i].data;
		G->adjlist[i].firstedge = NULL;
	}
	/*����ߵ���Ϣ�������߱�*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "����ߣ�vi��vj�����±�i���±�j��Ȩֵw��";
		cin >> i >> j >> w;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->weight = w;
		e->Next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = e;
		/*���������ͼ����ִ������Ĵ���*/
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

void DeQueue(Queue Q, int *a)//��ɾ�������е�Ԫ��ʱ���ж϶����Ƿ�Ϊ�յķ�����������������Show�������еķ�����ͬ����Ϊ��Q->front==Q->rearʱ������һ��Ԫ��û�г���
{
	if (Q->front == NULL)
	{
		cout << "����Ϊ�գ�\n";
	}
	else
	{
		List temp = Q->front;
		Q->front = Q->front->next;
		*a = temp->value;
		delete temp;
	}
}

/*�ڽӱ�Ĺ�����ȱ����㷨*/
void BFSTraverse(GraphAdjList G)
{
	int i,k;
	EdgeNode * p;
	/*��ʼ��visited����*/
	for (i = 0;i < G.numVertexes;i++)
	{
		visited[i] = false;
	}
	Queue Q = CreateQueue();
	/*��ÿһ��������в���*/
	for (i = 0;i < G.numVertexes;i++)
	{
		/*����ö��㻹û�н��з��ʾ�ִ������Ĵ���*/
		if (!visited[i])
		{
			visited[i] = true;//��Ȼ�ܽ�if���棬�ͱ�ʾ��������
			cout << G.adjlist[i].data << " ";
			EnQueue(Q, i);//ʹ��ǰ�������
			while (!IsEmpty(Q))
			{
				DeQueue(Q, &k);
				p = G.adjlist[i].firstedge;//�õ���ǰ����ĵ�һ���ߵ�ָ��
				while (p != NULL)
				{
					if (!visited[p->adjvex])//���˶��㻹û�б�����
					{
						visited[p->adjvex] = true;//�Ըö�����з���
						cout << G.adjlist[p->adjvex].data;
						EnQueue(Q, p->adjvex);
					}
					p = p->Next;
				}
			}
		}
	}
}