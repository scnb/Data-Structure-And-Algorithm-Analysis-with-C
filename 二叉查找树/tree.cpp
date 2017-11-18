#include "stdafx.h"
#include "tree.h"
#include <iostream>
#include <algorithm>
#include <vector>

using std::max;

using std::cout;
using std::cin;
using std::endl;
using std::vector;

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		delete T;
	}
	return NULL;
}

void PreOrderTraverse(TreeNode * root, int * max, TreeNode * pos[])
{
	if (root == NULL)
	{
		return;
	}
	if (*max < root->Element)
	{
		*max = root->Element;
		pos[0] = root;
	}
	PreOrderTraverse(root->left, max, pos);
	PreOrderTraverse(root->right, max, pos);
}

TreeNode* maxNode(TreeNode* root)
{
	// Write your code here
	int max = -65535;
	TreeNode * pos[1] = { NULL };//���������Ҫ���������ʽ����Ϊֻ��TreeNode * posʱ��pos�ڵݹ麯������ʱ����˵�ԭ����ֵ
	PreOrderTraverse(root, &max, pos);
	 //cout<<max<<endl;
	return pos[0];
}

Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Element == X)
	{
		return T;
	}
	else if(X < T->Element)
	{
		Find(X, T->left);
	}
	else if (X > T->Element)
	{
		Find(X, T->right);
	}
	else
	{
		return NULL;
	}
}

Position FindMin(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->left == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->left);
	}
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->right == NULL)
	{
		return T;
	}
	else
	{
		return FindMax(T->right);
	}
}

/*ǰ�����*/
void PreOrderTraverse(TreeNode * root, TreeNode * Pos)
{
	int max = root->Element;
	if (root == NULL)
	{
		return;
	}
	PreOrderTraverse(root->left, Pos);
	PreOrderTraverse(root->right, Pos);
}

//TreeNode* maxNode(TreeNode* root) 
//{
//	TreeNode * Position = root;
//	PreOrderTraverse(root, Position);
//	return Position;
//}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = new struct TreeNode;
		if (T == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�\n";
			exit(-1);
		}
		else
		{
			T->Element = X;
			T->left = T->right = NULL;
		}
	}
	else if (X < T->Element)
	{
		T->left = Insert(X, T->left);
	}
	else if (X > T->Element)
	{
		T->right = Insert(X, T->right);
	}
	return T;//������Ҫһ��һ��ķ���T��ֵ����Ϊԭ��T��ֵ��Insert�����ڲ����ı���
}

void PreOrderTraverse(TreeNode * root, int * pos, vector<int> A)
{
	if (root == NULL)
	{
		return;
	}
	A[(*pos)++] = root->Element;
	PreOrderTraverse(root->left, pos, A);
	PreOrderTraverse(root->right, pos, A);
}

vector<int> preorderTraversal(TreeNode *root)
{
	// write your code here
	vector<int> A(3);
	int a = 0;
	PreOrderTraverse(root,&a, A);
	return A;
}

SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;
	if (T == NULL)
	{
		cout << "û���ҵ���ֵ��\n";
	}
	else if (X < T->Element)
	{
		T->left = Delete(X, T->left);
	}
	else if (X > T->Element)
	{
		T->right = Delete(X, T->right);
	}
	else if (T->left&&T->right)//��������  ������������С�����ݵĽ�����ý������ݲ��ݹ��ɾ���ý��
	{
		//������������С�Ľ��������ý��
		TmpCell = FindMin(T->right);
		T->Element = TmpCell->Element;
		T->right = Delete(T->Element, T->right);//�ݹ��ɾ���ý��
	}
	else if(X==T->Element)//0����1������ ���ý��ĺ��Ӹ��丸�ڵ�
	{
		TmpCell = T;
		if (T->left == NULL)
		{
			T = T->right;
		}
		else if (T->right == NULL)
		{
			T = T->left;
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
		PrintTree(P->left);
		PrintElement(P->Element);
		PrintTree(P->right);
	}
}

int Height(Position P)//���ϴӵ�ǰ���ݹ鵽��Ҷ��Ȼ����һ���������ؼ�
{
	if (P == NULL)
	{
		return -1;
	}
	if (P != NULL)
	{
		return 1 + max(Height(P->left), Height(P->right));//����һ�������˵��Ҫ�����ĸ߶ȣ���Ҫ֪���������������ĸ߶ȣ�Ȼ��ȡ����ߣ��ټ�1
	}
}

void CloneTraverse(TreeNode * root, TreeNode * root2, int flag)
{
	if (root == NULL)
	{
		root2 = NULL;
		return;
	}
	if (flag == 1)
	{
		TreeNode * temp = new TreeNode;
		temp->Element = root->Element;
		temp->left = temp->right = NULL;
		root2->left = temp;
		root2 = root2->left;
	}
	if (flag == 2)
	{
		TreeNode * temp = new TreeNode;
		temp->Element = root->Element;
		temp->left = temp->right = NULL;
		root2->right = temp;
		root2 = root2->right;
	}
	CloneTraverse(root->left, root2, 1);
	CloneTraverse(root->right, root2, 2);
}

TreeNode* cloneTree(TreeNode *root)
{
	// Write your code here
	TreeNode * head = new TreeNode;
	head->Element = root->Element;
	head->left = head->right = NULL;
	TreeNode * p = head;
	CloneTraverse(root, p, 0);
	return head;
}