#pragma once
#ifndef LIST_H_
#define LIST_H_

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode ListNode;
typedef PtrToNode Position;
typedef int ElementType;

struct Node
{
	ElementType Element;
	Position Next;
};

List CreateList();
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P,List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, Position P, List L);
Position FindPrevious(ElementType X, List L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void Show(List L);


#endif // !LIST_H)