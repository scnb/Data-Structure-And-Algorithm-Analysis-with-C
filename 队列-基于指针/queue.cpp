#include "stdafx.h"
#include "queue.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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

int IsEmpty(Queue Q)
{
	return Q->front == Q->rear;
}

Queue CreateQueue(void)
{
	Queue Q = new struct QueueRecord;
	Q->list = new struct ListRecord;
	if (Q->list == NULL||Q == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�\n";
		exit(-1);
	}
	Q->list->next = NULL;
	Q->list->value = 0;
	Q->rear = Q->list;
	Q->front = Q->list;
}

void DisposeQueue(Queue Q)
{
	delete Q->list;
	delete Q;
}

void MakeEmpty(Queue Q)
{
	List temp = Q->front;
	List tmp = temp;
	while (temp != Q->rear)
	{
		tmp = temp->next;
		delete tmp;
		temp = temp->next;
	}
	delete temp;
}

void Enqueue(ElementType X, Queue Q)
{
	static int i = 1;
	if (i == 1)
	{
		Q->front->value = X;
		i++;
	}
	else
	{
		List temp = new struct ListRecord;
		if (temp == NULL)
		{
			cout << "�ڴ����ʧ�ܣ�\n";
			exit(-1);
		}
		temp->value = X;
		temp->next = NULL;
		Q->rear->next = temp;
		Q->rear = temp;
	}
}

ElementType Front(Queue Q)
{
	return Q->front->value;
}

void Dequeue(Queue Q)//��ɾ�������е�Ԫ��ʱ���ж϶����Ƿ�Ϊ�յķ�����������������Show�������еķ�����ͬ����Ϊ��Q->front==Q->rearʱ������һ��Ԫ��û�г���
{
	if (Q->front == NULL)
	{
		cout << "����Ϊ�գ�\n";
	}
	else
	{
		List temp = Q->front;
		Q->front = Q->front->next;
		delete temp;
	}	
}

ElementType FrontAndDequeue(Queue Q)
{
	if (Q->front==NULL)
	{
		cout << "����Ϊ�գ�\n";
		return 0;
	}
	else
	{
		ElementType value = Front(Q);
		List temp = Q->front;
		Q->front = Q->front->next;
		delete temp;
		return value;
	}
}

void Show(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "����Ϊ�գ�\n";
	}
	else
	{
		List temp = Q->front;
		while (temp != Q->rear)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << temp->value;
	}
	cout << endl;
}