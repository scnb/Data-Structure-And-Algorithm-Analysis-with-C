#pragma once
#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include <iostream>

#define MinPQSize 0
#define MinData -INFINITY

struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;
typedef int ElementType;

struct HeapStruct
{
	int Capacity;//�ѵ�����
	int Size;//���е�Ԫ�ظ���
	ElementType * Elements;//ʹ�ö�̬�������洢Ԫ��
};

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void ShowHeap(PriorityQueue H);

#endif // !HEAP_SORT_H_

