#pragma once
#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

#define MinPQSize 5
#define MinData 0

struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;
typedef int ElementType;

struct HeapStruct
{
	int Capacity;//堆的容量
	int Size;//堆中的元素个数
	ElementType * Elements;//使用动态数组来存储元素
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


#endif // !BINARY_HEAP_H_