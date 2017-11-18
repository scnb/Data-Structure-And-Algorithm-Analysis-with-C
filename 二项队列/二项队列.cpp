// �������.cpp : �������̨Ӧ�ó������ڵ㡣
/*
	������У��������ļ��ϣ�����˵�Ƕ������ļ��ϣ�����Ϊɭ�֡��������е�ÿһ�ö�����Լ������ʽ��������������
	ÿһ���߶����������һ�ö�������
	�߶�Ϊ0�Ķ�������һ�õ���������߶�Ϊk�Ķ�����Bkͨ����һ�ö�����Bk-1���ӵ���һ�ö�����Bk-1�ĸ��϶����ɡ�
	������Bk��һ�����ж���B0��B1������Bk-1�ĸ���ɡ�
	�߶�Ϊk�Ķ�����ǡ����2^k����㡣
*/

#include "stdafx.h"
#include <iostream>
#include "binomial_tree.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	BinQueue H1;
	BinQueue H2;
	H1 = Initialize();
	H2 = Initialize();
	BinTree t;
	t->Element = 1;
	t->LeftChild = t->NextSibling = NULL;
	H2->TheTrees[0] = t;
	Merge(H1, H2);
	getchar();
    return 0;
}

