#include "stdafx.h"
#include "queue.h"
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define MinQueueSize 5

struct QueueRecord
{
	int Capacity;//���е�����
	int front;//���е�ͷ���λ��
	int rear;//����β���λ��
	int size;//����Ŀǰ�Ľ�����
	ElementType * Array;//����
};

int IsEmpty(Queue Q)
{
	return Q->size == 0;
}

int IsFull(Queue Q)
{
	return Q->size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
	if (MaxElements < MinQueueSize)
	{
		MaxElements = MinQueueSize;
	}
	Queue Q = new struct QueueRecord;
	if (Q == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		exit(-1);
	}
	Q->Array = (int *)malloc(sizeof(ElementType)*MaxElements);
	if (Q->Array == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		exit(-1);
	}
	Q->Capacity = MaxElements;
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;
}

void DisposeQueue(Queue Q)
{
	free(Q->Array);
	delete Q;
}

void MakeEmpty(Queue Q)
{
	Q->rear = 0;
	Q->size = 0;
	Q->front = 1;
}

static int Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)
	{
		Value = 0;
	}
	return Value;
}

void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
	{
		cout << "�����������޷���ӣ�\n";
	}
	else
	{
		Q->rear = Succ(Q->rear, Q);
		Q->Array[Q->rear] = X;
		Q->size++;
	}
}

ElementType Front(Queue Q)//���ص�һ������ֵ
{
	return Q->Array[Q->front];
}

void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "����Ϊ�գ��޷����ӣ�\n";
	}
	else
	{
		Q->front = Succ(Q->front, Q);
	}
}

ElementType FrontAndDequeue(Queue Q)
{
	ElementType Value;
	if (IsEmpty(Q))
	{
		cout << "����Ϊ�գ��޷����ӣ�\n";
	}
	else
	{
		Value = Front(Q);
		Q->front = Succ(Q->front, Q);
	}
	return Value;
}

void Show(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "����Ϊ�գ�\n";
	}
	else
	{
		if (Q->front < Q->rear)
		{
			for (int i = Q->front;i <= Q->rear;i++)
			{
				cout << Q->Array[i] << " ";
			}
		}
		else if (Q->front > Q->rear)
		{
			int i = Q->front;
			while (i <= Q->Capacity-1)
			{
				cout << Q->Array[i] << " ";
				i++;
			}
			i = 0;
			while (i <= Q->rear)
			{
				cout << Q->Array[i] << " ";
				i++;
			}
		}
		cout << endl;
	}
}