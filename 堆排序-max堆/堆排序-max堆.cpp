// 堆排序-max堆.cpp : 定义控制台应用程序的入口点。
//基于二叉堆中DeleteMin()方法的排序叫做堆排序，
//按照顺序，最小的元素先离开堆，因此可以用另一个数组来存储从堆中出来的元素。
//上述方法存在一个问题，即使用了一个附加数组，所以会占用空间（想象有一亿个元素），
//可以用堆自身来存储从堆中删除的元素。
//该方法为：在每次DeleteMin之后，堆缩小了1，位于堆中最后的单元就会空缺，可以用来存放刚删除的元素。
//使用上述策略，就会以递减的方式来存储数组，要想使该堆删除完毕后，元素是以递增来排列的，
//可以改变堆的序的特性，即父节点的关键字的值大于子节点的关键字的值。
//另外，对任意数组进行堆排序，首先要确保该数组满足堆的特性要求，
//保险的方法是进行堆排序前，先对数组进行操作，构建一个堆。（使用PercDown()函数）

#include "stdafx.h"
#include "heap_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[Size] = {97,53,59,26,41,65,31};
	cout << "排序之前：";
	Show(arr, Size);
	HeapSort(arr, Size);
	cout << "排序之后：";
	Show(arr, Size);
	getchar();
    return 0;
}

