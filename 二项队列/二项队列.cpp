// 二项队列.cpp : 定义控制台应用程序的入口点。
/*
	二项队列：堆序树的集合（或者说是二项树的集合），称为森林。堆序树中的每一棵都是有约束的形式，叫做二项树。
	每一个高度上至多存在一棵二项树。
	高度为0的二项树是一棵单结点树；高度为k的二项树Bk通过将一棵二项树Bk-1附接到另一棵二项树Bk-1的根上而构成。
	二项树Bk由一个带有儿子B0、B1、……Bk-1的根组成。
	高度为k的二项树恰好有2^k个结点。
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

