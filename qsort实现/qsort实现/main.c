#include <stdio.h>
#include <windows.h>

void Print(int arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int CompInt(const void *_xp, const void *_yp)//用户自己定义的比较函数
{
	int *xp = (int *)_xp;
	int *yp = (int *)_yp;
	return *xp - *yp;
}
void swap(void *_p, void *_q,int size)//无类型交换
{
	char *p = (char *)_p;
	char *q = (char *)_q;//
	for (int i = 0; i < size; i++)
	{
		char temp = *(p + i);
		*(p + i) = *(q + i);
		*(q + i) = temp;//通过两个变量每个字节的内容来交换两个变量当中整体的数据
	}
}
void My_qsort(void *_arr, int num, int size, int(*comp)(const void *, const void *))//无类型排序
{
	char *arr = (char *)_arr;
	for (int i = 0; i < num-1; i++)
	{
		int quit = 0;
		for (int j = 0; j < num - 1 - i; j++)//冒泡排序
		{
			if (comp(arr + j*size, arr + (j + 1)*size) > 0)
			{
				swap(arr + j*size, arr + (j + 1)*size, size);
				quit = 1;
			}
		}
		if (0 == quit) return;
	}
}
int main()
{
	int arr[] = { 2, 3, 1, 5, 6, 3, 7, 2, 4, 8, 0 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Print(arr, num);
	My_qsort(arr, num, sizeof(int), CompInt);
	Print(arr, num);
	system("pause");
	return 0;
}