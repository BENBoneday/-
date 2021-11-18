//#define _CRT_SECURE_NO_WARNINGS 1
//#include"TwoWayList.h"
//Node* CreatNewNode(LTDataType x)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (newNode == NULL)
//	{
//		printf("%s", strerror(errno));
//		exit(-1);
//	}
//	newNode->next = NULL;
//	newNode->prev = NULL;
//	newNode->val = x;
//	return newNode;
//}
//Node* ListInit()
//{
//	Node* phead = CreatNewNode(0);
//	phead->next = phead;
//	phead->prev = phead;
//	return phead;
//}
//Node* ListFind(Node* phead,LTDataType x)
//{
//	assert(phead);
//	Node* cur = phead->next;
//	while (cur != phead)
//	{
//		if (cur->val == x)
//		{
//			return cur;
//		}
//		cur = cur->next;
//	}
//	return NULL;
//}
//void ListInsert(Node* phead,LTDataType x,LTDataType data)
//{
//	assert(phead);
//	Node* cur = ListFind(phead,x);
//	if (cur == NULL)
//	{
//		exit(-1);
//	}
//	Node* front = cur->prev;
//
//	Node* newNode = CreatNewNode(data);
//	front->next = newNode;
//	newNode->prev = front;
//
//	newNode->next = cur;
//	cur->prev = newNode;
//}
//void ListErase(Node* phead,LTDataType x)
//{
//	Node* cur = ListFind(phead, x);
//	if (cur == NULL)
//	{
//		exit(-1);
//	}
//	Node* front = cur->prev;
//	Node* frontfront = front->prev;
//
//	frontfront->next = cur;
//	cur->prev = frontfront;
//
//	free(front);
//	front = NULL;
//}
//void ListPushBack(Node* phead, LTDataType x)
//{
//	/*Node* newNode =CreatNewNode(x);
//	Node* tail = phead->prev;
//	tail->next = newNode;
//	newNode->prev = tail;
//	phead->prev = newNode;
//	newNode->next = phead;*/
//	ListInsert(phead, x, x);
//}
//void ListPopBack(Node* phead)
//{
//	assert(phead);
//	assert(phead->next != phead);
//	Node* tail = phead->prev;
//	phead->prev = tail->prev;
//	tail->prev->next = phead;
//	free(tail);
//	tail = NULL;
//}
//void ListPushFront(Node* phead,LTDataType x)
//{
//	Node* newNode = CreatNewNode(x);
//	Node* front = phead->next;
//
//	phead->next = newNode;
//	newNode->prev = phead;
//
//	newNode->next = front;
//	front->prev = newNode;
//}
//void ListPopFront(Node* phead)
//{
//	assert(phead);
//	assert(phead->next!=phead);
//	Node* first = phead->next;
//	Node* second = first->next;
//
//	phead->next = second;
//	second->prev = phead;
//
//	free(first);
//	first = NULL;
//}
//void ListDestroy(Node** phead)
//{
//	assert(*phead);
//	ListClear(*phead);
//	free(*phead);
//	*phead = NULL;
//}
//void ListClear(Node* phead)
//{
//	assert(phead);
//	Node* cur = phead->next;
//	while (cur != phead)
//	{
//		Node* next = cur->next;
//		free(cur);
//		cur = next;
//		next = next->next;
//	}
//	phead->next = phead;
//	phead->prev = phead;
//}
//void ListPrint(Node* phead)
//{
//	assert(phead);
//	Node* cur = phead->next;
//	printf("%d->", phead->val);
//	while (cur != phead)
//	{
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("\n");
//}