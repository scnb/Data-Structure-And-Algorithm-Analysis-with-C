#pragma once
#ifndef LEFTHEAP_H_
#define LEFTHEAP_H_

struct TreeNode;
typedef struct TreeNode * PriorityQueue;
typedef int ElementType;

struct TreeNode
{
	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;//该域用来存储该结点的零路径长
};

PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);
void SwapChildren(PriorityQueue H);

#define Insert(X,H) (H=Insert1((X),H))

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

#define DeleteMin(H) cout<<"删除的最小结点值为："<<FindMin(H)<<" ";H=DeleteMin1(H)

ElementType Retrieve(PriorityQueue H);
void PrintElement(ElementType X);
void PrintTree(PriorityQueue H);	

#endif // !LEFTHEAP_H_
