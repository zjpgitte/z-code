#include "sort.h"
//void sort()
//{
//
//	ShellSort(a, size);
//
//	SelectSort(a, size);
//
//	HeapSort(a, size);
//
//	BubbleSort(a, size);
//
//	QuickSort(a, 0, size - 1);
//}
void PrintArray(int *a, int size)
{
	for (int i = 0; i < size;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	//int a[] = { 5, 2, 4, 6, 1, 3 };
	int a[] = { 5, 2, 4, 6,3,1};
	int size = sizeof(a) / sizeof(a[0]);

	printf("ÅÅÐòÇ°:");
	PrintArray(a, size);//´òÓ¡ÅÅÐòÇ°
	//InsertSort(a, size);
	//ShellSort(a, size);
	//SelectSort(a, size);
	//HeapSort(a, size);
	//BubbleSort(a, size);
	//QuickSort(a, size);
	//MergeSort(a, size);
	MergeSortNonR(a, size);
	printf("ÅÅÐòºó:");
	PrintArray(a, size);//´òÓ¡ÅÅÐòºó

	system("pause");
	return 0;
}