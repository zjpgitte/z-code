#include <stdio.h>
#include <windows.h>
//折半查找
void BinarySearch(int arr[], int num, int n)
{
	int start = 0;
	int end = num - 1;
	int mid = (start + end) / 2;
	while (start <= end)
	{
		if (n > arr[mid])
		{
			start = mid + 1; // 这里因为我们已经确定 arr[mid] 不是要找的所以更新start的时候赋值为mid+1.下面更新end时同理。
			mid = (start + end) / 2;
		}
		else if (n < arr[mid])
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else
		{
			printf("下标：%d\n", mid);
			break;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 89, 367 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int n = 1;
	BinarySearch(arr, num,n);
	system("pause");
	return 0;
}