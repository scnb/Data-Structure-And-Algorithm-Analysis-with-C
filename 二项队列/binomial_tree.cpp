#include "stdafx.h"
#include "binomial_tree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

BinQueue Initialize(void)
{
	BinQueue H;
	int i;
	H = new struct Collection;
	if (H == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		getchar();
		exit(-1);
	}
	H->CurrentSize = 0;
	for (i = 0;i < MaxTrees;i++)
	{
		H->TheTrees[i] = new struct BinNode;
		if (H->TheTrees[i] == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�\n";
			getchar();
			exit(-1);
		}
		H->TheTrees[i]->LeftChild = H->TheTrees[i]->NextSibling = NULL;
	}
	return H;
}

int IsEmpty(BinQueue H)
{
	return H->CurrentSize == 0;
}

void DestroyQueue(BinQueue H)
{
	for (int i = 0;i < MaxTrees;i++)
	{
		delete H->TheTrees[i];
	}
	delete H;
}

void MakeEmpty(BinQueue H)
{
	BinNode temp;
	for (int i = 0;i < H->CurrentSize;i++)
	{
		temp = H->TheTrees[i];
		H->TheTrees[i] = NULL;
		delete temp;
	}
	H->CurrentSize = 0;
}

BinTree CombineTrees(BinTree T1, BinTree T2)
{
	if (T1->Element > T2->Element)
	{
		return CombineTrees(T2, T1);
	}
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
}

BinQueue Merge(BinQueue H1, BinQueue H2)
{
	BinTree T1, T2, Carry = NULL;
	int i, j;
	if (H1->CurrentSize + H2->CurrentSize > Capacity)
	{
		cout << "�ϲ������ᳬ����С��Χ��\n";
		return;
	}
	H1->CurrentSize += H2->CurrentSize;
	for (i = 0, j = 1;j <= H1->CurrentSize;i++, j *= 2)
	{
		T1 = H1->TheTrees[i];
		T2 = H2->TheTrees[j];
		switch (!!T1 + 2 * !!T2 + 4 * !!Carry)
		{
		case 0:/*û����*/
		case 1:/*ֻ����H1*/
			break;
		case 2:/*ֻ����H2*/
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		case 3:/*��H1����H2*/
			Carry = CombineTrees(T1, T2);
			H1->TheTrees[i] = H2->TheTrees[i] = NULL;
			break;
		case 4:/*ֻ����Carry*/
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		case 5:/*��H1����Carry*/
			Carry = CombineTrees(T1, Carry);
			H1->TheTrees[i] = NULL;
			break;
		case 6:/*��H2����Carry*/
			Carry = CombineTrees(T2, Carry);
			H2->TheTrees[i] = NULL;
			break;
		case 7:/*���е���*/
			H1->TheTrees[i] = Carry;
			Carry = CombineTrees(T1, T2);
			H2->TheTrees[i] = NULL;
			break;
		}
	}
	return H1;
}

ElementType DeleteMin(BinQueue H)
{
	int i, j;
	int MinTree;//�洢�����������С���ڵ��λ��
	BinQueue DeletedQueue;
	Position DeletedTree, OldRoot;//�ֱ�����������С���ڵ㣬��������ʱ�洢��С���ڵ�
	ElementType MinItem;//������С���ڵ��ֵ
	if (IsEmpty(H))
	{
		cout << "�������Ϊ�գ�\n";
		return -INFINITY;
	}
	MinItem = INFINITY;
	/*Ѱ����С���ڵ�*/
	for (i = 0;i < MaxTrees;i++)
	{
		if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)//����ý�㲻Ϊ�գ����Ҹý���ֵС�ڵ�ǰ����Сֵ
		{
			/*������С���ڵ�*/
			MinItem = H->TheTrees[i]->Element;
			MinTree = i;
		}
	}
	DeletedTree = H->TheTrees[i];//�����С��������
	OldRoot = DeletedTree;//����С���ڵ㱣������ʱ�����
	DeletedTree = DeletedTree->LeftChild;//�������ڵ㣬�Ѹ��ڵ�������洢��DeletedTree��
	delete OldRoot;//����С���ڵ�ɾ��
	DeletedQueue = Initialize();//��ʼ��һ����ʱ����������洢ԭ�����ڵ�ɾ��������ļ�������
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;//MinTree����С������ڶ����е�λ�ã��Ѹø����ɾ���󣬽������2^MinTree-1����
	/*����С���ڵ������   Ȼ����ϳ�һ���������*/
	for (j = MinTree - 1;j >= 0;j--)
	{
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}
	H->TheTrees[MinTree] = NULL;//��ԭ����������е���С�������0
	H->CurrentSize = H->CurrentSize - DeletedQueue->CurrentSize + 1;
	Merge(H, DeletedQueue);//�ϲ�ԭ���Ķ��к����ڵ���ʱ����
	return MinItem;//������Сֵ
}
