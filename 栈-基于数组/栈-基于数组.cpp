// 栈-基于数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using std::endl;
using std::cout;
using std::cin;

struct StackRecord;
typedef struct StackRecord * Stack;
typedef int ElementType;

struct StackRecord
{
	int Capacity;//栈中最大元素个数
	int TopOfStack;//栈顶元素索引
	ElementType * Array;//指针数组
};

#define EmptyTOS -1
#define MinStackSize 5

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

Stack CreateStack(int MaxElements)
{
	if (MaxElements < MinStackSize)
	{
		cout << "Stack size is too small!\n";
	}
	Stack S = new struct StackRecord;
	if (S == NULL)
	{
		cout << "Error！No memory!\n";
	}
	S->Array = (ElementType *)malloc(sizeof(ElementType)*MaxElements);
	if (S->Array == NULL)
	{
		cout << "Error! Bad memory!\n";
	}
	S->Capacity = MaxElements;
	MakeEmpty(S);
	return S;
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity-1;
}

void DisposeStack(Stack S)//销毁栈
{
	if (S != NULL)
	{
		free(S->Array);
		delete S;
	}
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
	{
		cout << "Full Stack!\n";
	}
	else
	{
		S->Array[++S->TopOfStack] = X;
	}
}

void Pop(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty Stack!\n";
	}
	else
	{
		S->TopOfStack--;
	}
}

ElementType Top(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty Stack!\n";
		return 0;
	}
	else
	{
		return S->Array[S->TopOfStack];
	}
}

ElementType TopAndPop(Stack S)
{

	ElementType tmp;
	if (IsEmpty(S))
	{
		cout << "Empty Stack!\n";
		return 0;
	}
	else
	{
		return S->Array[S->TopOfStack--];
	}
}

void Show(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty Stack!\n";
	}
	else
	{
		for (int i = S->TopOfStack;i > EmptyTOS;i--)
		{
			cout << S->Array[i] << " ";
		}
	}
	cout << endl;
}

int main()
{
	Stack s = CreateStack(7);
	Push(1, s);
	Push(2, s);
	Push(3, s);
	Push(4, s);
	Push(5, s);
	Push(6, s);
	Push(7, s);
	Push(8, s);
	Show(s);
	//Pop(s);
	//Pop(s);
	//Pop(s);
	//Pop(s);
	//Pop(s);
	for (int i = 0;i < 4;i++)
	{
		cout << "弹出的元素为" << TopAndPop(s) << endl;
	}
	Show(s);
	MakeEmpty(s);//使成为空栈
	Show(s);
	DisposeStack(s);//销毁之后就无法显示了
	Show(s);
	getchar();
    return 0;
}

