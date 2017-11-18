// 左倾（式）堆.cpp : 定义控制台应用程序的入口点。
//左式堆同其他的堆一样，也具有结构特性和有序性。
//事实上，左式堆也是二叉树，而它和二叉树唯一的区别是：左式堆不是理想平衡的，实际上是趋于非常不平衡的（从字面就可以理解）。
//零路径长（Npl(X))：任一结点X到一个没有两个儿子的结点的最短路径的长度。具有0个或1个儿子的结点的零路径长为0，而Npl(NULL)=-1;
//零路径长保存在结点内（结构体中的一个域），且任一路径的零路径长比它的诸儿子结点的零路径长的最小值多1.
//左式堆性质：对于堆中的每一个结点，左儿子的零路径长至少与右儿子的零路径长一样大。


#include "stdafx.h"
#include "LeftHeap.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	PriorityQueue H1;
	PriorityQueue H2;
	H1 = Initialize();
	H2 = Initialize();
	cout << "打印左倾堆H1：";
	PrintTree(H1);
	cout << endl;
	cout << "打印左倾堆H2：";
	PrintTree(H2);
	cout << endl;
	//填充H1
	Insert(3, H1);
	Insert(10, H1);
	Insert(8, H1);
	Insert(21, H1);
	Insert(14, H1);
	Insert(17, H1);
	Insert(23, H1);
	Insert(26, H1);
	//填充H2
	Insert(6, H2);
	Insert(12, H2);
	Insert(7, H2);
	Insert(18, H2);
	Insert(24, H2);
	Insert(37, H2);
	Insert(19, H2);
	Insert(33, H2);
	cout << "打印填充后的H1：";
	PrintTree(H1);
	cout << endl;
	cout << "打印填充后的H2：";
	PrintTree(H2);
	cout << endl;
	cout << "合并H1和H2，并打印：";
	PriorityQueue merge;
	merge = Merge(H1, H2);
	PrintTree(merge);
	cout << endl;
	DeleteMin(merge);
	PrintTree(merge);
	getchar();
    return 0;
}

