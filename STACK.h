#define _CRT_SECURE_NO_WARNINGS 1
#ifndef	STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#endif
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;
typedef struct LINKSTACK
{
	int size;
	LinkNode head;
}LinkStack;
//初始化栈
LinkStack* InitStack();

//入栈
void PushStack(LinkStack* stack, LinkNode* data);
//出栈
void PopStack(LinkStack* stack);
//返回栈顶元素
LinkNode* StackTop(LinkStack* stack);
//返回栈元素个数
int StackNum(LinkStack* stack);
//栈的清空
void ClearStack(LinkStack* stack);
//栈的销毁
void StackDeatroy(LinkStack* stack);

