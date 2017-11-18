// ͼ�ۡ��ڽӱ�����ͼ��.cpp : �������̨Ӧ�ó������ڵ㡣
//�ڽӱ�Adjacency List


#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define MAXVEX 100

typedef char VertexType;//��������
typedef int EdgeType;//���ϵ�Ȩֵ����

typedef struct EdgeNode//�߱�
{
	int adjvex;//�洢�ڽӵ���±�
	EdgeType weight;//�洢���ϵ�Ȩֵ
	struct EdgeNode *Next;//ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode//�����
{
	VertexType data;//�洢���������
	EdgeNode *firstedge;//�洢��һ���ڽӵ��ָ��
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;//ͼ�е�ǰ�������ͱ���
}GraphAdjList;

void CreateALGraph(GraphAdjList * G);
void ShowGraph(GraphAdjList G);

int main()
{
	GraphAdjList G;
	CreateALGraph(&G);
	cout << "��ʾͼ��\n";
	ShowGraph(G);
	getchar();
	getchar();
	return 0;
}

void CreateALGraph(GraphAdjList * G)//�ڱ����У�������ͼΪ��
{
	int i, j, k;
	EdgeNode *e;//�����߱���
	cout << "���붥������\n";
	cin >> G->numVertexes;
	cout << "�����������\n";
	cin >> G->numEdges;
	/*���붥����Ϣ�����������*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "�����" << i + 1 << "�������ֵ:";
		G->adjList[i].firstedge = NULL;//��ÿһ�������ı߱�ָ������Ϊ��
		cin>> G->adjList[i].data;//���붥����Ϣ
	}
	/*�����߱�*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "�����(vi,vj)�ϵĶ�����ţ�ע���з���:\n";
		cin >> i >> j;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));//����߱���Ŀռ�
		e->adjvex = j;//�ڽ����Ϊj
		e->Next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;//��������ָ������Ϊ��ǰ�߱���ĵ�ַ

		/*��Ϊ������ͼ�����Ժ���Ĳ����������*/
		/*e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->Next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;*/
	}
}

void ShowGraph(GraphAdjList G)
{
	/*����ÿ���������ʾ���*/
	for (int i = 0;i < G.numVertexes;i++)
	{
		cout << "��" << i + 1 << "�����ı��У�";
		EdgeNode * temp = G.adjList[i].firstedge;
		while (temp != NULL)
		{
			cout << "��" << i << "," << temp->adjvex << "��" << " ";
			temp = temp->Next;
		}
	}
	cout << endl;
}

