#pragma once
#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

typedef int ElementType;
typedef int Index;
struct ListNode;
struct HashTbl;
typedef struct ListNode * Position;
typedef Position List;
typedef struct HashTbl * HashTable;


#define MinTableSize 5

struct ListNode   //链表
{
	ElementType Element;
	Position Next;
};

struct HashTbl
{
	int TableSize;
	List * TheLists;//链表数组，即数组元素是链表
};



Index Hash(ElementType X, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);//销毁链表
Position Find(ElementType Key, HashTable H);//key是关键值
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
void MakeEmpty(HashTable H);
int prime(int a);
int NextPrime(int size);
void Delete(ElementType Key, HashTable H);//删除某一个关键值

#endif // !HASH_TABLE_H_
