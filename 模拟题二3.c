#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#define READ_MAX 6
typedef struct LinkList
{
	struct LinkList* next;
	
	int data;
}linkList;

void Sort(linkList* l,int size)
{

	linkList* cur1 = l;
	linkList* cur2 = l;
	int tmp;
	for (; cur1->next!=NULL; cur1=cur1->next)
	{
		for (cur2=cur1->next; cur2!=NULL;cur2=cur2->next)
		{
			if (cur1->data > cur2->data)
			{
				tmp = cur1->data;
				cur1->data = cur2->data;
				cur2->data = tmp;
			}
		}
	}
}
void Print(linkList* l)
{
	linkList* cur = l;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
int main()
{
	//д

	int i;
	int val;
	int size = 1;
	linkList* h = (linkList*)malloc(sizeof(linkList));//ͷ���
	if (h == NULL)
	{
		printf("error");
		exit(-1);
	}
	h->data = 0;
	h->next = NULL;//��ʼ��
	linkList* cur = h;
	//head->data
	while (1)
	{
		scanf("%d", &val);//������ֵ
		if (val == -1)
		{
			break;
		}
		linkList* node = (linkList*)malloc(sizeof(linkList));
		if (node == NULL)
		{
			exit(-1);
		}
		node->data = val;
		cur->next = node;
		cur = cur->next;
		node->next = NULL;//β��
		size++;
	}
	Print(h);
	Sort(h, size);//����
	FILE* fp = fopen("a.bf", "wb");//д�ļ�2����
	cur = h;
	
	while (cur != NULL)
	{
		fwrite(cur, sizeof(linkList), 1, fp);
		cur = cur->next;
	}//д����
	
	Print(h);
	cur = h;
	linkList* next = cur->next;
	while (next != NULL)
	{
		
		free(cur);
		cur = next;
		next = next->next;
	}//�ͷſռ�
	
	
	fclose(fp);


	//��

	/****************************************************/
	/********************����д�Ĵ��벻��ͬʱ����********/
	/****************************************************/
	int read_max = 6;
	linkList* l = (linkList*)malloc(sizeof(linkList) * read_max);//�������ļ����յĽ��
	
	if (l == NULL)
	{
		exit(-1);
	}
	FILE* fp = fopen("a.bf", "rb");
	//linkList* cur = l;
	for (int i = 0; i < read_max; i++)//����
	{
		fread(&l[i], sizeof(linkList), 1, fp);
		//cur = cur->next;
	}
	for (int i = 0; i <read_max; i++)//��ӡ
	{
		printf("%d->", l[i].data);
	}
	printf("NULL");
	//Print(&l);
	free(l);
	fclose(fp);
	return 0;
}