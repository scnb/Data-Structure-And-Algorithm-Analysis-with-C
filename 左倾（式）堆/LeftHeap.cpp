#include "stdafx.h"
#include "LeftHeap.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

PriorityQueue Initialize(void)//初始化的时候不用做其他的工作，返回一个空指针就可以，这样可以方便的创建根节点
{
	/*PriorityQueue H;
	H = new struct TreeNode;
	if (H == NULL)
	{
		cout << "内存分配失败！\n";
		getchar();
		exit(-1);
	}
	H->Element = 0;
	H->Left = H->Right = NULL;
	H->Npl = 0;
	return H;*/
	return NULL;
}

ElementType FindMin(PriorityQueue H)
{
	if (!IsEmpty(H))
	{
		return H->Element;//左倾堆有二叉堆的堆序性，即根节点为最小值
	}
	return 0;
}

int IsEmpty(PriorityQueue H)
{
	return H == NULL;
}

/*该Merge函数为合并驱动函数，用来预先处理一些特殊情况：①H1为空
													   ②H2为空
  然后根据H1和H2谁的根节点更小，来决定调用Merge1函数的参数的顺序
*/

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
	{
		return H2;
	}
	if (H2 == NULL)
	{
		return H1;
	}
	if (H1->Element < H2->Element)//判断谁的根节点值更小，把该堆放在第一个参数
	{
		Merge1(H1, H2);
	}
	else
	{
		Merge1(H2, H1);
	}
}

void SwapChildren(PriorityQueue H)
{
	PriorityQueue temp;
	temp = H->Left;
	H->Left = H->Right;
	H->Right = temp;
}

/*调用Merge1函数来使H1的右子树和H2进行合并*/

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
	if (H1->Left == NULL)
	{
		H1->Left = H2;//如果H1的左子树为空，则直接把H2放在H1的左子树
	}
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
		{
			SwapChildren(H1);
		}
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

/*把插入一个数看作把一个只有一个结点的堆和堆H合并*/

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
	PriorityQueue SingleNode;
	SingleNode = new struct TreeNode;
	if (SingleNode == NULL)
	{
		cout << "内存分配失败！\n";
		getchar();
		exit(-1);
	}
	else
	{
		SingleNode->Element = X;
		SingleNode->Npl = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}
	return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
	PriorityQueue LeftHeap, RightHeap;
	if (IsEmpty(H))
	{
		cout << "该左倾树为空！\n";
		return H;
	}
	else
	{
		LeftHeap = H->Left;
		RightHeap = H->Right;
		delete H;
		return Merge(LeftHeap, RightHeap);
	}
}

ElementType Retrieve(PriorityQueue H)
{
	return H->Element;
}

void PrintElement(ElementType X)
{
	cout << X << " ";
}

void PrintTree(PriorityQueue H)
{
	if (H != NULL)
	{
		PrintTree(H->Left);
		PrintElement(H->Element);
		PrintTree(H->Right);
	}
}