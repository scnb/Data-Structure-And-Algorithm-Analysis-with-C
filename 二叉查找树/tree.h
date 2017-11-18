#pragma once
#ifndef TREE_H_
#define TREE_H_

#include <vector>
using std::vector;
struct TreeNode;
typedef int ElementType;
typedef struct TreeNode * SearchTree;
typedef struct TreeNode * Position;

struct TreeNode
{
	ElementType Element;
	SearchTree left;
	SearchTree right;
};

void PreOrderTraverse(TreeNode * root, int * max, TreeNode * pos[]);
TreeNode* maxNode(TreeNode* root);
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);
void PreOrderTraverse(TreeNode * root, TreeNode * Pos);
TreeNode* maxNode(TreeNode* root);
void PrintTree(Position P);//从树叶到树根把每个值打印出来
void PrintElement(ElementType X);
int Height(Position P);
void PreOrderTraverse(TreeNode * root, int  pos, vector<int> A);
vector<int> preorderTraversal(TreeNode *root);
void CloneTraverse(TreeNode * root, TreeNode * root2, int flag);
TreeNode* cloneTree(TreeNode *root);


#endif // !TREE_H_
