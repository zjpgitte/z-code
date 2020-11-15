#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>

int CompareInt(const void *_xp, const void *_yp)
{
	int *xp = (int *)_xp;
	int *yp = (int *)_yp;
	return *xp - *yp;
}
void Print(int arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int CompStr(const void *_xp, const void *_yp)
{
	char *s1 = *(char **)_xp;
	char *s2 = *(char **)_yp;//*(char **)_yp == str[i]   (char **)_yp == &str[i]
	return *s1 - *s2;
}
int main()
{
	char *str[] = { "hello", "world", "yes" ,"a"};
	int num = sizeof(str) / sizeof(str[0]);
	qsort(str, num, sizeof(char *), CompStr);
	/*int arr[] = { 8, 9, 4, 7, 9, 3, 5, 8, 2, 1 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Print(arr, num);
	qsort(arr, num, sizeof(int), CompareInt);
	Print(arr, num);*/
	
	system("pause");
	return 0;
}