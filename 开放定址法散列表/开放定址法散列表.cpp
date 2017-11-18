// 开放定址法散列表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "hash_tbl.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	HashTable h = InitializeTable(10);
	Insert(89,h);
	Insert(18, h);
	Insert(49, h);
	Insert(58, h);
	Insert(69, h);
	cout << "显示哈希表中的值：\n";
	for (int i = 0;i < h->TableSize;i++)
	{
		if (h->TheCells[i].Info == Legitimate)
		{
			cout << Retrieve(i, h);
			cout << endl;
		}
		if (h->TheCells[i].Info == Empty || h->TheCells[i].Info == Deleted)
		{
			cout << endl;
		}
	}
	cout << "重新分配哈希表：\n";
	h = Rehash(h);
	cout << "显示哈希表中的值：\n";
	for (int i = 0;i < h->TableSize;i++)
	{
		if (h->TheCells[i].Info == Legitimate)
		{
			cout << Retrieve(i, h);
			cout << endl;
		}
		if (h->TheCells[i].Info == Empty || h->TheCells[i].Info == Deleted)
		{
			cout << endl;
		}
	}
	cout << "销毁哈希表：\n";
	DestroyTable(h);
	cout << "显示哈希表中的值：\n";
	for (int i = 0;i < h->TableSize;i++)
	{
		if (h->TheCells[i].Info == Legitimate)
		{
			cout << Retrieve(i, h);
			cout << endl;
		}
		if (h->TheCells[i].Info == Empty || h->TheCells[i].Info == Deleted)
		{
			cout << endl;
		}
	}
	cout << "Done!" << endl;
	getchar();
    return 0;
}

