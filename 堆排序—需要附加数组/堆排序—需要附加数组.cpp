// 堆排序—需要附加数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "heap_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[20];
	PriorityQueue h;
	h = Initialize(20);
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
	cout << "排序之前：";
	ShowHeap(h);
	cout << "排序之后：";
	for (int i = 0;i < 10;i++)  //因为在DeleteMin中h->Size是会减小的，所以不能用i<h->Size来判断
	{
		arr[i] = DeleteMin(h);
	}
	for (int i = 0;i < 10;i++)
	{
		cout << arr[i] << " ";
	}
	getchar();
    return 0;
}

