#include "stdafx.h"
#include "heap_sort.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if (MaxElements < MinPQSize)
	{
		cout << "Ԫ�ظ���̫�٣��޷����ɶ���ѣ�\n";
		cout << "���������룺";
		cin >> MaxElements;
	}
	H = new struct HeapStruct;
	if (H == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		getchar();
		exit(-1);
	}
	H->Elements = (ElementType*)malloc(sizeof(ElementType)*(MaxElements + 1));//��С+1��Ϊ��������ͷ���洢һ��Seninel����ǣ��������ڲ������ʱ���бȽ�
	if (H->Elements == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		getchar();
		exit(-1);
	}
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;
	return H;
}

void Destroy(PriorityQueue H)
{
	delete H->Elements;
	delete H;
	cout << "������ѱ����٣�" << endl;
}

void MakeEmpty(PriorityQueue H)
{
	for (int i = 0;i <= H->Size;i++)
	{
		H->Elements[i] = 0;
	}
	H->Size = 0;
}

void Insert(ElementType X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		cout << "�����������\n";
		return;
	}
	for (i = ++H->Size;H->Elements[i / 2] > X;i /= 2)//i����һ������Ԫ�ؿ�ʼ���ж������Ǹ��ڵ�(i/2)��Ҫ�����Ԫ�ش�
	{
		H->Elements[i] = H->Elements[i / 2];//������ڵ��Ҫ�����Ԫ�ش���Ѹ��ڵ����ӽڵ��ƶ�
	}
	H->Elements[i] = X;
}

/*
ɾ����СԪ�صĺ�������ȡ�ö��������С��Ԫ�غܼ򵥣���Ϊ�����ڸ���㴦��Ҳ��������ĵڶ���Ԫ��
�����ѵ��ǣ�ɾ�����ڵ�󣬱���Ѻ����Ԫ�������ƶ������ʵ�λ�ã����������
��ѵĶ�������
����ɾ�����ڵ�����һ������λ��Ҳ����ҲҪ�仯����Ϊ������ǰ����Ϊ����
Ԫ�ص����������˿�Ѩ��������Ҫ���һ�����ȥ���
*/

ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;
	if (IsEmpty(H))
	{
		cout << "�����Ϊ�գ��޷�ɾ����\n";
		return H->Elements[0];
	}
	MinElement = H->Elements[1];//ȡ�������Ķ���ѵ���Сֵ
	LastElement = H->Elements[H->Size--];//ȡ�ö���ѵ����һ��Ԫ��

	for (i = 1;i * 2 <= H->Size;i = Child)//��ÿһ��ѭ���У�i�Ǹ��ڵ��������Child�����ӵ�����
	{
		Child = i * 2;					 //���ڵ���������2�������ӵ�����
										 /*�����жϣ�������û�е�������ЧԪ��ĩ��
										 �ڱȽ����Ӻ��Һ���˭��С����С�����Ƶ����ڵ�Ŀ�Ѩ*/
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
		{
			Child++;//����Һ��Ӹ�С����Child����1����Ϊ�Һ��ӵ�����
		}
		if (LastElement > H->Elements[Child])//�����������һ��Ԫ�ش��ڵ�ǰ������Ԫ��
		{
			H->Elements[i] = H->Elements[Child];
		}
		else
		{
			break;
		}
	}
	H->Elements[i] = LastElement;//����ԭ�������һ��Ԫ�ش�����ʵ�λ��
	return MinElement;
}

ElementType FindMin(PriorityQueue H)
{
	return H->Elements[1];
}

int IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
	return H->Size == H->Capacity;
}

void ShowHeap(PriorityQueue H)
{
	for (int i = 1;i <= H->Size;i++)
	{
		cout << H->Elements[i] << " ";
	}
	cout << endl;
}
