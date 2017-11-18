// ͼ�ۡ��ڽӾ�������ͼ��.cpp : �������̨Ӧ�ó������ڵ㡣
//����������ͼΪ��

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

typedef struct
{
	VertexType vexs[MAXVEX];//�洢����
	EdgeType arc[MAXVEX][MAXVEX];//�洢��
	int numVertexes, numEdges;//�ֱ�Ϊ�������������
}MGraph;

void CreateMGraph(MGraph * G);
void ShowMGraph(MGraph G);

int main()
{
	MGraph G;
	CreateMGraph(&G);
	cout << "��ʾ����:\n";
	ShowMGraph(G);
	getchar();
	getchar();
	return 0;
}


/*������ͼΪ��*/
void CreateMGraph(MGraph * G)
{
	int i, j, k, w;
	cout << "���붥������";
	cin >> G->numVertexes;
	cout << "���������";
	cin >> G->numEdges;
	/*���������*/
	for (i = 0;i < G->numVertexes;i++)
	{
		cout << "�����" << i+1 << "�������ֵ��";
		cin >> G->vexs[i];
	}
	/*������ά���顪�߱�*/
	/*���ȰѶ�ά�����ʼ��*/
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
	/*����numEdges���ߣ������ڽӾ���*/
	for (k = 0;k < G->numEdges;k++)
	{
		cout << "����ߣ�vi,vj)���±�i���±�j��Ȩw:\n";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*��Ϊ������ͼ����������Ĳ������ý���*/
		//G->arc[j][i] = w;//��Ϊ������ͼ�����Թ��ɶԳƾ���
	}
}

void ShowMGraph(MGraph G)
{
	for (int i = 0;i < G.numVertexes;i++)
	{
		cout << "��" << i + 1 << "��������ڱ��У�";
		for (int j = 0;j < G.numVertexes;j++)
		{
			if (G.arc[i][j] != 0 && G.arc[i][j] != INFINITY)
			{
				cout << "��" << i << "," << j << "��" << " ";
			}
		}
	}
	cout << endl;
}