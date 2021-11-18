//#define _CRT_SECURE_NO_WARNINGS 1
//#include"singleList.h"
////申请一个新结点
//Node* BuyListNode(SListDataType x)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (newNode == NULL)
//	{
//		printf("%s", strerror(errno));
//		exit(-1);
//	}
//	newNode->data = x;
//	newNode->next = NULL;
//	return newNode;
//}
////尾插
//void SListPushBack(Node** pphead, SListDataType x)
//{
//	Node* newNode = BuyListNode(x);
//	if (*pphead == NULL)
//	{
//		*pphead = newNode;
//	}
//	else
//	{
//		Node* tail = *pphead;
//		while (tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//		tail->next = newNode; 
//	}
//}
////尾删
//void SListPopBack(Node** pphead)
//{
//	//1.空节点
//	if (*pphead == NULL)
//	{
//		return;
//	}
//	//2.有一个节点
//	else if ((*pphead)->next == NULL)
//	{
//		free(*pphead);
//		(*pphead) = NULL;
//	}
//	//有一个以上结点
//	else if((*pphead)->next != NULL)
//	{
//		Node* tail = *pphead;
//		Node* preu = NULL;
//		while (tail->next != NULL)
//		{
//			preu = tail;
//			tail = tail->next;
//		}
//		free(tail);
//		
//		preu->next = NULL;
//	}
//	
//
//}
////头插
//void SListPushFront(Node** pphead, SListDataType x)
//{
//	Node* newNode = BuyListNode(x);
//	
//	newNode->next = *pphead;
//	*pphead = newNode;
//}
////头删
//void SListPopFront(Node** pphead)
//{
//	
//	
//	if ((*pphead) == NULL)
//	{
//		return;
//	}
//	Node* tmp = (*pphead)->next;	
//	free(*pphead);
//	*pphead = tmp;
//	
//}
////查找
//Node* SListFind(Node* phead,SListDataType x)
//{
//	if (phead == NULL)
//	{
//		return;
//	}
//	else
//	{
//		Node* cur = phead;
//		while (cur)
//		{
//			if (cur->data == x)
//			{
//				return cur;
//			}
//			cur = cur->next;
//		}
//		return NULL;
//	}
//}
////插入
//void SListInsertAfter(Node* pos,SListDataType x)
//{
//	assert(pos);
//	Node* newNode = BuyListNode(x);
//	newNode->next = pos->next;
//	pos->next = newNode;
//}
////删除
//void SListEraseAfter(Node* pos)
//{
//	assert(pos);
//	if (pos->next)
//	{
//		Node* next = pos->next;
//		Node* nextnext = next->next;
//		pos->next = nextnext;
//		free(next);
//	}
//}
////打印
//void SListPrint(Node* phead)
//{
//	Node* cur = phead;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}