#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char STDataType;

typedef struct Stack
{
    STDataType* data;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType data);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);

void StackInit(ST* ps)
{
    assert(ps);
    ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->data == NULL)
    {
        exit(-1);
    }
    ps->capacity = 4;
    ps->top = 0;
}
void StackDestroy(ST* ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = 0;
    ps->top = 0;
}
//ÈëÕ»
void StackPush(ST* ps, STDataType data)
{
    assert(ps);
    if (ps->capacity == ps->top)
    {
        STDataType* tmp = (STDataType*)realloc(ps->data, ps->capacity * 2 * sizeof(STDataType));
        if (tmp == NULL)
        {
            exit(-1);
        }
        else
        {
            ps->data = tmp;
            ps->capacity *= 2;
        }
    }
    ps->data[ps->top] = data;
    ps->top++;
}
void StackPop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}
STDataType StackTop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->data[ps->top - 1];
}
int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;
}
bool StackEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}
bool isValid(char* s)
{
    ST st;
    StackInit(&st);
    while (*s != '\0')
    {
        switch (*s)
        {
        case '{':
        case '[':
        case '(':
        {
            StackPush(&st, *s);
            s++;
            break;
        }
        case '}':
        case ']':
        case ')':
        {
            if (StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            char top = StackTop(&st);
            StackPop(&st);
            if (*s == '}' && top != '{'
                || *s == ']' && top != '['
                || *s == ')' && top != '(')
            {
                StackDestroy(&st);
                return false;
            }
            else
            {
                s++;
            }
            break;
        }
        default:
            break;
        }
    }
    bool ret = StackEmpty(&st);
    StackDestroy(&st);
    return ret;
}
int main()
{
    char* s = "{}";
    bool l = isValid(s);
    printf("%d", l);
    return 0;
}