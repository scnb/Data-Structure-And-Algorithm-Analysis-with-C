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

struct ListNode   //����
{
	ElementType Element;
	Position Next;
};

struct HashTbl
{
	int TableSize;
	List * TheLists;//�������飬������Ԫ��������
};



Index Hash(ElementType X, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);//��������
Position Find(ElementType Key, HashTable H);//key�ǹؼ�ֵ
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
void MakeEmpty(HashTable H);
int prime(int a);
int NextPrime(int size);
void Delete(ElementType Key, HashTable H);//ɾ��ĳһ���ؼ�ֵ

#endif // !HASH_TABLE_H_
