// ͼ�ۡ����·�����Ͻ�˹�����㷨��Dijkstra��.cpp : �������̨Ӧ�ó������ڵ㡣
//�Ͻ�˹�����㷨��Ѱ�Ҵ�ĳ��Դ�㵽�������������·�����⣬��һ�ְ�·�����ȵ����Ĵ���������·�����㷨��
//˼·Ϊ���ȴ�ĳһ��Դ�㿪ʼ��ɨ�����������ڱߣ��ҵ���С����һ����ѡ�������ٴӸ��ڽӵ㿪ʼɨ����������
//		  �ڱߣ��ҵ���С����һ��������������
//���㷨���ս�������������������У�����P���������·���Ķ���˳��P�е�ÿһ��Ԫ�ص�ֵ���Ƕ�Ӧ�����ǰ������
//����P={0��0��1��4��2��4��3��6��7}����V8��ǰ��������V7����V7��ǰ��������V6����
//����D�������Դ�㵽ÿһ����������·������D={0��1��4��7��5��8��10��12��16}������V0��Դ�㣬��V0��V1�����·����1��
//��V2�����·����4����V3�����·����7����

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXVEX (9)
#define INFINITY (65535)
typedef int Patharc[MAXVEX];//���ڴ洢���·�����±�
typedef int ShortPathTable[MAXVEX];//���ڴ洢���������·����Ȩֵ��

typedef int VertexType;
typedef int EdgeNode;
typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeNode arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph * G);
void shortestPath_Dijkstra(MGraph G, int v0, Patharc * P, ShortPathTable * D);

int main()
{
	MGraph G;
	Patharc P;
	ShortPathTable D;
	CreateMGraph(&G);
	cout << "���·����\n";
	shortestPath_Dijkstra(G,0, &P, &D);
	for (int i = 0;i < MAXVEX;i++)
	{
		cout << D[i] << " ";
	}
	getchar();
	getchar();
    return 0;
}

void CreateMGraph(MGraph * G)
{
	int i, j, k, w;
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

void shortestPath_Dijkstra(MGraph G, int v0, Patharc * P, ShortPathTable * D)
{
	int v, w, k, min;
	int final[MAXVEX];//final[w]=1��ʾ�Ѿ����V0��Vw�����·��
	for (v = 0;v < G.numVertexes;v++)
	{
		final[v] = 0;//ȫ�������ʼ��Ϊδ֪���·��״̬
		(*D)[v] = G.arc[v0][v];//����V0�����ڽӱߵĶ���Ȩֵ������D������
		(*P)[v] = 0;//��ʼ��·������Ϊ0
	}
	(*D)[v0] = 0;//v0��v0��·��Ϊ0
	final[v0] = 1;//��Ϊv0��v0����Ҫ��·��
	/*��ʼ��ѭ����ÿ�����V0��ĳ��v��������·��*/
	for (v = 1;v < G.numVertexes;v++)
	{
		min = INFINITY;//��ǰ��֪��V0������������
		for (w = 0;w < G.numVertexes;w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];//Vw������V0�������
			}
		}
		final[k] = 1;//��Ŀǰ�ҵ�������Ķ����ӦԪ����1
		/*���ϱ��ҵ�������Ķ���Ϊ�µ���㣬�����������ڽӶ������ѭ����Ѱ����С���ڽӱ�*/
		for (w = 0;w < G.numVertexes;w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}