#include<stdio.h>
#include<windows.h>
#define MAX 20
//int func(int arr[],int num)
//{
//	int arr1[MAX];
//	int j = 0;
//	for (int i = 0; i < num; i++)
//	{
//		if (arr[i] % 2 != 0)
//		{
//			arr1[j++] = arr[i];
//		}
//	}
//	for (int i = 0; i < num; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			arr1[j++] = arr[i];
//		}
//	}
//	for (int i = 0; i < num; i++)
//	{
//		arr[i] = arr1[i];
//	}
//}
void func(int arr[], int num)
{
	int left = 0;
	int right = num - 1;
	while (left < right)
	{
		if (arr[left] % 2 != 0)
		{
			left++; continue;
		}
		if (arr[right] % 2 == 0) 
		{
			right--; continue;
		}
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;

	}

}
int main()
{
	int arr[] = { 1, 2, 4, 5, 6, 17, 7 };
	int num = sizeof(arr) / sizeof(arr[0]);
	func(arr, num);
	for (int i = 0; i < num;i++)
	printf("%d ", arr[i]);
	system("pause");
	return 0;
}