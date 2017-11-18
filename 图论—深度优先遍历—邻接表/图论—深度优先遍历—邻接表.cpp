// ͼ�ۡ�������ȱ������ڽӱ�.cpp : �������̨Ӧ�ó������ڵ㡣
//������ȱ�����Deep_First_Search���ֳ������������
//ͬ���ڽӾ����������ȱ���һ����ͬ����Ҫvisited��������ʶÿ��Ԫ�صķ����Ƿ񱻷���
//�����ǻ�������ͼ�ģ�������������ͼ��ʾ������ֻ���CreateGraph��������Ӧ�Ĳ��ִ���ɾȥ����

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100

typedef struct EdgeNode//�߱�
{
	int adjvex;//�洢�ڽӵ���±�
	EdgeType weight;//�洢Ȩֵ
	struct EdgeNode * Next;//ָ����һ����
}EdgeNode;

typedef struct VertexNode//�����
{
	VertexType data;//�洢�����ֵ
	EdgeNode * firstedge;//�洢����ĵ�һ���ڱ�
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;//�����
	int numVertexes, numEdges;//ͼ�е�ǰ�������ͱ���
}GraphAdjList;

bool visited[MAXVEX];

void CreateGraph(GraphAdjList * G);
void DFS(GraphAdjList G, int i);
void DFSTraverse(GraphAdjList G);

int main()
{
	GraphAdjList G;
	CreateGraph(&G);
	cout << "��ʾͼ��\n";
	DFSTraverse(G);
	getchar();
	getchar();
    return 0;
}

void CreateGraph(GraphAdjList * G)
{
	int i, j, k,w;
	EdgeNode * e;
	cout << "���붥������";
	cin >> G->numVertexes;
	cout << "���������";
	cin >> G->numEdges;
	/*���붥����Ϣ�����������*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "�����" << i + 1 << "�������ֵ��";
		cin >> G->adjlist[i].data;
		G->adjlist[i].firstedge = NULL;//�Ȱ�ÿ������ĵ�һ����ָ����Ϊ��
	}
	/*����ߵ���Ϣ�������߱�*/
	for (k = 0;k < G->numEdges;k++)
	{
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		if (e == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�\n";
			getchar();
			exit(-1);
		}
		cout << "����ߣ�vi,vj�����±�i���±�j��Ȩֵw��";
		cin >> i >> j >> w;
		e->adjvex = j;
		e->weight = w;
		e->Next = G->adjlist[k].firstedge;
		G->adjlist[k].firstedge = e;
		/*��Ϊ����ͼ�����ԶԳƵĲ������£�*/
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		if (e == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�\n";
			getchar();
			exit(-1);
		}
		e->adjvex = i;
		e->weight = w;
		e->Next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = e;
	}
}

/*�ڽӱ��������ȵݹ��㷨*/
void DFS(GraphAdjList G, int i)
{
	EdgeNode * p;
	visited[i] = true;
	cout << G.adjlist[i].data << " ";
	p = G.adjlist[i].firstedge;
	while (p!=NULL)
	{
		if (!visited[i])//����ö��㻹û�б����ʣ�����еݹ����
		{
			DFS(G, p->adjvex);
		}
		p = p->Next;
	}
}

/*�ڽӱ����ȱ�������*/
void DFSTraverse(GraphAdjList G)
{
	int i;
	/*�Ƚ�visited������г�ʼ��*/
	for (i = 0;i < G.numVertexes;i++)
	{
		visited[i] = false;
	}
	/*��ÿһ��������з���*/
	for (i = 0;i < G.numVertexes;i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
		}
	}
}