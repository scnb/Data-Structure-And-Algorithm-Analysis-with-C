#pragma once
#ifndef CURSOR_H_
#define CURSOR_H_



int IsEmpty(List L);
int IsLast(Position P, List L);
Position CursorAlloc(void);//����һ���µĿռ�
void CursorFree(Position P);//ɾ��һ���ռ�
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


#endif // !CURSOR_H_
