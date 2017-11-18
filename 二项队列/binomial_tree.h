#pragma once
#ifndef BINOMIAL_TREE_H_
#define BINOMIAL_TREE_H_

#define MaxTrees 5;

struct BinNode;
struct Collection;
typedef struct Collection * BinQueue;
typedef struct BinNode * Position;
typedef struct BinNode * BinTree;
typedef int ElementType;

struct BinNode
{
	ElementType Element;
	Position LeftChild;
	Position NextSibling;
};

struct Collection
{
	int CurrentSize;
	BinTree TheTrees[5];
};

BinQueue Initialize();
void DestroyQueue(BinQueue H);
int IsEmpty(BinQueue H);
void MakeEmpty(BinQueue H);
BinTree CombineTrees(BinTree T1, BinTree T2);
BinQueue Merge(BinQueue Q1, BinQueue Q2);
ElementType DeleteMin(BinQueue H);

#endif // !BINOMIAL_TREE_H_
