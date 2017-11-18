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
	if (Left + Cutoff <= Right)//����Ǵ����飬���ÿ�������
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
		if (k <= i)//������k����СԪ�����ߵ�������
		{
			QSelect(A, k, Left, i - 1);
		}
		else if (k > i + 1)//˵����k����СԪ���Ұ�ߵ�������
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

/*3��ֵ�м�ֵ��ȡ����ŦԪ*/
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
	/*����if-elseʹA[Left]<=A[Center]<=A[Right]*/
	Swap(&A[Center], &A[Right-1]);//����ŦԪ�Ƴ��ָ�����
	return A[Right - 1];//������ŦԪ
}

void InsertionSort(ElementType A[], int N)
{
	int i, j;
	ElementType temp;
	for (i = 1;i < N;i++)
	{
		temp = A[i];
		for (j = i;j > 0 && A[j - 1] > temp;j--)//�����������������һȺ��ͬ��ߵ����Ŷӣ�һ�����������ڶ���ķ�϶�в��ȥ�������ǰ�ߵ��˱����ߣ�����������ǰ�壬�൱�ڰ�ǰ����˷����˺����λ���ϡ�
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
