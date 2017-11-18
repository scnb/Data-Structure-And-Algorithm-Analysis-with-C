#pragma once
#ifndef BFS_H_
#define BFS_H_

#define MAXVEX (100)
#define INFINITY (65535)
typedef int VertexType;
typedef int EdgeType;
struct QueueRecord;
typedef struct QueueRecord * Queue;//queue是队列结构的指针
typedef int ElementType;
typedef struct ListRecord * List;

typedef struct
{
	VertexType vexs[MAXVEX];//顶点表
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

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

void CreateGraph(MGraph * G);
Queue CreateQueue(void);
void EnQueue(Queue Q, ElementType X);
int IsEmpty(Queue Q);
ElementType Front(Queue Q);
void DeQueue(Queue Q, int a);
void BFSTraverse(MGraph G);


#endif // !BFS_H_
