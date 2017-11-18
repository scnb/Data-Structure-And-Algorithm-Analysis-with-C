// ���ȶ��С������.cpp : �������̨Ӧ�ó������ڵ㡣
//���ȶ��У�һ������Ķ��С�����ȴ������ʵ��.
/*���ȶ��������������������ֲ��������ݽṹ����Insert ����
											��DeleteMin �ҳ������غ�ɾ�����ȶ�������С��Ԫ��
  ���ѣ�Heap���������ε�ʹ��ʱһ�㶼��ָ���ȶ��С�
����ѣ���ƶѣ����ȶ��е�һ��ʵ�֡�
���������ʣ�
			  �ٽṹ���ʣ�����һ����ȫ�������Ķ��������п��ܵ��������ڵײ㣬�ײ��ϵ�Ԫ�ش������Ҳ���
			  �ڶ������ʣ���һ�����У�����ÿһ�����X��X�ĸ����еĹؼ���С�ڻ����X�Ĺؼ��֡�����С��Ԫ���ڸ���㴦��
*/

#include "stdafx.h"
#include "binary_heap.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	PriorityQueue h;
	h = Initialize(20);
	cout << "��ʾ����ѣ�";
	ShowHeap(h);
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
	cout << "��ʾ����ѣ�";
	ShowHeap(h);
	Insert(14, h);
	cout << "��ʾ����ѣ�";
	ShowHeap(h);
	cout << "��ն���ѣ�\n";
	MakeEmpty(h);
	cout << "��ʾ����ѣ�";
	ShowHeap(h);
	Insert(13, h);
	Insert(14, h);
	Insert(16, h);
	Insert(19, h);
	Insert(21, h);
	Insert(19, h);
	Insert(68, h);
	Insert(65, h);
	Insert(26, h);
	Insert(32, h);
	Insert(31, h);
	cout << "��ʾ����ѣ�";
	ShowHeap(h);
	cout << "ɾ����С��Ԫ��Ϊ��" << DeleteMin(h) << endl;
	cout << "��ʾ����ѣ�";
	ShowHeap(h);
	cout << "���ٶ���ѣ�";
	Destroy(h);
	getchar();
    return 0;
}

