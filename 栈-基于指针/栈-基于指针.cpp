// 栈-基于指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stack.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node;

typedef int ElementType;
typedef struct Node * PtrToNode;
typedef PtrToNode Stack;

struct Node
{
	ElementType Element;
	PtrToNode Next;
};





int IsEmpty(Stack S)
{
	return S->Next == 0;
}

Stack CreateStack(void)
{
	Stack ptr = new (struct Node);
	if (ptr == NULL)
	{
		cout << "Failure!\n";
		exit(-1);
	}
	ptr->Next = NULL;
	return ptr;
}

void DiposeStack(Stack S)
{
	Stack top, tmp;
	top = S;
	tmp = S;
	while (top != NULL)
	{
		delete top;
		tmp = tmp->Next;
		top = tmp;
	}
	delete tmp;
}

void Pop(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Error! Empty Stack!\n";
	}
	else
	{
		PtrToNode tmp = S->Next;
		S->Next = S->Next->Next;
		delete tmp;
	}
}

void MakeEmpty(Stack S)
{
	if (S == NULL)
	{
		cout << "Must use CreateStack first!\n";
		exit(-1);
	}
	else
	{
		while (!IsEmpty(S))
		{
			Pop(S);
		}
	}
}

void Push(ElementType X, Stack S)
{
	PtrToNode ptr = new (struct Node);
	if (ptr == NULL)
	{
		cout << "Error!\n";
		exit(-1);
	}
	ptr->Next = S->Next;
	ptr->Element = X;
	S->Next = ptr;
}

ElementType Top(Stack S)//返回顶部元素
{
	if (!IsEmpty(S))
	{
		return S->Element;
	}
	else
	{
		cout << "Error! Empty Stack!\n";
		return 0;
	}
}



void Show(Stack S)
{
	while (S->Next != NULL)
	{
		cout << S->Next->Element << " ";
		S = S->Next;
	}
	cout << endl;
}



int main()
{
	Stack s = CreateStack();
	Push(1, s);
	Push(2, s);
	Push(3, s);
	Push(4, s);
	Push(5, s);
	Push(6, s);
	Show(s);
	Pop(s);
	Show(s);
	Pop(s);
	Show(s);
	Pop(s);
	Show(s);
	Pop(s);
	Show(s);
	Pop(s);
	Show(s);
	getchar();
    return 0;
}

