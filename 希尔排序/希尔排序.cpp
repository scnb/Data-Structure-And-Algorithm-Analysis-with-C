// ϣ������.cpp : �������̨Ӧ�ó������ڵ㡣
//��һ�����ƶ���ʱ�����ϵ��㷨֮һ����Donald Shell������
//��ͨ���Ƚ����һ�������Ԫ�������������˱Ƚ����õļ�����������㷨�Ľ��ж���С��
//ֱ�����һ�����򡪡�ֻ�Ƚ�����Ԫ��Ϊֹ��
//���бȽ�Ԫ�صĲ����õ��ǲ��������㷨��ֻ��������������һ��һ��Ԫ�ذ����Ƚϵģ���ϣ���������м��ıȽϡ�
//ϣ��������һ���������У�������ÿһ��������Ԫ�صļ������������ǵݼ��ġ�
//һ��������Ƕ�h��������������ִ��һ�β�������
//Shell��������������ǣ�ht=[N/2]��hk=[h(k+1)/2]������ht����������

//ϣ�����������ʱ���������������е�ѡ��

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
	cout << "����֮ǰ��";
	Show(arr, 13);
	cout << "����֮��";
	ShellSort(arr, 13);
	Show(arr, 13);
	getchar();
    return 0;
}

/*��ʾ�����е�ÿһ��Ԫ��*/
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
	for (Increment = N / 2;Increment > 0;Increment /= 2)//������ѭ���������ݼ�����������
	{
		for (i = Increment;i < N;i++)//��ĳһ��������Ӧ������λ�ÿ�ʼ
		{
			temp = A[i];//����ǰ��Ԫ�ش�����ʱ������
			for (j = i;j >= Increment;j -= Increment)//������������ʵ���ǲ������򣬼���temp����ǰ������ɸ�Ԫ�ء����������бȽϣ���ͬ��һ���ǣ���ϣ�������У��Ƚϲ��ǰ����ģ����Ǹ������������
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
