#include "stdafx.h"
#include "avl_tree.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;

int Height(Position P)//P��㴦�ĸ߶�
{
	if (P == NULL)
	{
		return -1;//����㴦�ĸ߶�Ϊ-1
	}
	else
	{
		return P->Height;
	}
}

AvlTree MakeEmpty(AvlTree T)
{
	if (T == NULL)
	{
		return T;
	}
	else
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
	}
}

Position Find(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		cout << "û���ҵ���Ԫ�أ�\n";
	}
	else if (X < T->Element)
	{
		Find(X, T->Left);
	}
	else if (X > T->Element)
	{
		Find(X, T->Right);
	}                        //ʡ����X==T->Element���������Ϊ�������Ҳ��ֱ�ӷ���T��ֵ
	return T;
}

Position FindMin(AvlTree T)
{
	/*if (T == NULL)
	{
		cout << "������\n";
	}
	AvlTree temp = T;
	while (temp->Left != NULL)
	{
		temp = temp->Left;
	}
	return temp;*/

	//�ݹ�ķ���
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Left == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
}

Position FindMax(AvlTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Right == NULL)
	{
		return T;
	}
	else
	{
		return FindMax(T->Right);
	}
}

static Position SingleRotateWithLeft(Position K2)//�ٶԦ�������ӵ�����������һ�β���  ʵ����������
{
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;//���������������ĸ߶�ȡ���ֵ���ټ�1����Ϊ��Ҫ����K2
	K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
	return K1;//�����µġ�������㣬������ԭ��K2�Ľ��
}

static Position SingleRotateWithRight(Position K2)//�ڶԦ����Ҷ��ӵ�����������һ�β���   ʵ����������
{
	Position K1;
	K1=K2->Right;         //ԭ�������йؼ��Ĵ����Ǵ���ģ�һ��Ҫ��ͼ������д���򣬰�ʵ�ʵı仯������
	K2->Right=K1->Left;
	K1->Left=K2;
	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
	return K1;//�����µġ������ڵ㣬������ԭ��K2�Ľ��
}
	

static Position DoubleRotateWithLeft(Position K3)//�ٶԦ�������ӵ�����������һ�β���  ��������������
{
	//����K1��K2֮�������ת
	K3->Left = SingleRotateWithRight(K3->Left);
	//����K2��K3֮�������ת
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K4)//�ٶԦ����Ҷ��ӵ�����������һ�β���  ��������������
{
	K4->Right = SingleRotateWithLeft(K4->Right);
	return SingleRotateWithRight(K4);
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		//����������һ��ֻ��һ��������S
		T = new struct AvlNode;
		if (T == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�\n";
			exit(-1);
		}
		else
		{
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)//���ɲ�ƽ�������
		{
			if (X < T->Left->Element) //����Ľ���ֵ�����ӵ�ֵС���͵���ת
			{
				T = SingleRotateWithLeft(T);
			}
			else
			{
				T = DoubleRotateWithLeft(T);
			}
		}
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->Element)
			{
				T = SingleRotateWithRight(T);
			}
			else
			{
				T = DoubleRotateWithRight(T);
			}
		}
	}
	//���X�Ѿ���������ˣ���ʲô������
	T->Height = max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int maxDepth(AvlTree  root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->Left);//��һ�ε���maxDepth�󣬽�����һ����еݹ飬ֱ��root==NULL
	int rightDepth = maxDepth(root->Right);//���������ײ�ݹ�󣬽�����һ����еݹ飬ֱ��root==NULL
	if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth)>1)
	{
		return -1;//Ϊʲô�᷵��-1�أ�
	}
	return max(leftDepth, rightDepth) + 1;
}

bool isBalanced(AvlTree root) 
{
	// write your code here
	return (-1 != (maxDepth(root)));
}

AvlTree Delete(ElementType X, AvlTree T)
{
	Position TmpCell;
	if (T == NULL)
	{
		cout << "û���ҵ���ֵ��\n";
	}
	else if (X < T->Element)
	{
		T->Left = Delete(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Delete(X, T->Right);
	}
	else if (T->Left&&T->Right)//��������  ������������С�����ݵĽ�����ý������ݲ��ݹ��ɾ���ý��
	{
		//������������С�Ľ��������ý��
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);//�ݹ��ɾ���ý��
	}
	else if (X == T->Element)//0����1������ ���ý��ĺ��Ӹ��丸�ڵ�
	{
		TmpCell = T;
		if (T->Left == NULL)
		{
			T = T->Right;
		}
		else if (T->Right == NULL)
		{
			T = T->Left;
		}
		delete TmpCell;
	}
	return T;
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

void PrintElement(ElementType X)
{
	cout << X << " ";
}

void PrintTree(Position P)
{
	if (P != NULL)
	{
		PrintTree(P->Left);
		PrintElement(P->Element);
		PrintTree(P->Right);
	}
}
