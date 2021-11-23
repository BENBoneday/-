#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<sys/timeb.h>
#define MAX 10

void Print(int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void ShellSort(int arr[],int length)
{
	int increasement=length;
	int i, j, k;
	do
	{
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++)
		{
			for (j = i + increasement; j<length; j += increasement)
			{
				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
					{
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement>1);
}
int main()
{
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int randNum = rand() % MAX;
		arr[i] = randNum;
	}
	//int arr1[10] = { 3,3,55,6,48,88,99,100,0,77 };
	Print(arr, MAX);
	ShellSort(arr, MAX);
	Print(arr, MAX);
	return 0;
}