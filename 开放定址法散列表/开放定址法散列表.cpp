// ���Ŷ�ַ��ɢ�б�.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "��ʾ��ϣ���е�ֵ��\n";
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
	cout << "���·����ϣ��\n";
	h = Rehash(h);
	cout << "��ʾ��ϣ���е�ֵ��\n";
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
	cout << "���ٹ�ϣ��\n";
	DestroyTable(h);
	cout << "��ʾ��ϣ���е�ֵ��\n";
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

