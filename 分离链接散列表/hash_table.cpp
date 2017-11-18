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

int NextPrime(int size)//������size��С��ӽ�������
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
		cout << "��ϣ��̫С�ˣ�\n";
		return NULL;
	}
	//�����ϣ��Ŀռ�
	H = new struct HashTbl;
	if (H == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		getchar();
		exit(-1);
	}
	H->TableSize = NextPrime(TableSize);//NextPrime�������ڰ�TableSizeת������ӽ�������
	//H->TableSize = TableSize;//ִ�и�����ִ����һ����䵼�µĴ洢����ǲ�ͬ�ġ�
	//������������Ŀռ�
	H->TheLists = (List*) malloc(sizeof(List)*H->TableSize);
	if (H->TheLists == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		getchar();
		exit(-1);
	}
	//�����ͷ�ռ䣬������ͷ��Next����ΪNULL
	for (i = 0;i < H->TableSize;i++)
	{
		H->TheLists[i] = new struct ListNode;
		if (H->TheLists[i] == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�\n";
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
	L = H->TheLists[Hash(Key, H->TableSize)];//Hash������ɢ�к�������������ؼ����������ӳ��
	P = L->Next;//��һ��Lȡ�õ��Ǳ�ͷ�ĵ�ַ
	while (P != NULL && P->Element != Key)//һ������P->Element==Keyʱ�˳�ѭ��
	{
		P = P->Next;
	}
	return P;//������û���ҵ�Keyʱ��P������NULL�˳�whileѭ���ģ���ʱ����NULL
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)//����PosΪ�գ���˵����һ��û���ҵ�Key�������Բ���
	{
		NewCell = new struct ListNode;
		if (NewCell == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�\n";
			getchar();
			exit(-1);
		}
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];//L�Ǳ�ͷ

			/*һ�ֿ��ܵ�ʵ�֣�����Ԫ�ص�˳��ͷ��ˣ���������Ԫ�ط����ŵ���ǰ��*/

			//NewCell->Next = L->Next;//ָ���
			//NewCell->Element = Key;
			//L->Next = NewCell;//���ڱ�ͷ�ĺ���

			/*��һ��ʵ�֣���������˳��*/

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

void MakeEmpty(HashTable H)//ֻ������ͷ
{
	if (H == NULL)
	{
		cout << "��ϣ���Ѿ�Ϊ�գ�\n";
	}
	for (int i = 0;i < H->TableSize;i++)
	{
		List temp1;
		temp1 = H->TheLists[i]->Next;//�����Ǳ�ͷ�ĺ�һ����Ҳ���ǵ�һ������ЧԪ��
		H->TheLists[i]->Next = NULL;
		while (temp1 != NULL)
		{
			List temp2 = new struct ListNode;
			temp2 = temp1;
			temp1 = temp1->Next;
			delete temp2;//ÿ��delete �����󣬱���Ҫ���´����������ٴ�ʹ��ʱ����������ǲ����ڵ�
		}
	}
}

void Delete(ElementType Key, HashTable H)
{
	Position P;
	List L;
	L = H->TheLists[Hash(Key, H->TableSize)];//Hash������ɢ�к�������������ؼ����������ӳ��
	P = L->Next;//��һ��Lȡ�õ��Ǳ��ĵ�ַ
	while (P != NULL && P->Next->Element != Key)//һ������P->Element==Keyʱ�˳�ѭ��
	{
		P = P->Next;
	}
	Position temp = P->Next;
	delete temp;
	P->Next = NULL;
}