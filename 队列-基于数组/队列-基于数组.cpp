// ����-��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "queue.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Queue Q = CreateQueue(7);
	Show(Q);
	Enqueue(1, Q);
	Enqueue(2, Q);
	Enqueue(3, Q);
	Show(Q);
	Enqueue(4, Q);
	Enqueue(5, Q);
	Enqueue(6, Q);
	Enqueue(7, Q);
	Enqueue(8, Q);
	Enqueue(9, Q);
	Enqueue(10, Q);
	Enqueue(11, Q);
	Show(Q);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	Show(Q);
	Dequeue(Q);
	Dequeue(Q);
	Show(Q);
	cout<<"���ӵ�Ԫ��Ϊ��"<<FrontAndDequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	getchar();
    return 0;
}

