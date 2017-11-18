// 优先队列—二叉堆.cpp : 定义控制台应用程序的入口点。
//优先队列：一种特殊的队列。但是却用树来实现.
/*优先队列是至少允许下列两种操作的数据结构：①Insert 插入
											②DeleteMin 找出、返回和删除优先队列中最小的元素
  当堆（Heap）不加修饰地使用时一般都是指优先队列。
二叉堆：简称堆，优先队列的一种实现。
有两个性质：
			  ①结构性质：堆是一个完全被填满的二叉树，有可能的例外是在底层，底层上的元素从左向右插入
			  ②堆序性质：在一个堆中，对于每一个结点X，X的父亲中的关键字小于或等于X的关键字。即最小的元素在根结点处。
*/

#include "stdafx.h"
#include "binary_heap.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	PriorityQueue h;
	h = Initialize(20);
	cout << "显示二叉堆：";
	ShowHeap(h);
	Insert(13, h);
	Insert(21, h);
	Insert(16, h);
	Insert(24, h);
	Insert(31, h);
	Insert(19, h);
	Insert(68, h);
	Insert(65, h);
	Insert(26, h);
	Insert(32, h);
	cout << "显示二叉堆：";
	ShowHeap(h);
	Insert(14, h);
	cout << "显示二叉堆：";
	ShowHeap(h);
	cout << "清空二叉堆：\n";
	MakeEmpty(h);
	cout << "显示二叉堆：";
	ShowHeap(h);
	Insert(13, h);
	Insert(14, h);
	Insert(16, h);
	Insert(19, h);
	Insert(21, h);
	Insert(19, h);
	Insert(68, h);
	Insert(65, h);
	Insert(26, h);
	Insert(32, h);
	Insert(31, h);
	cout << "显示二叉堆：";
	ShowHeap(h);
	cout << "删除最小的元素为：" << DeleteMin(h) << endl;
	cout << "显示二叉堆：";
	ShowHeap(h);
	cout << "销毁二叉堆：";
	Destroy(h);
	getchar();
    return 0;
}

