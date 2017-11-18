// 归并排序.cpp : 定义控制台应用程序的入口点。
//归并排序，顾名思义,就是把一个数组，分成两部分，每一部分分别排序，然后再用Merge()函数合并起来
//其中，在排序中用到了递归的思想，即一个数组，分成两部分之后，每一部分还可以再分成两部分。
//如此一直分到只剩下两个元素，然后进行比较，再回溯。
//其中，还涉及到了三个“指针”（Lpos，Rpos，Tempos），其实就是数组的索引，用来指示每个子数组当前的元素

#include "stdafx.h"
#include "merge_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[8] = { 1,13,24,26,2,15,27,38 };
	cout << "排序之前：";
	Show(arr, 8);
	MergeSort(arr, 8);
	cout << "排序之后：";
	Show(arr, 8);
	getchar();
    return 0;
}

