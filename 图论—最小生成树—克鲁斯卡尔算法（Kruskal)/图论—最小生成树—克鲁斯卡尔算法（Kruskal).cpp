// ͼ�ۡ���С����������³˹�����㷨��Kruskal).cpp : �������̨Ӧ�ó������ڵ㡣
//����С�������ĳ�ʼ״̬Ϊֻ��n��������ޱߵķ���ͨͼ���ڱ߼���ѡ�������С�ıߣ����ñ�
//�����Ķ���������ͨͼ�в�ͬ����ͨ�����ϣ��򽫴˱߼��뵽��ͨͼ�У�������ȥ�˱߶�ѡ����һ
//��������С�ıߣ�ֱ����ͨͼ�����ж��㶼��ͬһ��ͨ������Ϊֹ
//parent��������ã����ڵ�ǰ��Ȩֵ��С�ıߣ�ͨ��Find�����ֱ��ҳ������������
//�ڽӵ���ڽӵ�ġ����ڽӵ�(��һֱ�ҵ�ͷ����n��m��������������ڽӵ���ͬ����˵����ǰ����Ȩ
//ֵ��С�ıߺ͵�ǰ����С�������γ��˻�·����ͼ�ܹ���ֱ�۵Ŀ�����

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXVEX (3)
#define INFINITY (65536)
#define MAXEDGE (4)

typedef int VertexType;
typedef int EdgeNode;

/*�ߵĽṹ*/
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeNode arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph * G);
void MiniSpanTree_Kruskal(MGraph G);
void Turn2Edges(MGraph G, Edge edges[MAXEDGE]);
int Find(int parent[MAXVEX], int f);
void test(int a[], int N);

int main()
{
	MGraph G;
	CreateMGraph(&G);
	cout << "������С��������\n";
	MiniSpanTree_Kruskal(G);
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
		cout << "����ߣ�vi��vj�����±�i���±�j��Ȩֵw��";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*���������ͼ�����ǶԳƵľ���ִ������Ĵ���*/
		G->arc[j][i] = w;
	}
}

void Turn2Edges(MGraph G,Edge edges[MAXEDGE])
{
	int i, j,k=0;
	int min_weight;
	int min_i, min_j;
	/*�Ȱ����еı�ת����edges������*/
	for (i = 0;i < G.numVertexes;i++)
	{
		for (j = 0;j < G.numVertexes;j++)
		{
			if (i < j)
			{
				if (G.arc[i][j] != 0 && G.arc[i][j] < INFINITY)
				{
					edges[k].begin = i;
					edges[k].end = j;
					edges[k++].weight = G.arc[i][j];
				}
			}
		}
	}
	/*ת�����֮���ٽ�������*/
	Edge temp;
	for (i = 0;i < G.numEdges;i++)
	{
		for (j = i;j < G.numEdges;j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
		}
	}
}

void test(int a[],int N)
{
	int i, j;
	int temp;
	for (i = 0;i < N;i++)
	{
		for (j = i;j < N;j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];//����߼�����
	int parent[MAXVEX];//����һ�����������жϱ�����Ƿ��γɻ�·��ͬʱҲ�Ǳ����Щ��������������
	/*���ڽӾ���Gת��Ϊ�߼�����edges�����Ұ�Ȩ��С��������*/
	Turn2Edges(G,edges);
	/*���������ת���Լ�����󣬱ߵ�Ȩֵ������С�����������*/
	for (i = 0;i < G.numVertexes;i++)
	{
		parent[i] = 0;//��ʼ��parent�����е�ֵΪ0
	}
	for (i = 0;i < G.numEdges;i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)/*���n��m������Ϊ�ñ�û�������е��������γɻ�·*/
		{
			parent[n] = m;/*���ñ������Ϊ�±꣬���յ�Ϊֵ������parent��*/
			cout << "��" << edges[i].begin << "��" << edges[i].end << "��" << edges[i].weight << " ";
		}
	}
}

int Find(int parent[MAXVEX], int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}