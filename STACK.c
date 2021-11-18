#define _CRT_SECURE_NO_WARNINGS 1

#include"STACK.h"
//初始化栈
LinkStack* InitStack() {
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}
//入栈
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
//出栈
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
//返回栈顶元素
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
//返回栈元素个数
int StackNum(LinkStack* stack) {
	if (stack == NULL)
	{
		return -1;
	}
	return stack->size;
}
//栈的清空
void ClearStack(LinkStack* stack) {
	//assert(head);
	if (stack == NULL)
	{
		return NULL;
	}
	stack->head.next = NULL;
	stack->size = 0;

}
//栈的销毁
void StackDeatroy(LinkStack* stack) {
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}
