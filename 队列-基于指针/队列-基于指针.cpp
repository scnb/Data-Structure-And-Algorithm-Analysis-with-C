// 队列-基于链表.cpp : 定义控制台应用程序的入口点。
//基于链表的队列就是动态队列，它的每一个结点可以自由的创建和删除，不用像数组那个静态队列一样，必须要是循环队列才可以
//并且动态队列只有空，没有满
//通过在Enqueue函数中添加静态变量i，使得front能够正常的指向起始元素

#include "stdafx.h"
#include "queue.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Queue Q = CreateQueue();
	Show(Q);
	Enqueue(1, Q);
	Enqueue(2, Q);
	Enqueue(3, Q);
	Show(Q);
	Enqueue(4, Q);
	Enqueue(5, Q);
	Show(Q);
	cout << "出队的元素为：" << FrontAndDequeue(Q) << endl;
	cout << "出队的元素为：" << FrontAndDequeue(Q) << endl;
	cout << "出队的元素为：" << FrontAndDequeue(Q) << endl;
	cout << "出队的元素为：" << FrontAndDequeue(Q) << endl;
	cout << "出队的元素为：" << FrontAndDequeue(Q) << endl;
	cout << "出队的元素为：" << FrontAndDequeue(Q) << endl;
	cout << "出队的元素为：" << FrontAndDequeue(Q) << endl;
	getchar();
	return 0;
}



