// ͼ�ۡ�������ȱ������ڽӾ���.cpp : �������̨Ӧ�ó������ڵ�
//������ȱ�����Deep_First_Search���ֳ��������������
//��ͼ��������ȱ�����������ǰ�������һ���ģ����ǻ��ڵݹ��˼��
//һ���ؼ���Ҫ����Ҫ��Ǻ��Ѿ����ʹ��Ķ��㣬��ֹͼ�еĻ�·�����ظ����ʣ�
//����취�Ǵ���һ��ר�ŵ�����������¼�����Ƿ񱻱�ǣ���ÿ�η��ʶ���ǰ�������ж�һ��visited�����ж�ӦԪ�ص�ֵ
//�����ǻ�������ͼ�ģ�������������ͼ��ʾ������ֻ���CreateGraph�����ж�Ӧ�Ĵ���ɾȥ����

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

bool visited[MAXVEX];//��¼ÿһ�������Ƿ񱻷���

typedef struct
{
	int numVertexes, numEdges;
	VertexType vexs[MAXVEX];//�洢����
	EdgeType arc[MAXVEX][MAXVEX];//�洢��
}MGraph;

void CreateMGraph(MGraph * G);
void DFS(MGraph G, int i);
void DFSTraverse(MGraph G);


int main()
{
	MGraph G;
	CreateMGraph(&G);
	DFSTraverse(G);
	getchar();
	getchar();
    return 0;
}

void CreateMGraph(MGraph * G)
{
	int i, j,k,w;
	cout << "���붥�������";
	cin >> G->numVertexes;
	cout << "����ߵĸ�����";
	cin >> G->numEdges;
	/*���������*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "�����" << i + 1 << "�������ֵ��";
		cin >> G->vexs[i];
	}
	/*�ȳ�ʼ���߱����*/
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
	/*�����߱����*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "���루vi��vj�����±�i���±�j��Ȩֵw��\n";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*��������ͼ����Ҫ�������*/
		G->arc[j][i] = w;
	}
}

/*�ڽӾ����������ȵݹ��㷨*/
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = true;
	cout << G.vexs[i];
	for (j = 0;j < G.numVertexes;j++)
	{
		if (G.arc[i][j] != 0 && G.arc[i][j] != INFINITY && !visited[j])
		{
			DFS(G, j);//���½��еݹ�
		}
	}
}

/*�ڽӾ������ȱ�������*/
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0;i < G.numVertexes;i++)
	{
		visited[i] = false;
	}
	for (i = 0;i < G.numVertexes;i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
		}
	}
}