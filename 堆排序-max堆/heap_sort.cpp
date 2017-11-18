#include "stdafx.h"
#include "heap_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define LeftChild(i) (2*(i)+1)//��Ϊ�ڱ������е�ģ���ǣ���0λΪ���ڵ㣬��������Ϊ2*i+1���Һ���Ϊ2*i+2

void PercDown(ElementType A[], int i, int N)//���˲�����ʹ�ѵݼ�����ʹ���׹ؼ��ֵ�ֵ���ں��ӹؼ��ֵ�ֵ������������Ϊ����������
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
	for (i = N / 2;i >= 0;i--)   //��һ���������¡����������£������ǹ���һ���ѣ���Ϊԭ��������������ġ�����Ԫ�ص����в�һ����һ���ѡ�ԭ���������ƫ�����һ���ѣ�ʹ�丸�ڵ��ֵ���ں��ӽ���ֵ
	{
		PercDown(A, i, N);
	}
	cout << "�м���̣�";
	Show(A, N);
	for (i = N - 1;i > 0;i--) //i�ǵݼ��ģ���ʵÿ�����������ǵ�ǰ�����ֵ�����ԾͲ��ù���������Ԫ���ˣ��൱��ÿһ��ѭ������Ҫ�����Ԫ�ؾ���һ����
	{
		Swap(&A[0], &A[i]);//�Ѹ��ڵ��������Ԫ�ػ������������ɾ�����ڵ��Լ��Ѹ��ڵ�洢���������Ĺ���
		PercDown(A, 0, i);//�ٰ����µĽ�����һ�����ˣ�ʹ���ڵ�Ϊ���ֵ
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
