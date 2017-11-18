#include "stdafx.h"
#include "merge_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*真正的归并排序的实现函数*/
void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Left + Right) / 2;//把数组从中间分成两半
		MSort(A, TmpArray, Left, Center);//左边一半进行递归
		MSort(A, TmpArray, Center + 1, Right);//右边一半也进行递归
		Merge(A, TmpArray, Left, Center + 1, Right);//左右两半开始合并
	}
}

void MergeSort(ElementType A[], int N)  //归并排序的驱动例程，内部调用真正的归并实现函数MSort
{
	ElementType * TmpArray;
	TmpArray = (ElementType *)malloc(N * sizeof(ElementType));
	if (TmpArray != NULL)
	{
		MSort(A, TmpArray, 0, N - 1);//left和right分别为数组首元素和数组最后元素
		delete TmpArray;
	}
	else
	{
		cout << "没有可为临时数组分配的空间！\n";
		getchar();
		exit(-1);
	}
}

/*Lpos是左半边的开头，Rpos是右半边的开头*/
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;//不用多传递一个参数，直接用Rpos就能推出LeftEnd，节省空间
	TmpPos = Lpos;//临时指针先赋值成Lpos
	NumElements = RightEnd - Lpos + 1;//数组的元素个数也不用当作参数传递进来

	/*主循环*/
	while (Lpos <= LeftEnd && Rpos <= RightEnd)//当左计数器和右计数器都没有达到数组末尾的时候
	{
		if (A[Lpos] <= A[Rpos])//如果左半边的当前元素小于右半边的当前元素
		{
			TmpArray[TmpPos++] = A[Lpos++];//则把A数组的当前元素存到临时数组中
		}
		else
		{
			TmpArray[TmpPos++] = A[Rpos++];//如果右半边的当前元素小于左半边的当前元素，则把B数组的当前元素存到临时数组中
		}
	}
	/*当左半边和右半边有一个已经循环完了的话，就退出循环*/
	while (Lpos <= LeftEnd)//如果是左半边没有循环完
	{
		TmpArray[TmpPos++] = A[Lpos++];//就把左半边的剩余元素都存在临时数组中
	}
	while (Rpos <= RightEnd)
	{
		TmpArray[TmpPos++] = A[Rpos++];//否则就把右半边的剩余元素都存在临时数组中
	}

	/*把临时数组再复制到原来的数组中，复制操纵会花费一定的时间，但是是线性的O(N)*/
	for (i = 0;i < NumElements;i++, RightEnd--)
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}

void Show(ElementType A[], int N)
{
	for (int i = 0;i < N;i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
