// 分离链接散列表.cpp : 定义控制台应用程序的入口点。
//散列是一种用于以常数平均时间执行插入、删除和查找的技术。
//理想的散列表数据结构只不过是一个包含有关键字的具有固定大小的数组。关键字可以是数据、字符串等。
//在分离链接散列表中，解决同一个位置插入多个元素的冲突的方法是分离链接法，即用链表把这些元素都接起来。
//散列表的装填因子λ：表中元素的个数/表的大小

#include "stdafx.h"
#include "hash_table.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	HashTable h = InitializeTable(10);
	for (int i = 0;i < h->TableSize;i++)
	{
		Insert(i*i, h);
	}
	cout << "显示哈希表中的值：\n";
	for (int i = 0;i < h->TableSize;i++)
	{
		List L = h->TheLists[i]->Next;
		while (L != NULL)
		{
			cout<<Retrieve(L)<<" ";
			L = L->Next;
		}
		cout << endl;
	}
	cout << "执行MakeEmpty操作：" << endl;
	MakeEmpty(h);
	cout << "显示哈希表中的值：\n";
	for (int i = 0;i < h->TableSize;i++)
	{
		List L = h->TheLists[i]->Next;
		while (L != NULL)
		{
			cout << Retrieve(L) << " ";
			L = L->Next;
		}
		cout << endl;
	}
	cout << endl;
	cout << "Done!" << endl;
	getchar();
    return 0;
}

