// ͼ�ۡ�������ȱ������ڽӾ���.cpp : �������̨Ӧ�ó������ڵ㡣
//������ȱ�����Breadth_First_Search���ֳƹ������������BFS
//������ȱ������������Ĳ��������һ��һ�����������ҷ�Χ��
//�����˼���Ǵ���һ���ն��У�����ÿһ��������Enqueue��ӣ�Ȼ����Dequeue����,�������ӵ�ֵ����i�У�������i�ڽӵıߣ�
//���������û�з��ʹ����������Щ���㣨��ʵ������������ֵ���ٽ��붥��i�ڽӵļ���������Enqueue���,�ظ��������衣

#include "stdafx.h"
#include <iostream>
#include "bfs.h"

using std::cin;
using std::cout;
using std::endl;


int main()
{
	MGraph G;
	CreateGraph(&G);
	cout << "��ʾͼ��";
	BFSTraverse(G);
	getchar();
	getchar();
    return 0;
}

