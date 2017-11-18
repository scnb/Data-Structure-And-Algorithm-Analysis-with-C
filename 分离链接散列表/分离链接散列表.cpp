// ��������ɢ�б�.cpp : �������̨Ӧ�ó������ڵ㡣
//ɢ����һ�������Գ���ƽ��ʱ��ִ�в��롢ɾ���Ͳ��ҵļ�����
//�����ɢ�б����ݽṹֻ������һ�������йؼ��ֵľ��й̶���С�����顣�ؼ��ֿ��������ݡ��ַ����ȡ�
//�ڷ�������ɢ�б��У����ͬһ��λ�ò�����Ԫ�صĳ�ͻ�ķ����Ƿ������ӷ��������������ЩԪ�ض���������
//ɢ�б��װ�����Ӧˣ�����Ԫ�صĸ���/��Ĵ�С

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
	cout << "��ʾ��ϣ���е�ֵ��\n";
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
	cout << "ִ��MakeEmpty������" << endl;
	MakeEmpty(h);
	cout << "��ʾ��ϣ���е�ֵ��\n";
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

