// AVL��.cpp : �������̨Ӧ�ó������ڵ㡣
//һ��AVL������ÿ���������������������ĸ߶�����1�Ķ����������ע�������Ƕ����������
//������һ�������¸���������ƽ������ʱ����Ҫ���е���ת����˫��ת������ƽ�⣬����������������ɡ�
//�ѱ�������ƽ��Ľ���������������ƽ��ʱ����������������ĸ߶Ȳ�Ϊ2
/*����ת������������ٶԦ�������ӵ�����������һ�β���
					�ڶԦ����Ҷ��ӵ�����������һ�β���
  ˫��ת������������ٶԦ�������ӵ�����������һ�β���
					�ڶԦ����Ҷ��ӵ�����������һ�β���
*/


#include "stdafx.h"
#include "avl_tree.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	AvlTree t = new struct AvlNode;
	t = NULL;
	t = Insert(10, t);
	t = Insert(5, t);
	t = Insert(4, t);
	t = Insert(8, t);
	t = Insert(12, t);
	t = Insert(7, t);
	t = Insert(24, t);
	bool res = isBalanced(t);
	cout << res << endl;
	/*cout << "���ĸ߶�Ϊ��" << Height(t) << endl;
	cout << "������ֵΪ��" << Retrieve(t) << endl;
	Position tmax = FindMax(t);
	cout << "����ֵΪ��" << tmax->Element << endl;
	Position tmin = FindMin(t);
	cout << "��С��ֵΪ��" << tmin->Element << endl;
	cout << "������ӡ������" << endl;
	PrintTree(t);
	cout << "���ڵ�ĸ߶ȣ�" <<Height(t)<< endl;*/
	getchar();
	return 0;
}