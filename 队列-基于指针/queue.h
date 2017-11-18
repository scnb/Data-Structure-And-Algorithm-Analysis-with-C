#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_

struct QueueRecord;
typedef struct QueueRecord * Queue;//queue是队列结构的指针
typedef int ElementType;
typedef struct ListRecord * List;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
void Show(Queue Q);

#endif // !QUEUE_H_

