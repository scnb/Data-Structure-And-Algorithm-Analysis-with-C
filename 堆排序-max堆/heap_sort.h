#pragma once
#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#define Size 7

typedef int ElementType;

void PercDown(ElementType A[], int i, int N);
void HeapSort(ElementType A[], int N);
void Show(ElementType A[], int N);
void Swap(ElementType *, ElementType *);

#endif // !HEAP_SORT_H_


