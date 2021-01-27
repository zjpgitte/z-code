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

	//��a����������ͬ�����Ԫ�ذ�˳��ŵ�temp������    
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

	//��ʣ�������е�ʣ��Ԫ�طŵ�temp��
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	//�ٽ�tempԪ�طŻ�ԭ����
	memcpy(a + begin1, temp, sizeof(int)*i);
}
void _MergeSort(int *a, int left, int right, int *temp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;

	//���������ų����򣬽��������ų�����
	_MergeSort(a, left, mid, temp);
	_MergeSort(a, mid + 1, right, temp);

	//���������������Ѿ�����,���кϲ�
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

	printf("����ǰ:");
	PrintArray(a, size);

	MergeSort(a, size);


	printf("�����:");
	PrintArray(a, size);

	system("pause");
	return 0;
}