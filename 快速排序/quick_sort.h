#pragma once
#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#define Cutoff (3)

typedef int ElementType;

void Swap(ElementType * a, ElementType * b);
ElementType Median3(ElementType A[], int Left, int Right);
void QSort(ElementType A[], int Left, int Right);
void QuickSort(ElementType A[], int N);//快速排序的驱动程序，内部调用QSort
void InsertionSort(ElementType A[], int N);
void Show(ElementType A[], int N);


#endif // !QUICK_SORT_H_
