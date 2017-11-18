// 快速排序.cpp : 定义控制台应用程序的入口点。
//采用了分治的策略和递归的思想，即把数组分成两半，递归的进行分组，然后再对每一组排序，再把这些子数组
//合并起来。
//不同于归并排序的是，在快速排序中，用3数值中值法选定了一个枢纽元，所以分组是关于枢纽元进行的，
//一半小于枢纽元，一半大于枢纽元。
//在程序设计中还有一点需要注意的是：对于大数组（自己定义元素个数，一般是10个以上）采用快速排序，对于
//小数组，采用插入排序。

#include "stdafx.h"
#include "quick_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[10] = { 8,1,4,9,6,3,5,2,7,0 };
	cout << "排序之前：";
	Show(arr, 10);
	cout << "排序之后：";
	QuickSort(arr, 10);
	Show(arr, 10);
	getchar();
    return 0;
}

