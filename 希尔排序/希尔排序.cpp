// 希尔排序.cpp : 定义控制台应用程序的入口点。
//第一批冲破二次时间屏障的算法之一，由Donald Shell发明。
//它通过比较相距一定距离的元素来工作，各趟比较所用的间隔距离随着算法的进行而减小，
//直到最后一趟排序——只比较相邻元素为止。
//其中比较元素的部分用的是插入排序算法，只不过插入排序是一个一个元素挨个比较的，而希尔排序是有间距的比较。
//希尔排序有一个增量序列，来决定每一趟排序中元素的间隔，这个序列是递减的。
//一趟排序就是对h个独立的子序列执行一次插入排序。
//Shell建议的增量序列是：ht=[N/2]，hk=[h(k+1)/2]，其中ht是最大的增量

//希尔排序的运行时间依赖于增量序列的选择

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef int ElementType;

void ShellSort(ElementType A[], int N);
void Show(ElementType A[], int N);

int main()
{
	ElementType arr[13] = { 81,94,11,96,12,35,17,95,28,58,41,75,15 };
	cout << "排序之前：";
	Show(arr, 13);
	cout << "排序之后：";
	ShellSort(arr, 13);
	Show(arr, 13);
	getchar();
    return 0;
}

/*显示数组中的每一个元素*/
void Show(ElementType A[], int N)
{
	for (int i = 0;i < N;i++)
	{
		cout << A[i] << " ";
	}
}

void ShellSort(ElementType A[], int N)
{
	int i, j, Increment;
	ElementType temp;
	for (Increment = N / 2;Increment > 0;Increment /= 2)//最外层大循环，产生递减的增量序列
	{
		for (i = Increment;i < N;i++)//从某一个增量对应的数组位置开始
		{
			temp = A[i];//将当前的元素存在临时变量中
			for (j = i;j >= Increment;j -= Increment)//从这里往下其实就是插入排序，即把temp和它前面的若干个元素“挨个”进行比较，不同的一点是，在希尔排序中，比较不是挨个的，而是根据增量跳变的
			{
				if (temp < A[j - Increment])
				{
					A[j] = A[j - Increment];
				}
				else
				{
					break;
				}
			}
			A[j] = temp;
		}
	}
}
