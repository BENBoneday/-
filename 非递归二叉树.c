#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#define MY_FALSE 0
#define MY_TRUE 1
#include"STACK.h"
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lChild;
	struct BINARYNODE* rChild;
}BinaryNode;
typedef struct BITREESTACKNODE
{
	LinkNode node;
	BinaryNode* root;
	int flag;
}BiTreeStackNode;
//创建栈中的结点
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node, int flag)
{
	BiTreeStackNode* newNode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newNode->flag = flag;
	newNode->root = node;
	return newNode;
}
//先序
void Recursion(BinaryNode* root)
{
	LinkStack* stack = InitStack();
	PushStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));
	while (StackNum(stack) > 0)
	{
		//弹出栈顶元素
		BiTreeStackNode* topNode = (BiTreeStackNode*)StackTop(stack);
		PopStack(stack);
		if (topNode->root == NULL)
		{
			continue;
		}
		if (topNode->flag == MY_TRUE)
		{
			printf("%c", topNode->root->ch);
		}
		else
		{
			PushStack(stack, (LinkNode*)CreateBiTreeStackNode(topNode->root->rChild, MY_FALSE));
			PushStack(stack, (LinkNode*)CreateBiTreeStackNode(topNode->root->lChild, MY_FALSE));
			topNode->flag = MY_TRUE;
			PushStack(stack, (LinkNode*)topNode);
		}
	}
}
//中序
void Recursion1(BinaryNode* root)
{
	LinkStack* stack = InitStack();
	PushStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));
	while (StackNum(stack) > 0)
	{
		//弹出栈顶元素
		BiTreeStackNode* topNode = (BiTreeStackNode*)StackTop(stack);
		PopStack(stack);
		if (topNode->root == NULL)
		{
			continue;
		}
		if (topNode->flag == MY_TRUE)
		{
			printf("%c", topNode->root->ch);
		}
		else
		{
			PushStack(stack, (LinkNode*)CreateBiTreeStackNode(topNode->root->rChild, MY_FALSE));
			topNode->flag = MY_TRUE;
			PushStack(stack, (LinkNode*)topNode);
			PushStack(stack, (LinkNode*)CreateBiTreeStackNode(topNode->root->lChild, MY_FALSE));
			
		}
	}
}
//后序
void Recursion2(BinaryNode* root)
{
	LinkStack* stack = InitStack();
	PushStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));
	while (StackNum(stack) > 0)
	{
		//弹出栈顶元素
		BiTreeStackNode* topNode = (BiTreeStackNode*)StackTop(stack);
		PopStack(stack);
		if (topNode->root == NULL)
		{
			continue;
		}
		if (topNode->flag == MY_TRUE)
		{
			printf("%c", topNode->root->ch);
		}
		else
		{
			topNode->flag = MY_TRUE;
			PushStack(stack, (LinkNode*)topNode);
			PushStack(stack, (LinkNode*)CreateBiTreeStackNode(topNode->root->rChild, MY_FALSE));
			
			PushStack(stack, (LinkNode*)CreateBiTreeStackNode(topNode->root->lChild, MY_FALSE));

		}
	}
}
void CreateBinaryTree()
{
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };

	node1.lChild = &node2;
	node1.rChild = &node6;
	node2.rChild = &node3;
	node3.lChild = &node4;
	node3.rChild = &node5;
	node6.rChild = &node7;
	node7.lChild = &node8;

	Recursion2(&node1);
}
int main()
{
	CreateBinaryTree();
	return 0;
}