#include "stdafx.h"
#include "merge_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*�����Ĺ鲢�����ʵ�ֺ���*/
void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Left + Right) / 2;//��������м�ֳ�����
		MSort(A, TmpArray, Left, Center);//���һ����еݹ�
		MSort(A, TmpArray, Center + 1, Right);//�ұ�һ��Ҳ���еݹ�
		Merge(A, TmpArray, Left, Center + 1, Right);//�������뿪ʼ�ϲ�
	}
}

void MergeSort(ElementType A[], int N)  //�鲢������������̣��ڲ����������Ĺ鲢ʵ�ֺ���MSort
{
	ElementType * TmpArray;
	TmpArray = (ElementType *)malloc(N * sizeof(ElementType));
	if (TmpArray != NULL)
	{
		MSort(A, TmpArray, 0, N - 1);//left��right�ֱ�Ϊ������Ԫ�غ��������Ԫ��
		delete TmpArray;
	}
	else
	{
		cout << "û�п�Ϊ��ʱ�������Ŀռ䣡\n";
		getchar();
		exit(-1);
	}
}

/*Lpos�����ߵĿ�ͷ��Rpos���Ұ�ߵĿ�ͷ*/
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;//���öഫ��һ��������ֱ����Rpos�����Ƴ�LeftEnd����ʡ�ռ�
	TmpPos = Lpos;//��ʱָ���ȸ�ֵ��Lpos
	NumElements = RightEnd - Lpos + 1;//�����Ԫ�ظ���Ҳ���õ����������ݽ���

	/*��ѭ��*/
	while (Lpos <= LeftEnd && Rpos <= RightEnd)//������������Ҽ�������û�дﵽ����ĩβ��ʱ��
	{
		if (A[Lpos] <= A[Rpos])//������ߵĵ�ǰԪ��С���Ұ�ߵĵ�ǰԪ��
		{
			TmpArray[TmpPos++] = A[Lpos++];//���A����ĵ�ǰԪ�ش浽��ʱ������
		}
		else
		{
			TmpArray[TmpPos++] = A[Rpos++];//����Ұ�ߵĵ�ǰԪ��С�����ߵĵ�ǰԪ�أ����B����ĵ�ǰԪ�ش浽��ʱ������
		}
	}
	/*�����ߺ��Ұ����һ���Ѿ�ѭ�����˵Ļ������˳�ѭ��*/
	while (Lpos <= LeftEnd)//���������û��ѭ����
	{
		TmpArray[TmpPos++] = A[Lpos++];//�Ͱ����ߵ�ʣ��Ԫ�ض�������ʱ������
	}
	while (Rpos <= RightEnd)
	{
		TmpArray[TmpPos++] = A[Rpos++];//����Ͱ��Ұ�ߵ�ʣ��Ԫ�ض�������ʱ������
	}

	/*����ʱ�����ٸ��Ƶ�ԭ���������У����Ʋ��ݻỨ��һ����ʱ�䣬���������Ե�O(N)*/
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
