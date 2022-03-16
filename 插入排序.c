#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void InsertSort(int* a,int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else break;
		}
		a[end + 1] = temp;
	}

}
void Print(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);

	}
	printf("\n");
}
void Test()
{
	int a[] = { 3,6,4,5,8,9,44,6 };
	InsertSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}
int main()
{
	Test();
	return 0;
}