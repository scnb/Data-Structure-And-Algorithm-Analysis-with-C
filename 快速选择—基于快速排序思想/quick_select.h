#pragma once
#ifndef QUICK_SELECT
#define QUICK_SELECT

#define Cutoff (3)

typedef int ElementType;

void QSelect(ElementType A[], int k, int Left, int Right);
void Swap(ElementType * a, ElementType * b);
ElementType Median3(ElementType A[], int Left, int Right);
void InsertionSort(ElementType A[], int N);
void Show(ElementType A[], int N);
void QuickSelect(ElementType A[], int k, int N);//快速选择的驱动程序

#endif // !QUICK_SELECT
