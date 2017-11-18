// 快速选择—基于快速排序思想.cpp : 定义控制台应用程序的入口点。
//基于快速排序的思想，将一个数组关于枢纽元进行分割，如果k小于等于左半边数组元素个数，
//则第k个最小元一定在左半边数组中，否则就在右半边的数组中。然后进行递归调用。
//当算法终止的时候，第k个元素就在数组的第k个位置上，当然对应的数组下标是k-1。

#include "stdafx.h"
#include "quick_select.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[10] = { 8,1,4,9,0,3,5,2,7,6 };
	cout << "排序之前：";
	Show(arr, 10);
	cout << "排序之后：";
	cout << "第4个最小元为：";
	QuickSelect(arr, 4, 10);
	cout<<arr[3]<<endl;
	Show(arr, 10);
	getchar();
    return 0;
}

