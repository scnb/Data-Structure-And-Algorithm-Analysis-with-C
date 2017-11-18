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
enum KindOfEntry { Legitimate, Empty, Deleted };//�ֱ�Ϊ��ֵ���յģ��ѱ�ɾ��

struct HashEntry
{
	ElementType Element;//ɢ�б�ĳһ���ֵ
	enum KindOfEntry Info;//ɢ�б�ĳһ���״̬��Ϣ
};

struct HashTbl
{
	int TableSize;
	Cell * TheCells;//�����ﲻ���������飬����ʹ�� ɢ�б�������
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