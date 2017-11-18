#include "stdafx.h"
#include "LeftHeap.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

PriorityQueue Initialize(void)//��ʼ����ʱ�����������Ĺ���������һ����ָ��Ϳ��ԣ��������Է���Ĵ������ڵ�
{
	/*PriorityQueue H;
	H = new struct TreeNode;
	if (H == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		getchar();
		exit(-1);
	}
	H->Element = 0;
	H->Left = H->Right = NULL;
	H->Npl = 0;
	return H;*/
	return NULL;
}

ElementType FindMin(PriorityQueue H)
{
	if (!IsEmpty(H))
	{
		return H->Element;//������ж���ѵĶ����ԣ������ڵ�Ϊ��Сֵ
	}
	return 0;
}

int IsEmpty(PriorityQueue H)
{
	return H == NULL;
}

/*��Merge����Ϊ�ϲ���������������Ԥ�ȴ���һЩ�����������H1Ϊ��
													   ��H2Ϊ��
  Ȼ�����H1��H2˭�ĸ��ڵ��С������������Merge1�����Ĳ�����˳��
*/

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
	{
		return H2;
	}
	if (H2 == NULL)
	{
		return H1;
	}
	if (H1->Element < H2->Element)//�ж�˭�ĸ��ڵ�ֵ��С���Ѹöѷ��ڵ�һ������
	{
		Merge1(H1, H2);
	}
	else
	{
		Merge1(H2, H1);
	}
}

void SwapChildren(PriorityQueue H)
{
	PriorityQueue temp;
	temp = H->Left;
	H->Left = H->Right;
	H->Right = temp;
}

/*����Merge1������ʹH1����������H2���кϲ�*/

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
	if (H1->Left == NULL)
	{
		H1->Left = H2;//���H1��������Ϊ�գ���ֱ�Ӱ�H2����H1��������
	}
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
		{
			SwapChildren(H1);
		}
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

/*�Ѳ���һ����������һ��ֻ��һ�����ĶѺͶ�H�ϲ�*/

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
	PriorityQueue SingleNode;
	SingleNode = new struct TreeNode;
	if (SingleNode == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		getchar();
		exit(-1);
	}
	else
	{
		SingleNode->Element = X;
		SingleNode->Npl = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}
	return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
	PriorityQueue LeftHeap, RightHeap;
	if (IsEmpty(H))
	{
		cout << "��������Ϊ�գ�\n";
		return H;
	}
	else
	{
		LeftHeap = H->Left;
		RightHeap = H->Right;
		delete H;
		return Merge(LeftHeap, RightHeap);
	}
}

ElementType Retrieve(PriorityQueue H)
{
	return H->Element;
}

void PrintElement(ElementType X)
{
	cout << X << " ";
}

void PrintTree(PriorityQueue H)
{
	if (H != NULL)
	{
		PrintTree(H->Left);
		PrintElement(H->Element);
		PrintTree(H->Right);
	}
}