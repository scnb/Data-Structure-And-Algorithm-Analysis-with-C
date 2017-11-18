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
	TreeNode * pos[1] = { NULL };//在这里必须要用数组的形式，因为只用TreeNode * pos时，pos在递归函数回溯时会回退到原来的值
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

/*前序遍历*/
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
			cout << "内存分配失败！\n";
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
	return T;//最后必须要一层一层的返回T的值，因为原来T的值在Insert函数内部被改变了
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
		cout << "没有找到该值！\n";
	}
	else if (X < T->Element)
	{
		T->left = Delete(X, T->left);
	}
	else if (X > T->Element)
	{
		T->right = Delete(X, T->right);
	}
	else if (T->left&&T->right)//两个孩子  用右子树的最小的数据的结点代替该结点的数据并递归地删除该结点
	{
		//用右子树的最小的结点来代替该结点
		TmpCell = FindMin(T->right);
		T->Element = TmpCell->Element;
		T->right = Delete(T->Element, T->right);//递归的删除该结点
	}
	else if(X==T->Element)//0个或1个孩子 将该结点的孩子给其父节点
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

int Height(Position P)//不断从当前结点递归到树叶，然后在一部部的往回加
{
	if (P == NULL)
	{
		return -1;
	}
	if (P != NULL)
	{
		return 1 + max(Height(P->left), Height(P->right));//对于一个结点来说，要算它的高度，就要知道它的左右子树的高度，然后取其大者，再加1
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