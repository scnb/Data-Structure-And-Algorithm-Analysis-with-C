#pragma once
#ifndef AVL_TREE_H_
#define AVL_TREE_H_

struct AvlNode;
typedef int ElementType;
typedef struct AvlNode * Position;
typedef struct AvlNode * AvlTree;

struct AvlNode
{
	ElementType Element;//�ý���ֵ
	AvlTree Left;//������
	AvlTree Right;//������
	int Height;//ÿ����㶼Ҫ�洢�߶�
};

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
int Height(Position P);//AVL���е�Height�����Ͷ���������е�Height������һ������ΪAVL����ÿһ����㶼�洢�Ÿ߶���Ϣ
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
static Position SingleRotateWithLeft(Position K2);//����ת   �ٶԦ�������ӵ�����������һ�β���
static Position SingleRotateWithRight(Position K2);//�ҵ���ת  �ڶԦ����Ҷ��ӵ�����������һ�β���
static Position DoubleRotateWithLeft(Position K3);//��˫��ת   �ٶԦ�������ӵ�����������һ�β���
static Position DoubleRotateWithRight(Position K3);//��˫��ת  �ڶԦ����Ҷ��ӵ�����������һ�β���
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
void PrintTree(Position P);//����Ҷ��������ÿ��ֵ��ӡ����
void PrintElement(ElementType X);
int maxDepth(AvlTree  root);
bool isBalanced(AvlTree root);
int max(int a, int b);

#endif // !AVL_TREE_H_
