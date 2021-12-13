#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct LINKLIST
{
	struct LINKLIST* next;
	int data;
}linkList;
linkList* Init()
{
	linkList* head = (linkList*)malloc(sizeof(linkList));
		head->data = 0;
		linkList* node = (linkList*)malloc(sizeof(linkList));
		node->data = 44;
		head->next = node;
		linkList* node1 = (linkList*)malloc(sizeof(linkList));
		node1->data = 5;
		node->next = node1;
		linkList* node2 = (linkList*)malloc(sizeof(linkList));
		node2->data = 9;
		node1->next = node2;
		node2->next = NULL;
		return head;
}
linkList* Init1()
{
	linkList* head = (linkList*)malloc(sizeof(linkList));
	head->data = 6;
	linkList* node = (linkList*)malloc(sizeof(linkList));
	node->data = 4;
	head->next = node;
	linkList* node1 = (linkList*)malloc(sizeof(linkList));
	node1->data = 3;
	node->next = node1;
	linkList* node2 = (linkList*)malloc(sizeof(linkList));
	node2->data = 9;
	node1->next = node2;
	node2->next = NULL;
	return head;
}

linkList* CmSet(linkList* D,linkList* S,int sizeD,int sizeS)
{
	linkList* head = (linkList*)malloc(sizeof(linkList));
	if (head == NULL)
	{
		return NULL;
	}
	head->data = 0;
	linkList* curD = D;
	linkList* curS = S;
	linkList* curN = head;
	int count = 0;
	while (curD)
	{
		while (curS)
		{
			if (curD->data != curS->data)
			{
				count++;
			}
			curS = curS->next;
		}
		if (count == sizeS)
		{
			linkList* newNode = (linkList*)malloc(sizeof(linkList));
			curN->next = newNode;
			newNode->data = curD->data;
			curN = newNode;
			curN->next = NULL;
		}
		curD = curD->next;
		curS = S;
		count = 0;
	}
	linkList* newHead = head->next;
	free(head);
	return newHead;
}
void Destroy(linkList* l)
{
	if (l == NULL)
	{
		return;
	}
	linkList* cur = l;
	linkList* next = cur->next;
	while (next)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
}
void Print(linkList* l)
{
	if (l == NULL)
		return;
	linkList* cur = l;
	
	while (cur!=NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
int main()
{
	linkList* D=Init();
	linkList* S=Init1();
	char str[1024] = { 0 };
	linkList* ret = CmSet(D, S,4,4);
	Print(D);
	Print(S);
	Print(ret);
	FILE* fp = fopen("b.txt", "w");
	linkList* cur = ret;
	
	while (cur)
	{
		sprintf(str ,"%d->",cur->data);
		fputs(str, fp);
		cur = cur->next;
	}
	sprintf(str, "%s", "NULL");
	fputs(str, fp);
	
	fclose(fp);
	Destroy(D);
	Destroy(S);
	Destroy(ret);
	return 0;
}