//#define _CRT_SECURE_NO_WARNINGS 1
//#include"stack.h"
//void StackInit(ST* ps) 
//{
//	assert(ps);
//	ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
//	if (ps->data == NULL)
//	{
//		exit(-1);
//	}
//	ps->capacity = 4;
//	ps->top = 0;
//}
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->data);
//	ps->data = NULL;
//	ps->capacity = 0;
//	ps->top = 0;
//}
////ÈëÕ»
//void StackPush(ST* ps, STDataType data)
//{
//	assert(ps);
//	if (ps->capacity == ps->top)
//	{
//		STDataType* tmp = (STDataType*)realloc(ps->data, ps->capacity * 2 * sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			exit(-1);
//		}
//		else
//		{
//			ps->data = tmp;
//			ps->capacity *= 2;
//		}
//	}
//	ps->data[ps->top] = data;
//	ps->top++;
//	//ps->capacity++;
//	
//}
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	/*if (ps->capacity == 0)
//	{
//		return;
//	}*/
//	ps->top--;
//}
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	return ps->data[ps->top-1];
//}
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//bool StackEmpty(ST* ps)
//{	
//	assert(ps);
//	return ps->top==0;
//}
