//#define _CRT_SECURE_NO_WARNINGS 1
//#include"LinkQueue.h"
////初始化
//Node* InitQueue() {
//	Queue* queue = (Queue*)malloc(sizeof(Queue));
//	Node* node = (Node*)malloc(sizeof(Node));
//	queue->head = node;
//	queue->tail = node;
//	node->data = 0;
//	
//	queue->size = 1;
//	
//	return queue;
//}
////入队
//void PushQueue( Queue* queue, DATATYPE data) {
//	if (queue == NULL)
//	{
//		return;
//	}
//	Node* node = (Node*)malloc(sizeof(Node));
//	Node* cur = queue->tail;
//	
//	cur->next= node;
//	//node->next = cur;
//	cur = node;
//	cur->data = data;
//	cur->next = NULL;
//	queue->tail = cur;
//	queue->size++;
//}
////返回队头元素
//Node* FrontQueue( Queue* queue) {
//	if (queue == NULL)
//	{
//		return NULL;
//	}
//	return queue->head;
//}
////出队
//void PopQueue( Queue* queue) {
//	if (queue == NULL)
//	{
//		return;
//	}
//	Node* newTop = queue->head->next;
//	free(queue->head);
//	queue->head = NULL;
//	queue->head = newTop;
//	
//	queue->size--;
//}
////返回队尾元素
//Node* TailQueue( Queue* queue) {
//	if (queue == NULL)
//	{
//		return NULL;
//	}
//	return queue->tail;
//}
////销毁队列
//void DestroyQueue( Queue* queue) {
//	if (queue == NULL)
//	{
//		return;
//	}
//	Node* cur = queue->head;
//	while (cur)
//	{
//		Node* next = cur->next;
//		free(cur);
//		cur = NULL;
//		cur = next;
//	}
//}
////清空队列
//void ClearQueue( Queue* queue) {
//	if (queue == NULL)
//	{
//		return;
//	}
//	Node* cur = queue->head->next;
//	while (cur)
//	{
//		Node* next = cur->next;
//		free(cur);
//		cur = NULL;
//		cur = next;
//		queue->size--;
//	}
//}
//int QueueNum(Queue* queue)
//{
//	if (queue == NULL)
//	{
//		return;
//	}
//	return queue->size;
//}