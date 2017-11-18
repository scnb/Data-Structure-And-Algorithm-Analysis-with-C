#include "stdafx.h"
#include "heap_sort.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if (MaxElements < MinPQSize)
	{
		cout << "元素个数太少，无法生成二叉堆！\n";
		cout << "请重新输入：";
		cin >> MaxElements;
	}
	H = new struct HeapStruct;
	if (H == NULL)
	{
		cout << "内存分配失败！\n";
		getchar();
		exit(-1);
	}
	H->Elements = (ElementType*)malloc(sizeof(ElementType)*(MaxElements + 1));//大小+1是为了在数组头部存储一个Seninel（标记），用来在插入操作时进行比较
	if (H->Elements == NULL)
	{
		cout << "内存分配失败！\n";
		getchar();
		exit(-1);
	}
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;
	return H;
}

void Destroy(PriorityQueue H)
{
	delete H->Elements;
	delete H;
	cout << "二叉堆已被销毁！" << endl;
}

void MakeEmpty(PriorityQueue H)
{
	for (int i = 0;i <= H->Size;i++)
	{
		H->Elements[i] = 0;
	}
	H->Size = 0;
}

void Insert(ElementType X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		cout << "二叉堆已满！\n";
		return;
	}
	for (i = ++H->Size;H->Elements[i / 2] > X;i /= 2)//i从下一个空闲元素开始，判断条件是父节点(i/2)比要插入的元素大
	{
		H->Elements[i] = H->Elements[i / 2];//如果父节点比要插入的元素大，则把父节点往子节点移动
	}
	H->Elements[i] = X;
}

/*
删除最小元素的函数，①取得二叉堆中最小的元素很简单，因为它就在根结点处，也就是数组的第二个元素
②困难的是，删除根节点后，必须把后面的元素向上移动到合适的位置，继续满足二
叉堆的堆序性质
③在删除根节点后，最后一个结点的位置也必须也要变化，因为在它的前面因为其他
元素的上升产生了空穴，所以需要最后一个结点去填充
*/

ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;
	if (IsEmpty(H))
	{
		cout << "二叉堆为空！无法删除！\n";
		return H->Elements[0];
	}
	MinElement = H->Elements[1];//取得真正的二叉堆的最小值
	LastElement = H->Elements[H->Size--];//取得二叉堆的最后一个元素

	for (i = 1;i * 2 <= H->Size;i = Child)//在每一次循环中，i是父节点的索引，Child是左孩子的索引
	{
		Child = i * 2;					 //父节点索引乘以2就是左孩子的索引
										 /*进行判断，①左孩子没有到数组有效元素末端
										 ②比较左孩子和右孩子谁更小，更小的上移到父节点的空穴*/
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
		{
			Child++;//如果右孩子更小，则Child自增1，成为右孩子的索引
		}
		if (LastElement > H->Elements[Child])//如果数组的最后一个元素大于当前子树的元素
		{
			H->Elements[i] = H->Elements[Child];
		}
		else
		{
			break;
		}
	}
	H->Elements[i] = LastElement;//最后把原来的最后一个元素存入合适的位置
	return MinElement;
}

ElementType FindMin(PriorityQueue H)
{
	return H->Elements[1];
}

int IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
	return H->Size == H->Capacity;
}

void ShowHeap(PriorityQueue H)
{
	for (int i = 1;i <= H->Size;i++)
	{
		cout << H->Elements[i] << " ";
	}
	cout << endl;
}
