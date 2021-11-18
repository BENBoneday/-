#define _CRT_SECURE_NO_WARNINGS 1

#include"STACK.h"
//��ʼ��ջ
LinkStack* InitStack() {
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}
//��ջ
void PushStack(LinkStack* stack, LinkNode* data) {
	//assert(head);
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}
//��ջ
void PopStack(LinkStack* stack) {
	//assert(head);
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	LinkNode* pNext = stack->head.next;
	//LinkNode* next = cur->next;
	//free(cur);
	stack->head.next = pNext->next;
	stack->size--;
}
//����ջ��Ԫ��
LinkNode* StackTop(LinkStack* stack) {
	if (stack == NULL)
	{
		return NULL;
	}
	if (stack->size == 0)
	{
		return NULL;
	}
	return stack->head.next;
}
//����ջԪ�ظ���
int StackNum(LinkStack* stack) {
	if (stack == NULL)
	{
		return -1;
	}
	return stack->size;
}
//ջ�����
void ClearStack(LinkStack* stack) {
	//assert(head);
	if (stack == NULL)
	{
		return NULL;
	}
	stack->head.next = NULL;
	stack->size = 0;

}
//ջ������
void StackDeatroy(LinkStack* stack) {
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}
