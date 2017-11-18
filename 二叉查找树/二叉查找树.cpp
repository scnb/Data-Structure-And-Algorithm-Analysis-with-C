// 二叉查找树.cpp : 定义控制台应用程序的入口点。
//二叉查找树又叫二叉搜索树，它是一种特殊的二叉树，其特性为：对于树中的每个结点X，它的左子树中所有关键
//值小于X的关键字值，而它的右子树中所有关键字值大于X的关键字值字


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
	cout << "打印克隆前的树：\n";
	PrintTree(t);
	cout << endl;
	TreeNode * pos = new TreeNode;
	pos = cloneTree(t);
	cout << "打印克隆后的树：\n";
	PrintTree(pos);

	/*Position tmax = FindMax(t);
	cout << "最大值为：" << tmax->Element << endl;
	Position tmin = FindMin(t);
	cout << "最小值为：" << tmin->Element << endl;
	cout << "根结点的值为：" << Retrieve(t) << endl;
	cout << "将树打印出来：" << endl;
	cout << "树根的高度为：" << Height(t)<<endl;
	PrintTree(t);*/
	getchar();
    return 0;
}

