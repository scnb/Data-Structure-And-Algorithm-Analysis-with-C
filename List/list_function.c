#include "stdafx.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



List CreateList()
{
	List L = malloc(sizeof(struct Node));
	if (L == NULL)
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	L->Element = 0;
	L->Next = NULL;
	return L;
}

List MakeEmpty(List L)//初始化链表
{
	if (L != NULL)
	{
		DeleteList(L);
	}
	L = malloc(sizeof(struct Node));
	if (L == NULL)
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	L->Next = NULL;
	return L;
}

List removeElements(List head, int val)
{
	// Write your code here
	if (head == NULL)
	{
		return NULL;
	}
	while (head != NULL && head->Element == val)
	{
		head = head->Next;
	}
	/*上面两项排除特殊情况*/
	List p = head;
	while (p != NULL)
	{
		while (p->Next != NULL && p->Next->Element == val)
		{
			List  temp = malloc(sizeof(struct Node));
			temp = p->Next;
			p->Next = temp->Next;
			free(temp);
		}
		p = p->Next;
	}
	return head;
}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)//判断P位置的元素是不是最后一个元素
{
	return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;
}

void Delete(ElementType X, List L)
{
	Position P,TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))//当P不是尾指针时，说明找到了该元素
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
		TmpCell = NULL;
	}
}

void Insert(ElementType X, Position P, List L)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	return P;
}

void DeleteList(List L)
{
	Position TmpCell;
	TmpCell = L;
	while (TmpCell != NULL)
	{
		TmpCell = TmpCell->Next;
		free(TmpCell);
	}
}

Position Header(List L)
{
	Position P;
	P = L;
	return P;
}

Position First(List L)
{
	Position P;
	P = L->Next;
	return P;
}

Position Advance(Position P)//获取位置P的下一个位置
{
	return P->Next;
}

ElementType Retrieve(Position P)//取得该处的元素
{
	return P->Element;
}

void Show(List L)
{
	Position P = Header(L);
	if (P->Next == NULL)
	{
		printf("链表为空！\n");
	}
	while (P->Next!= NULL)
	{
		P = P->Next;
		printf("%d ", Retrieve(P));
		
	}
}


