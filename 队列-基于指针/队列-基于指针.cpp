// ����-��������.cpp : �������̨Ӧ�ó������ڵ㡣
//��������Ķ��о��Ƕ�̬���У�����ÿһ�����������ɵĴ�����ɾ���������������Ǹ���̬����һ��������Ҫ��ѭ�����вſ���
//���Ҷ�̬����ֻ�пգ�û����
//ͨ����Enqueue��������Ӿ�̬����i��ʹ��front�ܹ�������ָ����ʼԪ��

#include "stdafx.h"
#include "queue.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Queue Q = CreateQueue();
	Show(Q);
	Enqueue(1, Q);
	Enqueue(2, Q);
	Enqueue(3, Q);
	Show(Q);
	Enqueue(4, Q);
	Enqueue(5, Q);
	Show(Q);
	cout << "���ӵ�Ԫ��Ϊ��" << FrontAndDequeue(Q) << endl;
	cout << "���ӵ�Ԫ��Ϊ��" << FrontAndDequeue(Q) << endl;
	cout << "���ӵ�Ԫ��Ϊ��" << FrontAndDequeue(Q) << endl;
	cout << "���ӵ�Ԫ��Ϊ��" << FrontAndDequeue(Q) << endl;
	cout << "���ӵ�Ԫ��Ϊ��" << FrontAndDequeue(Q) << endl;
	cout << "���ӵ�Ԫ��Ϊ��" << FrontAndDequeue(Q) << endl;
	cout << "���ӵ�Ԫ��Ϊ��" << FrontAndDequeue(Q) << endl;
	getchar();
	return 0;
}



