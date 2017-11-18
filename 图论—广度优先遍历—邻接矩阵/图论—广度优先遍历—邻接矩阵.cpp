// 图论—广度优先遍历—邻接矩阵.cpp : 定义控制台应用程序的入口点。
//广度优先遍历：Breadth_First_Search，又称广度优先搜索，BFS
//广度优先遍历类似与树的层序遍历，一层一层的逐步扩大查找范围。
//其基本思想是创建一个空队列，对于每一个顶点用Enqueue入队，然后用Dequeue出队,并将出队的值存在i中，遍历与i邻接的边，
//如果存在且没有访问过，则访问这些顶点（其实就是输出顶点的值）再将与顶点i邻接的几个顶点用Enqueue入队,重复上述步骤。

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
	cout << "显示图：";
	BFSTraverse(G);
	getchar();
	getchar();
    return 0;
}

