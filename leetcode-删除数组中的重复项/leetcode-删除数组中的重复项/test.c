#include <stdio.h>
#include <windows.h>
int removeDuplicates(int* nums, int numsSize){
	int i = 1;
	int j = 0;
	for (j = 0; j < numsSize - 1; j++)
	{
		if (nums[j] != nums[j + 1])
		{
			nums[i++] = nums[j + 1];
		}
	}
	return i;
}
void Print(int arr[], int num)
{
	printf("%d\n", num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = {1,1,2 };
	int num = sizeof(arr) / sizeof(arr[0]);
	num = removeDuplicates(arr, num);
	Print(arr, num);
	system("pause");
	return 0;
}