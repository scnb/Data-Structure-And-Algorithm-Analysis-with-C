#include "stdafx.h"
#include "quick_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Swap( ElementType * a, ElementType * b)
{
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


/*ʹ��3��ֵ��ֵ��������ŦԪ����ŦԪȡ3��ֵ���м�ֵ*/
ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;//3��ֵ��ֵ���ֱ����������Ԫ�ء��Ҷ�Ԫ�غ��м�Ԫ��
	/*��������if-else��3����ֵ���������򣬼�A[Left]<=A[Center]<=A[Right]*/
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
		Swap(&A[Center], &A[Right]);
	}
	/*����ŦԪ�����鵹���ڶ���Ԫ�ؽ���λ�ã�֮�������뵹���ڶ���Ԫ�ؽ���������Ϊǰ��������Ѿ���֤����Ԫ��С����ŦԪ��βԪ�ش�����ŦԪ*/
	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];//������ŦԪ��ֵ
}

/*�����������̣�������С����*/
void InsertionSort(ElementType A[], int N)
{
	int j, P;
	ElementType temp;
	for (P = 1;P < N;P++)
	{
		temp = A[P];
		for (j = P;j > 0 && A[j - 1] > temp;j--)//��A[P]֮ǰ��Ԫ�ذ�����A[P]�Ƚϣ�˭��A[P]�󣬾ͻ�λ��
		{
			A[j] = A[j - 1];                    //ע��ӦΪ����һֱ���Ǹ���ֵtemp�Ƚϣ�������ʵ���ǿ�temp����ǰ�߶�Զ��������ǰ��ļ���ֵС��ֱ��������tempС�ģ���ֹͣǰ�ƣ����ǰ�temp�������λ��
		}
		A[j] = temp;
	}
}

void QSort(ElementType A[], int Left, int Right)
{
	int i, j;
	ElementType Pivot;
	if (Left + Cutoff <= Right)//���жϸ������ǲ���С���飬�������Ԫ�س���Cutoff�Ļ�����ִ�п�������
	{
		Pivot = Median3(A, Left, Right);//�õ���ŦԪ��ֵ���������Ƚ�
		i = Left;//��ֵ��ǣ���Median3�������Ѿ���3��ֵ�Ź����ˣ������i���Ǵ���˿�ʼ
		j = Right - 1;
		for (;;)//��forѭ�����˳�����ʵ������if-else�ж��У�����i��j������˳�ѭ��
		{
			while (A[++i] < Pivot) {}//������whileѭ����ɵĲ����ǣ�iԽ����Щ����ŦԪС��Ԫ�أ�
			while (A[--j] > Pivot) {}//��jԽ����Щ����ŦԪ���Ԫ��
			/*����ϱ�while������������i��jֹͣ�ƶ����±��ж�i�Ƿ�С��j����С�ڣ��򽻻�Ԫ��*/
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

		/*����forѭ��ʹi��j���ý�������������ŦԪΪ��׼���ֳ�����һ��һС����*/
		QSort(A, Left, i - 1);/*�ݹ�ؽ���ŦԪ����Ԫ�ؽ�������*/
		QSort(A, i + 1, Right);/*�ݹ�ؽ���ŦԪ�Ҳ��Ԫ�ؽ�������*/
	}
	else//�����������С���飬������Ԫ��С��Cutoff������ִ�в�������
	{
		InsertionSort(A + Left, Right - Left + 1);
	}
}

void QuickSort(ElementType A[], int N)
{
	QSort(A, 0, N - 1);
}

void Show(ElementType A[], int N)
{
	if (N == 0)
	{
		cout << "����Ϊ�գ�\n";
		return;
	}
	for (int i = 0;i < N;i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
