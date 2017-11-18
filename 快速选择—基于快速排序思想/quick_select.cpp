#include "stdafx.h"
#include "quick_select.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void QSelect(ElementType A[], int k, int Left, int Right)
{
	int i, j;
	ElementType Pivot;
	if (Left + Cutoff <= Right)//如果是大数组，则用快速排序法
	{
		Pivot = Median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for (;;)
		{
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			if (i < j)
			{
				Swap(&A[i], &A[j]);
			}
			else
			{
				break;
			}
		}
		Swap(&A[i], &A[Right - 1]);
		if (k <= i)//表明第k个最小元在左半边的数组中
		{
			QSelect(A, k, Left, i - 1);
		}
		else if (k > i + 1)//说明第k个最小元在右半边的数组中
		{
			QSelect(A, k, i + 1, Right);
		}
	}
	else
	{
		InsertionSort(A + Left, Right - Left + 1);
	}
}

void QuickSelect(ElementType A[], int k,int N)
{
	QSelect(A, k, 0, N - 1);
}

void Swap(ElementType * a, ElementType * b)
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*3数值中间值法取得枢纽元*/
ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
	{
		Swap(&A[Left], &A[Center]);
	}
	if (A[Left] > A[Right])
	{
		Swap(&A[Left], &A[Right]);
	}
	if (A[Center] > A[Right])
	{
		Swap(&A[Center] , &A[Right]);
	}
	/*上述if-else使A[Left]<=A[Center]<=A[Right]*/
	Swap(&A[Center], &A[Right-1]);//将枢纽元移出分割区域
	return A[Right - 1];//返回枢纽元
}

void InsertionSort(ElementType A[], int N)
{
	int i, j;
	ElementType temp;
	for (i = 1;i < N;i++)
	{
		temp = A[i];
		for (j = i;j > 0 && A[j - 1] > temp;j--)//插入排序可以想象是一群不同身高的人排队，一个人连续的在队伍的缝隙中插进去，如果它前边的人比它高，则它继续往前插，相当于把前面的人放在了后面的位置上。
		{
			A[j] = A[j - 1];
		}
		A[j] = temp;
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
