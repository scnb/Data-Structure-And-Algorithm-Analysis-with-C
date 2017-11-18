#include "stdafx.h"
#include "binomial_tree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

BinQueue Initialize(void)
{
	BinQueue H;
	int i;
	H = new struct Collection;
	if (H == NULL)
	{
		cout << "内存分配失败！\n";
		getchar();
		exit(-1);
	}
	H->CurrentSize = 0;
	for (i = 0;i < MaxTrees;i++)
	{
		H->TheTrees[i] = new struct BinNode;
		if (H->TheTrees[i] == NULL)
		{
			cout << "内存分配失败！\n";
			getchar();
			exit(-1);
		}
		H->TheTrees[i]->LeftChild = H->TheTrees[i]->NextSibling = NULL;
	}
	return H;
}

int IsEmpty(BinQueue H)
{
	return H->CurrentSize == 0;
}

void DestroyQueue(BinQueue H)
{
	for (int i = 0;i < MaxTrees;i++)
	{
		delete H->TheTrees[i];
	}
	delete H;
}

void MakeEmpty(BinQueue H)
{
	BinNode temp;
	for (int i = 0;i < H->CurrentSize;i++)
	{
		temp = H->TheTrees[i];
		H->TheTrees[i] = NULL;
		delete temp;
	}
	H->CurrentSize = 0;
}

BinTree CombineTrees(BinTree T1, BinTree T2)
{
	if (T1->Element > T2->Element)
	{
		return CombineTrees(T2, T1);
	}
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
}

BinQueue Merge(BinQueue H1, BinQueue H2)
{
	BinTree T1, T2, Carry = NULL;
	int i, j;
	if (H1->CurrentSize + H2->CurrentSize > Capacity)
	{
		cout << "合并操作会超出大小范围！\n";
		return;
	}
	H1->CurrentSize += H2->CurrentSize;
	for (i = 0, j = 1;j <= H1->CurrentSize;i++, j *= 2)
	{
		T1 = H1->TheTrees[i];
		T2 = H2->TheTrees[j];
		switch (!!T1 + 2 * !!T2 + 4 * !!Carry)
		{
		case 0:/*没有树*/
		case 1:/*只有树H1*/
			break;
		case 2:/*只有树H2*/
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		case 3:/*树H1和树H2*/
			Carry = CombineTrees(T1, T2);
			H1->TheTrees[i] = H2->TheTrees[i] = NULL;
			break;
		case 4:/*只有树Carry*/
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		case 5:/*树H1和树Carry*/
			Carry = CombineTrees(T1, Carry);
			H1->TheTrees[i] = NULL;
			break;
		case 6:/*树H2和树Carry*/
			Carry = CombineTrees(T2, Carry);
			H2->TheTrees[i] = NULL;
			break;
		case 7:/*所有的树*/
			H1->TheTrees[i] = Carry;
			Carry = CombineTrees(T1, T2);
			H2->TheTrees[i] = NULL;
			break;
		}
	}
	return H1;
}

ElementType DeleteMin(BinQueue H)
{
	int i, j;
	int MinTree;//存储二项队列中最小根节点的位置
	BinQueue DeletedQueue;
	Position DeletedTree, OldRoot;//分别用来保存最小根节点，和用来临时存储最小根节点
	ElementType MinItem;//保存最小根节点的值
	if (IsEmpty(H))
	{
		cout << "二项队列为空！\n";
		return -INFINITY;
	}
	MinItem = INFINITY;
	/*寻找最小根节点*/
	for (i = 0;i < MaxTrees;i++)
	{
		if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)//如果该结点不为空，并且该结点的值小于当前的最小值
		{
			/*更新最小根节点*/
			MinItem = H->TheTrees[i]->Element;
			MinTree = i;
		}
	}
	DeletedTree = H->TheTrees[i];//获得最小根结点的树
	OldRoot = DeletedTree;//把最小根节点保存在临时结点中
	DeletedTree = DeletedTree->LeftChild;//抛弃根节点，把根节点的子树存储在DeletedTree中
	delete OldRoot;//把最小根节点删除
	DeletedQueue = Initialize();//初始化一个临时二项队列来存储原来根节点删除后产生的几个子树
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;//MinTree是最小根结点在队列中的位置，把该根结点删除后，将会产生2^MinTree-1个树
	/*把最小根节点的树拆开   然后组合成一个二项队列*/
	for (j = MinTree - 1;j >= 0;j--)
	{
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}
	H->TheTrees[MinTree] = NULL;//把原来二项队列中的最小根结点置0
	H->CurrentSize = H->CurrentSize - DeletedQueue->CurrentSize + 1;
	Merge(H, DeletedQueue);//合并原来的队列和现在的临时队列
	return MinItem;//返回最小值
}
