// ͼ�ۡ���С������������ķ��Prim���㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//��С��������������ͨ������Ȩֵ����ͨͼ������С����������
//��ͨ��������ͼG�������������㶼����ͨ�ģ�����·���������Ϊ��ͨͼ��
//һ����ͨͼ����������һ����С����ͨ��ͼ��������ͼ��ȫ����n�����㣬��ֻ�����Թ���һ������n-1����
//�ڱ����У����ڽӾ���Ϊ��
//����ķ�㷨���Ժ󶥵�Ϊ��㣬���Ҹ���������СȨֵ�ı���������С������

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAXVEX (100)
#define INFINITY (65536)
typedef int VertexType;
typedef int EdgeNode;

typedef struct
{
	int numVertexes, numEdges;
	VertexType vexs[MAXVEX];
	EdgeNode arc[MAXVEX][MAXVEX];
}MGraph;

void CreateMGraph(MGraph * G);
void MiniSpanTree_Prim(MGraph G);

int main()
{
	MGraph G;
	CreateMGraph(&G);
	cout << "��ʾ��С��������\n";
	MiniSpanTree_Prim(G);
	getchar();
	getchar();
    return 0;
}


void CreateMGraph(MGraph * G)
{
	int i, j, w, k;
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
			G->arc[i][j] = INFINITY;
		}
	}
	/*����ߵ���Ϣ�������߱�*/
	for(k=0;k<G->numEdges;k++)
	{
		cout << "����ߣ�vi��vj�����±�i���±�j��Ȩֵw��";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		/*���������ͼ����ִ������Ĵ���*/
		G->arc[j][i] = w;
	}
}

void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];//�洢��ǰ�������СȨֵ�ڱߵ��ڽӵ�
	int lowcost[MAXVEX];//���浱ǰ������ڱ�Ȩֵ
	/*�������������Ĭ�ϴ�v0���㿪ʼѰ����С�������������Ƕ�V0����Ĳ���*/
	lowcost[0] = 0;//��ʼ����һ��ȨֵΪ0������ʾ��v0����������
	adjvex[0] = 0;//��ʼ����һ��������±�Ϊ0
	for (i = 1;i < G.numVertexes;i++)//ѭ�����±�0���ȫ������
	{
		lowcost[i] = G.arc[0][i];//��V0���ڱ�Ȩֵ����lowcost������
		adjvex[i] = 0;//����ʼ��ΪV0���±�
	}
	/*��������ѭ�����̾�����С�������Ĳ�������*/
	for (i = 1;i < G.numVertexes;i++)
	{
		min = INFINITY;//��ʼ����СȨֵΪ�ޣ�����һ����ͱ��Ȩֵ���бȽϣ�ȡ����СȨֵ
		j = 1;
		k = 0;
		while (j < G.numVertexes)//ѭ����V0������ж��㣬Ŀ�����ҳ���С��Ȩֵ
		{
			if (lowcost[j] != 0 && lowcost[j] < min)//��һ����0˵�����ö��㻹û�������������У��ڶ���С��min˵�����ڱߵ�ȨֵС��Ŀǰ����СȨֵ
			{
				min = lowcost[j];//������СȨֵ
				k = j;//k�������洢��ǰ�������СȨֵ�ڱߵ��ڽӵ��±�
			}
			j++;
		}
		cout << "��" << adjvex[k] << "��" << k << "��" << " ";//�����ǰ����������ڽӱ��е�Ȩֵ��С·��
		lowcost[k] = 0;//����ǰ������k����֮���·��Ȩֵ����Ϊ0������k�����Ѿ�������������
		for (j = 1;j < G.numVertexes;j++)//ѭ�����ж��㣬����k��Ӧ�Ķ���Ϊ��ǰ����
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])//��һ���ж�j��Ӧ�Ķ����Ƿ��ѱ������������У���һ��Ѱ��k������ڽӱ���Ȩֵ�Ƚ�С��
			{
				lowcost[j] = G.arc[k][j];//��k����Ƚ�С���ڽӱ�Ȩֵ����lowcost�У���ʵ�����ҵ��¶���(k)���lowcost����һ��
				adjvex[j] = k;//�������޸��˵ĵط���Ӧ��adjvex����ͬ���±껻��k������±�
			}
		}
	}
}
