// ���㣨ʽ����.cpp : �������̨Ӧ�ó������ڵ㡣
//��ʽ��ͬ�����Ķ�һ����Ҳ���нṹ���Ժ������ԡ�
//��ʵ�ϣ���ʽ��Ҳ�Ƕ������������Ͷ�����Ψһ�������ǣ���ʽ�Ѳ�������ƽ��ģ�ʵ���������ڷǳ���ƽ��ģ�������Ϳ�����⣩��
//��·������Npl(X))����һ���X��һ��û���������ӵĽ������·���ĳ��ȡ�����0����1�����ӵĽ�����·����Ϊ0����Npl(NULL)=-1;
//��·���������ڽ���ڣ��ṹ���е�һ���򣩣�����һ·������·��������������ӽ�����·��������Сֵ��1.
//��ʽ�����ʣ����ڶ��е�ÿһ����㣬����ӵ���·�����������Ҷ��ӵ���·����һ����


#include "stdafx.h"
#include "LeftHeap.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	PriorityQueue H1;
	PriorityQueue H2;
	H1 = Initialize();
	H2 = Initialize();
	cout << "��ӡ�����H1��";
	PrintTree(H1);
	cout << endl;
	cout << "��ӡ�����H2��";
	PrintTree(H2);
	cout << endl;
	//���H1
	Insert(3, H1);
	Insert(10, H1);
	Insert(8, H1);
	Insert(21, H1);
	Insert(14, H1);
	Insert(17, H1);
	Insert(23, H1);
	Insert(26, H1);
	//���H2
	Insert(6, H2);
	Insert(12, H2);
	Insert(7, H2);
	Insert(18, H2);
	Insert(24, H2);
	Insert(37, H2);
	Insert(19, H2);
	Insert(33, H2);
	cout << "��ӡ�����H1��";
	PrintTree(H1);
	cout << endl;
	cout << "��ӡ�����H2��";
	PrintTree(H2);
	cout << endl;
	cout << "�ϲ�H1��H2������ӡ��";
	PriorityQueue merge;
	merge = Merge(H1, H2);
	PrintTree(merge);
	cout << endl;
	DeleteMin(merge);
	PrintTree(merge);
	getchar();
    return 0;
}

