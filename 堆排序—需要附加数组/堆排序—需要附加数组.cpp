// ��������Ҫ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "heap_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[20];
	PriorityQueue h;
	h = Initialize(20);
	Insert(13, h);
	Insert(21, h);
	Insert(16, h);
	Insert(24, h);
	Insert(31, h);
	Insert(19, h);
	Insert(68, h);
	Insert(65, h);
	Insert(26, h);
	Insert(32, h);
	cout << "����֮ǰ��";
	ShowHeap(h);
	cout << "����֮��";
	for (int i = 0;i < 10;i++)  //��Ϊ��DeleteMin��h->Size�ǻ��С�ģ����Բ�����i<h->Size���ж�
	{
		arr[i] = DeleteMin(h);
	}
	for (int i = 0;i < 10;i++)
	{
		cout << arr[i] << " ";
	}
	getchar();
    return 0;
}

