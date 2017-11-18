#pragma once
#ifndef AVL_TREE_H_
#define AVL_TREE_H_

struct AvlNode;
typedef int ElementType;
typedef struct AvlNode * Position;
typedef struct AvlNode * AvlTree;

struct AvlNode
{
	ElementType Element;//该结点的值
	AvlTree Left;//左子树
	AvlTree Right;//右子树
	int Height;//每个结点都要存储高度
};

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
int Height(Position P);//AVL树中的Height函数和二叉查找树中的Height函数不一样，因为AVL树中每一个结点都存储着高度信息
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
static Position SingleRotateWithLeft(Position K2);//左单旋转   ①对α的左儿子的左子树进行一次插入
static Position SingleRotateWithRight(Position K2);//右单旋转  ②对α的右儿子的右子树进行一次插入
static Position DoubleRotateWithLeft(Position K3);//左双旋转   ①对α的左儿子的右子树进行一次插入
static Position DoubleRotateWithRight(Position K3);//右双旋转  ②对α的右儿子的左子树进行一次插入
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
void PrintTree(Position P);//从树叶到树根把每个值打印出来
void PrintElement(ElementType X);
int maxDepth(AvlTree  root);
bool isBalanced(AvlTree root);
int max(int a, int b);

#endif // !AVL_TREE_H_
