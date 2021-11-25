#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<sys/timeb.h>
#define MAX 20

using namespace std;

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}
int* CreateArr()
{
	int* arr = (int*)malloc(sizeof(int) * MAX);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int randNum = rand() % 10;
		arr[i] = randNum;
	}
	return arr;
}
void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	//记录辅助空间个数
	int length = 0;
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			i_start++;
			length++;
		}
		else
		{
			temp[length] = arr[j_start];
			j_start++;
			length++;
		}

	}
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		length++;
		i_start++;
	}
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}
	//覆盖
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}
void MergeArr(int arr[],int start,int end,int* temp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	//左半部分
	MergeArr(arr, start, mid , temp);
	//右半部分
	MergeArr(arr, mid+1,end, temp);
	Merge(arr, start, end, mid, temp);

}
void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(void)
{
	int* arr = CreateArr();
	int* temp = (int*)malloc(sizeof(int) * MAX);
	printArray(arr, MAX);
	MergeArr(arr, 0, MAX - 1, temp);
	printArray(arr, MAX);
	free(arr);
	free(temp);
}
