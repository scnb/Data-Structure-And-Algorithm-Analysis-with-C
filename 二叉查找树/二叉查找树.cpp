// ���������.cpp : �������̨Ӧ�ó������ڵ㡣
//����������ֽж���������������һ������Ķ�������������Ϊ���������е�ÿ�����X�����������������йؼ�
//ֵС��X�Ĺؼ���ֵ�������������������йؼ���ֵ����X�Ĺؼ���ֵ��


#include "stdafx.h"
#include "tree.h"
#include <iostream>
#include <vector>

using std::vector;

using std::cout;
using std::cin;
using std::endl;


int main()
{
	SearchTree t = new struct TreeNode;
	t = NULL;
	t = Insert(4, t);
	t = Insert(3, t);
	t = Insert(6, t);
	t = Insert(8, t); 
	t = Insert(1, t);
	t = Insert(2, t);
	t = Insert(9, t);
	cout << "��ӡ��¡ǰ������\n";
	PrintTree(t);
	cout << endl;
	TreeNode * pos = new TreeNode;
	pos = cloneTree(t);
	cout << "��ӡ��¡�������\n";
	PrintTree(pos);

	/*Position tmax = FindMax(t);
	cout << "���ֵΪ��" << tmax->Element << endl;
	Position tmin = FindMin(t);
	cout << "��СֵΪ��" << tmin->Element << endl;
	cout << "������ֵΪ��" << Retrieve(t) << endl;
	cout << "������ӡ������" << endl;
	cout << "�����ĸ߶�Ϊ��" << Height(t)<<endl;
	PrintTree(t);*/
	getchar();
    return 0;
}

