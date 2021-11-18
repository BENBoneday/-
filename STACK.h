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
//��ʼ��ջ
LinkStack* InitStack();

//��ջ
void PushStack(LinkStack* stack, LinkNode* data);
//��ջ
void PopStack(LinkStack* stack);
//����ջ��Ԫ��
LinkNode* StackTop(LinkStack* stack);
//����ջԪ�ظ���
int StackNum(LinkStack* stack);
//ջ�����
void ClearStack(LinkStack* stack);
//ջ������
void StackDeatroy(LinkStack* stack);

