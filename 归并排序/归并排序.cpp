// �鲢����.cpp : �������̨Ӧ�ó������ڵ㡣
//�鲢���򣬹���˼��,���ǰ�һ�����飬�ֳ������֣�ÿһ���ֱַ�����Ȼ������Merge()�����ϲ�����
//���У����������õ��˵ݹ��˼�룬��һ�����飬�ֳ�������֮��ÿһ���ֻ������ٷֳ������֡�
//���һֱ�ֵ�ֻʣ������Ԫ�أ�Ȼ����бȽϣ��ٻ��ݡ�
//���У����漰����������ָ�롱��Lpos��Rpos��Tempos������ʵ�������������������ָʾÿ�������鵱ǰ��Ԫ��

#include "stdafx.h"
#include "merge_sort.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[8] = { 1,13,24,26,2,15,27,38 };
	cout << "����֮ǰ��";
	Show(arr, 8);
	MergeSort(arr, 8);
	cout << "����֮��";
	Show(arr, 8);
	getchar();
    return 0;
}

