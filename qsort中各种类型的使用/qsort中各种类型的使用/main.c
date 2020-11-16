#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
void PrintInt(int *arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void PrintFloat(float arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%.3f ", arr[i]);
	}
	printf("\n");
}
void PrintStr(char *arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
}
int CompareInt(const void*_xp, const void*_yp)
{
	int *xp = (int *)_xp;
	int *yp = (int *)_yp;
	return *xp - *yp;
}
int CompareFloat(const void *_xp, const void *_yp)
{
	float *xp = (float*)_xp;
	float *yp = (float*)_yp;
	return *xp - *yp;
}
int CompareStr(const void *_xp, const void *_yp)
{
	char *xp = *(char **)_xp;
	char *yp = *(char **)_yp;
	return *xp - *yp;
}
int main()
{
	int arr1[] = { 7, 9, 10, 3, 2, 5, 1, 5, 7, 2 };
	int num1 = sizeof(arr1) / sizeof(arr1[0]);
	float arr2[] = { 9.8, 2.3, 1.4, 4.5, 7.8, 34, 6, 0 };
	int num2 = sizeof(arr2) / sizeof(arr2[0]);
	char *arr3[] = { "i", "like", "china" };
	int num3 = sizeof(arr3) / sizeof(arr3[0]);
	PrintInt(arr1, num1);
	PrintFloat(arr2, num2);
	PrintStr(arr3, num3);
	qsort(arr1, num1, sizeof(int), CompareInt);
	qsort(arr2, num2, sizeof(float), CompareFloat);
	qsort(arr3, num3, sizeof(char*), CompareStr);
	PrintInt(arr1, num1);
	PrintFloat(arr2, num2);
	PrintStr(arr3, num3);
	system("pause");
	return 0;
}