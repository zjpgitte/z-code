#include <stdio.h>
#include <windows.h>
#include <stdio.h>
int CompareInt(const void *_p, const void *_q)//用户写的比较某两个数据的函数，比较的是什么类型由用户决定，此函数的两个参数是用来接收待比较的两个数据的起始地址
{											//void* 可以接受任意类型通常用来接收指针
	const int *p = (int *)_p;
	const int *q = (int *)_q;//用户要比较什么类型的数据就定义什么类型的数据
	return *p - *q;
}
void Printnum(int arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void my_qsort(void *_arr, int num, int size, int Compare(void *,void *))
{
	if (NULL == _arr)
	{
		return;
	}
	char *arr = (char *)_arr;           
	for (int i = 0; i < num - 1; i++)//这里使用冒泡排序
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (CompareInt(arr+j*size,arr+(j+1)*size) < 0)//比较的是什么类型的元素由用户决定，我们只提供比较的两的元素的首地址
			{
				char *temp1 = arr + j*size;//这里我们只知道两个待比较变量的首地址以及大小(size)，因此我们只能通过交换
				char *temp2 = arr + (j + 1)*size;//两个变量每个字节的内容进而将两个变量进行交换
				int _size = size;
				while (_size)
				{
					char temp = *temp1;
					*temp1 = *temp2;
					*temp2 = temp;
					temp1++;
					temp2++;
					_size--;
				}
			}
		}
	}
}
int main()
{
	int arr[] = { 2, 4, 2, 1, 6, 5, 9, 8, 5, 2, 9 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Printnum(arr, num);
	my_qsort(arr, num, sizeof(int), CompareInt);//任意类型数组中元素排序，arr可以是任意类型的数组，第三个参数是数组类型大小，它决定比较几个字节
	Printnum(arr, num);
	system("pause");
	return 0;
}