#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
void BubbleSort(int arr[], int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		int quit = 0;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				quit = 1;
 			}
		}
		if (0 == quit)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 7, 9, 0, 3, 5, 6, 2, 7, 3, 2, 7, 1, 8 };
	int num = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%2d", arr[i]);
	}
	system("pause");
	return 0;
}