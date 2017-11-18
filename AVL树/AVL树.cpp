// AVL树.cpp : 定义控制台应用程序的入口点。
//一棵AVL树是其每个结点的左子树和右子树的高度最多差1的二叉查找树（注意它还是二叉查找树）
//当插入一个结点后导致该树不满足平衡条件时，需要进行单旋转或者双旋转来重新平衡，这样才算插入操作完成。
//把必须重新平衡的结点叫做α，当树不平衡时，α点的两棵子树的高度差为2
/*单旋转的两种情况：①对α的左儿子的左子树进行一次插入
					②对α的右儿子的右子树进行一次插入
  双旋转的两种情况：①对α的左儿子的右子树进行一次插入
					②对α的右儿子的左子树进行一次插入
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
	/*cout << "树的高度为：" << Height(t) << endl;
	cout << "根结点的值为：" << Retrieve(t) << endl;
	Position tmax = FindMax(t);
	cout << "最大的值为：" << tmax->Element << endl;
	Position tmin = FindMin(t);
	cout << "最小的值为：" << tmin->Element << endl;
	cout << "将树打印出来：" << endl;
	PrintTree(t);
	cout << "根节点的高度：" <<Height(t)<< endl;*/
	getchar();
	return 0;
}