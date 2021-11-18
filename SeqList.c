//#define _CRT_SECURE_NO_WARNINGS 1
//#include"SeqList.h"
//void SeqListPushBack(struct SeqList* ps, SLDataType x)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	ps->a[ps->size] = x;
//	ps->size++;
//}
//void SeqListPopBack(SL* ps)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	/*free(ps->a[ps->size-1]);
//	ps->a[ps->size-1] = NULL;*/
//	ps->size--;
//}
//void SeqListPushFront(SL* ps, SLDataType x)
//{
//	assert(ps);
//	SeqListCheckCapacity(ps);
//	int end = ps->size - 1;
//	while (end >= 0)
//	{
//		ps->a[end + 1] = ps->a[end];
//		--end;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}
//void SeqListPopFront(SL* ps)
//{
//	assert(ps);
//	int end =0;
//	while (end <= (ps->size - 1))
//	{
//		ps->a[end] = ps->a[end + 1];
//		++end;
//	}
//	ps->size--;
//}
//void SeqListInsert(SL* ps, size_t pos, SLDataType x)
//{
//	assert(ps);
//	int end = ps->size - 1;
//	{
//		ps->a[end + 1] = ps->a[end];
//		--end;
//	}
//	ps->a[pos] = x;
//	ps->size++;
//}
//void SeqListErase(SL* ps, size_t pos)
//{
//	assert(ps);
//	int start = pos;
//	while (start < ps->size - 1)
//	{
//		ps->a[start] = ps->a[start + 1];
//		start++;
//	}
//	ps->size--;
//}
//void SeqListFind(SL* ps,size_t pos, SLDataType x)
//{
//	//assert(pos < ps->size);
//	SeqListCheckCapacity(ps);
//	int end = ps->size - 1;
//	while (pos <= end)
//	assert(ps);
//	int i = 0;
//	while (i < ps->size)
//	{
//		if (x == ps->a[i])
//		{
//			return 0;
//
//		}
//	}
//	return -1;
//}
//void SeqListInit(SL* s)
//{
//	s->a = (SLDataType*)malloc(sizeof(SLDataType) * INITCAPACITY);
//	if (s->a == NULL)
//	{
//		printf("%s",strerror(errno));
//		exit(-1);
//	}
//	s->size = 0;
//	s->capacity = 4;
//}
//void SeqListDestroy(SL* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
//void SeqListPrint(SL* s)
//{
//	assert(s);
//	int i = 0;
//	for (i = 0; i < s->size; i++)
//	{
//		printf("%d ", s->a[i]);
//	}
//	printf("\n");
//}
//void SeqListCheckCapacity(SL* ps)
//{
//	assert(ps);
//	if (ps->size >= ps->capacity)
//	{
//		ps->capacity *= 2;
//		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
//		if (ps->a == NULL)
//		{
//			printf("%s", strerror(errno));
//			exit(-1);
//		}
//
//	}
//}