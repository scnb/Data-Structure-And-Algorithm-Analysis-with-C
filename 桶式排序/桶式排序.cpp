// 桶式排序.cpp : 定义控制台应用程序的入口点。
//以线性时间完成排序功能
//为使桶式排序能够正常工作，必须要有一些额外的信息，例如：
//数组Array的元素A1，A2，A3……AN，必须只由小于M的正整数组成。
//则算法为：使用一个大小为M的名为Count的数组，其被初始化为全0。于是，Count有M个桶。
//依次读入原数组Array的各个元素，当读入Ai时，Count[Ai]增加1。循环完后，扫描Count数组，其下标对应的
//元素不为0的话，说明原Array数组中有大小等于该下标的元素。
//在纸上画图演示一下能够清晰明了的弄清楚。

#include "stdafx.h"
#include "bucket_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[9] = { 5,2,3,1,4 ,5,6,3,8};
	cout << "排序之前：";
	Show(arr, 9);
	cout << "排序之后：";
	BucketSort(arr, 9, 10);
	Show(arr, 9);
	getchar();
    return 0;
}

