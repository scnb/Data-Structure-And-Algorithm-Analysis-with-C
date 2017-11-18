#include "stdafx.h"
#include "heap_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define LeftChild(i) (2*(i)+1)//因为在本程序中的模型是，第0位为根节点，所以左孩子为2*i+1，右孩子为2*i+2

void PercDown(ElementType A[], int i, int N)//下滤操作，使堆递减排序，使父亲关键字的值大于孩子关键字的值，方便排序后成为递增的序列
{
	int Child;
	ElementType temp;
	for (temp = A[i];LeftChild(i) < N;i = Child)
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])
		{
			Child++;
		}
		if (temp < A[Child])
		{
			A[i] = A[Child];
		}
		else
		{
			break;
		}
	}
	A[i] = temp;
}

void Swap(ElementType * a, ElementType * b)
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void HeapSort(ElementType A[], int N)
{
	int i;
	for (i = N / 2;i >= 0;i--)   //第一步，“重新”（不是重新，而就是构建一个堆，因为原来的数组是随机的。它的元素的排列不一定是一个堆。原来的理解有偏差）构建一个堆，使其父节点的值大于孩子结点的值
	{
		PercDown(A, i, N);
	}
	cout << "中间过程：";
	Show(A, N);
	for (i = N - 1;i > 0;i--) //i是递减的，其实每次数组的最后都是当前的最大值，所以就不用管数组最后的元素了，相当于每一次循环，需要处理的元素就少一个。
	{
		Swap(&A[0], &A[i]);//把根节点和最后结点的元素互换，这个就是删除根节点以及把根节点存储到数组最后的过程
		PercDown(A, 0, i);//再把余下的结点进行一次下滤，使根节点为最大值
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
