#include "sort.h"



int main()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int size = sizeof(a) / sizeof(int);
	//InsertSort(a, size);
	//ShellSort(a, size);
	//SelectSort(a, size);
	//HeapSort(a, size);
	//BubbleSort(a, size);
	QuickSort(a, 0, size - 1);
	PrintArray(a, size);

	system("pause");
	return 0;
}