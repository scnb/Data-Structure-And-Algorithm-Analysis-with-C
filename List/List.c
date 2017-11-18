// List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "list.h"

int main()
{
	int i = 0;
	List li = CreateList();
	Position P = Header(li);
	Show(li);
	for (i = 1;i < 5;i++)
	{
		Insert(i, P, li);
		P = Advance(P);
	}
	Insert(3, P, li);
	P = Advance(P);
	Insert(4, P, li);
	P = Advance(P);
	Insert(3, P, li);
	P = Advance(P);
	Insert(7, P, li);
	P = Advance(P);
	Show(li);
	printf("\n");
	Delete(5, li);
	Delete(3, li);
	Delete(1, li);
	Show(li);
	getchar();
    return 0;
}

