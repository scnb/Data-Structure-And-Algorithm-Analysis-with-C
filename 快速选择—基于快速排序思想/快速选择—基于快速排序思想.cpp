// ����ѡ�񡪻��ڿ�������˼��.cpp : �������̨Ӧ�ó������ڵ㡣
//���ڿ��������˼�룬��һ�����������ŦԪ���зָ���kС�ڵ�����������Ԫ�ظ�����
//���k����СԪһ�������������У���������Ұ�ߵ������С�Ȼ����еݹ���á�
//���㷨��ֹ��ʱ�򣬵�k��Ԫ�ؾ�������ĵ�k��λ���ϣ���Ȼ��Ӧ�������±���k-1��

#include "stdafx.h"
#include "quick_select.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	ElementType arr[10] = { 8,1,4,9,0,3,5,2,7,6 };
	cout << "����֮ǰ��";
	Show(arr, 10);
	cout << "����֮��";
	cout << "��4����СԪΪ��";
	QuickSelect(arr, 4, 10);
	cout<<arr[3]<<endl;
	Show(arr, 10);
	getchar();
    return 0;
}

