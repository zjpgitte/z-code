#include <stdio.h>
#include <windows.h>
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次
//编写一个函数找出这两个只出现一次的数字。
void SearchSingle(int arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		int tag = 0;
		for (int j = 0; j < num; j++)
		{
			if (arr[j] == arr[i] && ( i != j))
			{
				tag = 1;
				break;
			}
		}
		if (0 == tag)
		{
			printf("%d\n", arr[i]);
		}
	}
}
int main()
{
	int arr[] = { 1,  3, 1, 3, 4, 5,  6, 7,5, 7 };
	int num = sizeof(arr) / sizeof(arr[0]);
	SearchSingle(arr,num);
	system("pause");
	return 0;
}