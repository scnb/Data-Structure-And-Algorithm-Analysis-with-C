#include "stdafx.h"
#include "avl_tree.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;

int Height(Position P)//P结点处的高度
{
	if (P == NULL)
	{
		return -1;//根结点处的高度为-1
	}
	else
	{
		return P->Height;
	}
}

AvlTree MakeEmpty(AvlTree T)
{
	if (T == NULL)
	{
		return T;
	}
	else
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
	}
}

Position Find(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		cout << "没有找到该元素！\n";
	}
	else if (X < T->Element)
	{
		Find(X, T->Left);
	}
	else if (X > T->Element)
	{
		Find(X, T->Right);
	}                        //省略了X==T->Element的情况，因为那种情况也是直接返回T的值
	return T;
}

Position FindMin(AvlTree T)
{
	/*if (T == NULL)
	{
		cout << "空树！\n";
	}
	AvlTree temp = T;
	while (temp->Left != NULL)
	{
		temp = temp->Left;
	}
	return temp;*/

	//递归的方法
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Left == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
}

Position FindMax(AvlTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Right == NULL)
	{
		return T;
	}
	else
	{
		return FindMax(T->Right);
	}
}

static Position SingleRotateWithLeft(Position K2)//①对α的左儿子的左子树进行一次插入  实际上是右旋
{
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;//左子树和右子树的高度取最大值，再加1？因为还要加上K2
	K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
	return K1;//返回新的“根”结点，即代替原来K2的结点
}

static Position SingleRotateWithRight(Position K2)//②对α的右儿子的右子树进行一次插入   实际上是左旋
{
	Position K1;
	K1=K2->Right;         //原来这三行关键的代码是错误的，一定要画图来进行写程序，把实际的变化画出来
	K2->Right=K1->Left;
	K1->Left=K2;
	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
	return K1;//返回新的“根”节点，即代替原来K2的结点
}
	

static Position DoubleRotateWithLeft(Position K3)//①对α的左儿子的右子树进行一次插入  先左旋，后右旋
{
	//先在K1和K2之间进行旋转
	K3->Left = SingleRotateWithRight(K3->Left);
	//再在K2和K3之间进行旋转
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K4)//①对α的右儿子的左子树进行一次插入  先右旋，后左旋
{
	K4->Right = SingleRotateWithLeft(K4->Right);
	return SingleRotateWithRight(K4);
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		//创建并返回一个只有一个结点的树S
		T = new struct AvlNode;
		if (T == NULL)
		{
			cout << "内存分配失败！\n";
			exit(-1);
		}
		else
		{
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)//构成不平衡的条件
		{
			if (X < T->Left->Element) //插入的结点的值比左孩子的值小，就单旋转
			{
				T = SingleRotateWithLeft(T);
			}
			else
			{
				T = DoubleRotateWithLeft(T);
			}
		}
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->Element)
			{
				T = SingleRotateWithRight(T);
			}
			else
			{
				T = DoubleRotateWithRight(T);
			}
		}
	}
	//如果X已经在树里边了，则什么都不做
	T->Height = max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int maxDepth(AvlTree  root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->Left);//第一次调用maxDepth后，进入这一句进行递归，直到root==NULL
	int rightDepth = maxDepth(root->Right);//在上面的最底层递归后，进入这一句进行递归，直到root==NULL
	if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth)>1)
	{
		return -1;//为什么会返回-1呢？
	}
	return max(leftDepth, rightDepth) + 1;
}

bool isBalanced(AvlTree root) 
{
	// write your code here
	return (-1 != (maxDepth(root)));
}

AvlTree Delete(ElementType X, AvlTree T)
{
	Position TmpCell;
	if (T == NULL)
	{
		cout << "没有找到该值！\n";
	}
	else if (X < T->Element)
	{
		T->Left = Delete(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Delete(X, T->Right);
	}
	else if (T->Left&&T->Right)//两个孩子  用右子树的最小的数据的结点代替该结点的数据并递归地删除该结点
	{
		//用右子树的最小的结点来代替该结点
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);//递归的删除该结点
	}
	else if (X == T->Element)//0个或1个孩子 将该结点的孩子给其父节点
	{
		TmpCell = T;
		if (T->Left == NULL)
		{
			T = T->Right;
		}
		else if (T->Right == NULL)
		{
			T = T->Left;
		}
		delete TmpCell;
	}
	return T;
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

void PrintElement(ElementType X)
{
	cout << X << " ";
}

void PrintTree(Position P)
{
	if (P != NULL)
	{
		PrintTree(P->Left);
		PrintElement(P->Element);
		PrintTree(P->Right);
	}
}
