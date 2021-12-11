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
	//写

	int i;
	int val;
	int size = 1;
	linkList* h = (linkList*)malloc(sizeof(linkList));//头结点
	if (h == NULL)
	{
		printf("error");
		exit(-1);
	}
	h->data = 0;
	h->next = NULL;//初始化
	linkList* cur = h;
	//head->data
	while (1)
	{
		scanf("%d", &val);//输入结点值
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
		node->next = NULL;//尾插
		size++;
	}
	Print(h);
	Sort(h, size);//排序
	FILE* fp = fopen("a.bf", "wb");//写文件2进制
	cur = h;
	
	while (cur != NULL)
	{
		fwrite(cur, sizeof(linkList), 1, fp);
		cur = cur->next;
	}//写链表
	
	Print(h);
	cur = h;
	linkList* next = cur->next;
	while (next != NULL)
	{
		
		free(cur);
		cur = next;
		next = next->next;
	}//释放空间
	
	
	fclose(fp);


	//读

	/****************************************************/
	/********************读和写的代码不能同时运行********/
	/****************************************************/
	int read_max = 6;
	linkList* l = (linkList*)malloc(sizeof(linkList) * read_max);//创建从文件接收的结点
	
	if (l == NULL)
	{
		exit(-1);
	}
	FILE* fp = fopen("a.bf", "rb");
	//linkList* cur = l;
	for (int i = 0; i < read_max; i++)//读出
	{
		fread(&l[i], sizeof(linkList), 1, fp);
		//cur = cur->next;
	}
	for (int i = 0; i <read_max; i++)//打印
	{
		printf("%d->", l[i].data);
	}
	printf("NULL");
	//Print(&l);
	free(l);
	fclose(fp);
	return 0;
}