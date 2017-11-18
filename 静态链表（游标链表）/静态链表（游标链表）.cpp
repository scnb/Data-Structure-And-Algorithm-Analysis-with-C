// 静态链表（游标链表）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


const int SpaceSize = 10;

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node
{
	ElementType Element;
	Position Next;
};

struct Node CursorSpace[SpaceSize];


void InitializeCursorSpace(void);


void InitializeCursorSpace(void)
{
	CursorSpace[0].Next = 5;
	CursorSpace[1].Element = 1;
	CursorSpace[1].Next = 2;
	CursorSpace[2].Element = 2;
	CursorSpace[2].Next = 3;
	CursorSpace[3].Element = 3;
	CursorSpace[3].Next = 4;
	CursorSpace[4].Element = 4;
	CursorSpace[4].Next = 1;

	CursorSpace[5].Element = 0;
	CursorSpace[5].Next = 6;
	CursorSpace[6].Element = 0;
	CursorSpace[6].Next = 7;
	CursorSpace[7].Element = 0;
	CursorSpace[7].Next = 8;
	CursorSpace[8].Element = 0;
	CursorSpace[8].Next = 9;
	CursorSpace[9].Element = 0;
	CursorSpace[9].Next = 0;
}


int IsEmpty(List L)
{
	return CursorSpace[L].Element == 0;
}

int IsLast(Position P, List L)
{
	return CursorSpace[P].Next == 0;
}

Position CursorAlloc(void)
{
	Position P;
	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;
	return P;
}

void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = CursorSpace[L].Next;
	while (P && CursorSpace[CursorSpace[P].Next].Element != X)
	{
		P = CursorSpace[P].Next;
	}
	return P;
}

Position Find(ElementType X, List L)
{
	Position P;
	P = CursorSpace[L].Next;
	while (P&&CursorSpace[P].Element != X)
	{
		P = CursorSpace[P].Next;
	}
	return P;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;
		CursorFree(P);
	}
	else
	{
		cout << "Invalid number!\n";
	}
}

void Insert(ElementType X, Position P, List L)
{
	Position TmpCell;
	TmpCell = CursorAlloc();
	if (TmpCell == 0)
	{
		cout << "Error memory!\n";
	}
	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;
}



void DeleteList(List L)
{
	Position P, TmpCell;
	P = CursorSpace[L].Next;
	while (P&&CursorSpace[P].Next != 0)
	{
		TmpCell = P;
		P = CursorSpace[P].Next;
		CursorFree(TmpCell);
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
	P = CursorSpace[L].Next;
	return P;
}

Position Advance(Position P)//返回后一个元素的索引
{
	Position TmpCell;
	TmpCell = CursorSpace[P].Next;
	return TmpCell;
}

ElementType Retrieve(Position P)//返回索引为P处的元素
{
	return CursorSpace[P].Element;
}

void Show(List L)
{
	Position P;
	P = CursorSpace[L].Next;
	while (P&&CursorSpace[P].Next != 0)
	{
		cout << CursorSpace[P].Element << " ";
		P = CursorSpace[P].Next;
	}
}


int main()
{
	InitializeCursorSpace();
	Insert(11, 5, 9);
	Insert(12, 6, 9);
	Insert(13, 7, 9);
	Show(10);
	getchar();
    return 0;
}

