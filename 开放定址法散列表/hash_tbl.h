#pragma once
#ifndef HASH_TBL_H_
#define HASH_TBL_H_

typedef unsigned int Index;
typedef Index Position;

#define MinTableSize 5

struct HashTbl;
struct HashEntry;
typedef struct HashEntry Cell;
typedef struct HashTbl * HashTable;
typedef int ElementType;
enum KindOfEntry { Legitimate, Empty, Deleted };//分别为有值，空的，已被删除

struct HashEntry
{
	ElementType Element;//散列表某一项的值
	enum KindOfEntry Info;//散列表某一项的状态信息
};

struct HashTbl
{
	int TableSize;
	Cell * TheCells;//在这里不用链表数组，而是使用 散列表项数组
};

Index Hash(ElementType X, HashTable H);
HashTable InitializeTable(int TableSize);
int Prime(int a);
int NextPrime(int tablesize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
HashTable Rehash(HashTable H);
ElementType Retrieve(Position P, HashTable H);


#endif