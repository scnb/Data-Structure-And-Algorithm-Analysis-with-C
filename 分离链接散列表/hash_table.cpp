#include "stdafx.h"
#include "hash_table.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Index Hash(ElementType X, int TableSize)
{
	return X%TableSize;
}

int prime(int a)
{
	for (int i = 2;i < a;i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int NextPrime(int size)//返回与size大小最接近的素数
{
	for (int i = size;i <= size * 2;i++)
	{
		if (prime(i))
		{
			return i;
		}
	}
}

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if (TableSize < MinTableSize)
	{
		cout << "哈希表太小了！\n";
		return NULL;
	}
	//分配哈希表的空间
	H = new struct HashTbl;
	if (H == NULL)
	{
		cout << "内存分配失败！\n";
		getchar();
		exit(-1);
	}
	H->TableSize = NextPrime(TableSize);//NextPrime函数用于把TableSize转换成最接近的素数
	//H->TableSize = TableSize;//执行该语句和执行上一个语句导致的存储结果是不同的。
	//分配链表数组的空间
	H->TheLists = (List*) malloc(sizeof(List)*H->TableSize);
	if (H->TheLists == NULL)
	{
		cout << "内存分配失败！\n";
		getchar();
		exit(-1);
	}
	//分配表头空间，并将表头的Next设置为NULL
	for (i = 0;i < H->TableSize;i++)
	{
		H->TheLists[i] = new struct ListNode;
		if (H->TheLists[i] == NULL)
		{
			cout << "内存分配失败！\n";
			getchar();
			exit(-1);
		}
		else
		{
			H->TheLists[i]->Next = NULL;
		}
	}
	return H;
}

void DestroyTable(HashTable H)
{
	if (H == NULL)
	{
		delete H;
	}
	List temp1, temp2;
	for (int i = 0;i < H->TableSize;i++)
	{
		temp1 = H->TheLists[i];
		while (temp1!= NULL)
		{
			temp2 = temp1;
			temp1 = temp1->Next;
			delete temp2;
		}
	}
}

Position Find(ElementType Key, HashTable H)
{
	Position P;
	List L;
	L = H->TheLists[Hash(Key, H->TableSize)];//Hash函数是散列函数，用来计算关键字与数组的映射
	P = L->Next;//上一步L取得的是表头的地址
	while (P != NULL && P->Element != Key)//一般是在P->Element==Key时退出循环
	{
		P = P->Next;
	}
	return P;//当表中没有找到Key时，P就是以NULL退出while循环的，这时返回NULL
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)//返回Pos为空，就说明上一步没有找到Key，即可以插入
	{
		NewCell = new struct ListNode;
		if (NewCell == NULL)
		{
			cout << "内存分配失败！\n";
			getchar();
			exit(-1);
		}
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];//L是表头

			/*一种可能的实现，但是元素的顺序就反了，即后插入的元素反而排到了前面*/

			//NewCell->Next = L->Next;//指向空
			//NewCell->Element = Key;
			//L->Next = NewCell;//接在表头的后面

			/*另一种实现，即正常的顺序*/

			while (L->Next != NULL)
			{
				L = L->Next;
			}
			NewCell->Element = Key;
			NewCell->Next = NULL;
			L->Next = NewCell;
		}
	}
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

void MakeEmpty(HashTable H)//只保留表头
{
	if (H == NULL)
	{
		cout << "哈希表已经为空！\n";
	}
	for (int i = 0;i < H->TableSize;i++)
	{
		List temp1;
		temp1 = H->TheLists[i]->Next;//现在是表头的后一个（也就是第一个）有效元素
		H->TheLists[i]->Next = NULL;
		while (temp1 != NULL)
		{
			List temp2 = new struct ListNode;
			temp2 = temp1;
			temp1 = temp1->Next;
			delete temp2;//每次delete 变量后，必须要重新创建，否则再次使用时，这个变量是不存在的
		}
	}
}

void Delete(ElementType Key, HashTable H)
{
	Position P;
	List L;
	L = H->TheLists[Hash(Key, H->TableSize)];//Hash函数是散列函数，用来计算关键字与数组的映射
	P = L->Next;//上一步L取得的是表达的地址
	while (P != NULL && P->Next->Element != Key)//一般是在P->Element==Key时退出循环
	{
		P = P->Next;
	}
	Position temp = P->Next;
	delete temp;
	P->Next = NULL;
}