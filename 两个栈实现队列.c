#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType data);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);
void StackInit(ST* ps)
{
	assert(ps);
	ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->data == NULL)
	{
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
//ÈëÕ»
void StackPush(ST* ps, STDataType data)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		STDataType* tmp = (STDataType*)realloc(ps->data, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			exit(-1);
		}
		else
		{
			ps->data = tmp;
			ps->capacity *= 2;
		}
	}
	ps->data[ps->top] = data;
	ps->top++;
	//ps->capacity++;

}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	/*if (ps->capacity == 0)
	{
		return;
	}*/
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->data[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
typedef struct CQueue {
	ST pushS;
	ST popS;
} CQueue;


CQueue* cQueueCreate() {
	CQueue* q = (CQueue*)malloc(sizeof(CQueue));
	if (q == NULL)
	{
		exit(-1);
	}
	StackInit(&q->pushS);
	StackInit(&q->popS);
	return q;
}

void cQueueAppendTail(CQueue* obj, int value)
{
	if (!StackEmpty(&obj->popS))
	{
		while (StackSize(&obj->popS) > 0)
		{
			int tmp = StackTop(&obj->popS);
			StackPop(&obj->popS);
			StackPush(&obj->pushS, tmp);
		}
		StackPush(&obj->pushS, value);
		while (StackSize(&obj->pushS) > 0)
		{
			int tmp = StackTop(&obj->pushS);
			StackPop(&obj->pushS);
			StackPush(&obj->popS, tmp);
		}

	}
	else
	{
		StackPush(&obj->popS, value);
	}

}

int cQueueDeleteHead(CQueue* obj)
{
	if (StackEmpty(&obj->popS))
	{
		return -1;
	}
	int top = StackTop(&obj->popS);
	StackPop(&obj->popS);
	return top;
}

void cQueueFree(CQueue* obj)
{
	StackDestroy(&obj->popS);
	StackDestroy(&obj->pushS);
	free(obj);
}