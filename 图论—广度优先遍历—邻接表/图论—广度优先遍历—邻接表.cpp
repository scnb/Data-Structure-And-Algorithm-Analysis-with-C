// ͼ�ۡ�������ȱ������ڽӱ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "bfs.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{	
	GraphAdjList G;
	CreateGraph(&G);
	cout << "��ʾͼ��";
	BFSTraverse(G);
	getchar();
	getchar();
    return 0;
}


