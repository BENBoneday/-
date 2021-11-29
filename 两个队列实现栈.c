#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}


}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* newHead = pq->head->next;
		free(pq->head);
		pq->head = newHead;
	}

}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
typedef struct {
	Queue q1;
	Queue q2;

} MyStack;


MyStack* myStackCreate() {
	MyStack* myStack = (MyStack*)malloc(sizeof(MyStack));
	if (myStack == NULL)
	{
		exit(-1);
	}
	QueueInit(&myStack->q1);
	QueueInit(&myStack->q2);
	return myStack;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}

}

int myStackPop(MyStack* obj) {
	Queue* emptyQ = &obj->q1;
	Queue* unemptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		unemptyQ = &obj->q1;
		emptyQ = &obj->q2;
	}
	while (QueueSize(unemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(unemptyQ));
		QueuePop(unemptyQ);
	}
	int top = QueueFront(unemptyQ);
	QueuePop(unemptyQ);
	return top;

}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}
