#pragma once
#ifndef BFS_H_
#define BFS_H_

#define MAXVEX (100)
typedef int VertexType;
struct QueueRecord;
typedef struct QueueRecord * Queue;//queue是队列结构的指针
typedef int ElementType;
typedef struct ListRecord * List;

typedef struct EdgeNode
{
	VertexType adjvex;
	int weight;
	struct EdgeNode * Next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	struct EdgeNode * firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;
	int numVertexes, numEdges;
}GraphAdjList;


struct ListRecord
{
	ElementType value;
	List next;
};

struct QueueRecord
{
	List front;
	List rear;
	List list;
};

void CreateGraph(GraphAdjList * G);
Queue CreateQueue(void);
void EnQueue(Queue Q, ElementType X);
int IsEmpty(Queue Q);
ElementType Front(Queue Q);
void DeQueue(Queue Q, int *a);
void BFSTraverse(GraphAdjList G);



#endif // !BFS_H_
