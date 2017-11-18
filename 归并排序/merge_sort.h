#pragma once
#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

typedef int ElementType;

void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right);
void MergeSort(ElementType A[], int N);
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd);
void Show(ElementType A[], int N);

#endif // !MERGE_SORT_H_
