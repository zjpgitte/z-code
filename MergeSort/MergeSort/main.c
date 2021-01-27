#include <stdio.h>                                                                                                
#include <stdlib.h>    
#include <malloc.h>    
#include <string.h>    

void _MergeSort(int *a, int left, int right, int *temp);


void PrintArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void MergeSortArray(int *a, int begin1, int end1, int begin2, int end2, int *temp)
{
	int i = 0;

	//将a数中两个不同区间的元素按顺序放到temp数组中    
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}

	//将剩余数组中的剩余元素放到temp中
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	//再将temp元素放回原数组
	memcpy(a + begin1, temp, sizeof(int)*i);
}
void _MergeSort(int *a, int left, int right, int *temp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;

	//将左区间排成有序，将右区间排成有序
	_MergeSort(a, left, mid, temp);
	_MergeSort(a, mid + 1, right, temp);

	//数组左右两部分已经有序,进行合并
	MergeSortArray(a, left, mid, mid + 1, right, temp);
}

void MergeSort(int *a, int n)
{
	int *temp = (int*)malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1, temp);
}

int main()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(a) / sizeof(a[0]);

	printf("排序前:");
	PrintArray(a, size);

	MergeSort(a, size);


	printf("排序后:");
	PrintArray(a, size);

	system("pause");
	return 0;
}