#include "sort.h"

void InsertSortTest()
{
	int a[] = { 9, 1, 5, 2, 6, 3, 7, 2, 8 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);
	//InsertSort(a, size);
	ShellSort(a, size);
	PrintArray(a, size);
}

void SelectSortTest()
{
	int a[] = { 9, 1, 5, 2, 6, 3, 7, 2, 8 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);
	HeapSort(a, size);
	//SelectSort(a, size);
	PrintArray(a, size);
}

void SortTime()
{
	int n = 100000;
	srand((unsigned)time(NULL));
	int *a1 = malloc(sizeof(int)*n);
	int *a2 = malloc(sizeof(int)*n);
	for (int i = 0; i < n;++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
	}
	int begin = clock();
	InsertSort(a1, n);
	int end = clock();
	printf("InsertSort:%d\n", end - begin);
	begin = clock();
	ShellSort(a2, n);
	end = clock();
	printf("ShellSort:%d\n", end - begin);
}

int main()
{

	//InsertSortTest();
	SelectSortTest();
	//SortTime();
	
	system("pause");
	return 0;
}