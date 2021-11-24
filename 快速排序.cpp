#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
 
using namespace std;

void printArray(int arr[],int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void QuickSort(int arr[], int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];
	//һ�����ֲ�����
	if (i < j)
	{
		//iʼ�ձ�jС
		while (i < j)
		{
			//���������ұ�tempС�����ַŵ����
			while (i<j && arr[j]>temp)
			{
				j--;
			}
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}
			//���������ұ�temp������ַ��ұ�
			while (i < j && arr[i] < temp)
			{
				i++;
			}
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
			
		}
		arr[i] = temp;
		//��벿������
		QuickSort(arr, start, i-1);
		//�Ұ벿������
		QuickSort(arr, i + 1, end);
	}
}
int main(void)
{
	int arr[] = {66,22,313,33,8,6,15,34};
	int legth = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, legth);
	QuickSort(arr, 0, legth - 1);
	printArray(arr, legth);
}
