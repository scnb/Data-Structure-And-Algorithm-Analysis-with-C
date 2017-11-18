#include "stdafx.h"
#include "bucket_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void BucketSort(ElementType A[], int N, int M)
{
	ElementType * temp;
	temp = new ElementType[M];
	static int q = 0;
	for (int i = 0;i < M;i++)
	{
		*(temp + i) = 0;
	}
	for (int i = 0;i < N;i++)
	{
		(*(temp + A[i]))++;
	}
	for (int j = 0;j < M;j++)
	{
		if (*(temp + j) != 0)
		{
			for (int k = 0;k < *(temp+j);k++)
			{
				A[q++] = j;
			}
		}
		else
		{
			continue;
		}
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
