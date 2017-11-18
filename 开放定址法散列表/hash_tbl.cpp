#include "stdafx.h"
#include "hash_tbl.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Index Hash(ElementType Key, HashTable H)
{
	static int i = 0;
	return Key%H->TableSize;// +(i++)*i) % H->TableSize;后面这一部分按照作者的代码确实应该注释掉
}							//其实还是因为我没有理解作者的意思，在Hash函数这里确实应该这样写，因为首先要找到理论上的位置，然后再判断该位置是否为空，
							//如果为空，则直接放在这里，如果不空，则再使用平方探测法来找到应该所在的位置。
							//平方探测法的思想和代码都在Find函数里。
int Prime(int a)
{
	for (int i = 2;i < a;i++)
	{
		if (a%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int NextPrime(int tablesize)
{
	for (int i = tablesize;i < tablesize * 2;i++)
	{
		if (Prime(i))
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
		getchar();
		exit(-1);
	}
	H = new struct HashTbl;
	if (H == NULL)
	{
		cout << "内存分配失败!\n";
		getchar();
		exit(-1);
	}
	//H->TableSize = NextPrime(TableSize);//不好用
	H->TableSize = TableSize;
	H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
	for (i = 0;i < H->TableSize;i++)
	{
		H->TheCells[i].Info = Empty;
	}
	return H;
}

void DestroyTable(HashTable H)
{
	delete H->TheCells;
	delete H;
}

Position Find(ElementType Key, HashTable H)
{
	Position CurrentPos;
	int CollisionNum;
	CollisionNum = 0;
	CurrentPos = Hash(Key, H);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)//判断一下该理论上的位置是否已经被其他元素占了
	{
		CurrentPos += 2 * (++CollisionNum) - 1;//根据平方探测的公式得出的结论，即i²=(i-1)²+2*i-1，即从当前位置到下一位置需要经过2*i-1个位置
		if (CurrentPos >= H->TableSize)//如果上一步得出的CurrentPos超出了数组范围
		{
			CurrentPos -= H->TableSize;//则减去哈希表的大小来把这个位置拉回数组
		}
	}
	return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos;
	Pos = Find(Key, H);//先返回一个索引值，然后在下面判断是否是空的
	if (H->TheCells[Pos].Info!=Legitimate)//千万别写成  !=Empty,这样会把deleted这种情况丢掉
	{
		H->TheCells[Pos].Element = Key;
		H->TheCells[Pos].Info = Legitimate;
	}
}

/* 再散列的目的是为了当原来的散列表很满的时候，在程序运行过程中
可以用该函数重建一个更大的散列表							*/

HashTable Rehash(HashTable H)//返回的一定是参数H
{
	int i, OldSize;
	Cell * OldCells;
	OldSize = H->TableSize;
	OldCells = H->TheCells;
	H = InitializeTable(2 * OldSize);
	for (int i = 0;i < OldSize;i++)
	{
		if (OldCells[i].Info == Legitimate)
		{
			Insert(OldCells[i].Element, H);
		}
	}
	delete OldCells;
	return H;
}

ElementType Retrieve(Position P, HashTable H)
{
	return H->TheCells[P].Element;
}