// 图论—广度优先遍历—邻接表.cpp : 定义控制台应用程序的入口点。
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
	cout << "显示图：";
	BFSTraverse(G);
	getchar();
	getchar();
    return 0;
}


