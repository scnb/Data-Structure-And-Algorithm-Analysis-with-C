// Ͱʽ����.cpp : �������̨Ӧ�ó������ڵ㡣
//������ʱ�����������
//ΪʹͰʽ�����ܹ���������������Ҫ��һЩ�������Ϣ�����磺
//����Array��Ԫ��A1��A2��A3����AN������ֻ��С��M����������ɡ�
//���㷨Ϊ��ʹ��һ����СΪM����ΪCount�����飬�䱻��ʼ��Ϊȫ0�����ǣ�Count��M��Ͱ��
//���ζ���ԭ����Array�ĸ���Ԫ�أ�������Aiʱ��Count[Ai]����1��ѭ�����ɨ��Count���飬���±��Ӧ��
//Ԫ�ز�Ϊ0�Ļ���˵��ԭArray�������д�С���ڸ��±��Ԫ�ء�
//��ֽ�ϻ�ͼ��ʾһ���ܹ��������˵�Ū�����

#include "stdafx.h"
#include "bucket_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[9] = { 5,2,3,1,4 ,5,6,3,8};
	cout << "����֮ǰ��";
	Show(arr, 9);
	cout << "����֮��";
	BucketSort(arr, 9, 10);
	Show(arr, 9);
	getchar();
    return 0;
}

