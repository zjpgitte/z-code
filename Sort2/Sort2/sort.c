#include "sort.h"

void PrintArray(int *a, int n)
{
	for (int i = 0; i < n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//直接插入排序
void InsertSort(int *a, int n)
{
	for (int i = 0; i < n - 1;++i)
	{
		int end = i;
		int tmp = a[end + 1];//tmp是将要插入了元素
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;//end+1是插入的位置
	}
}

//希尔排序
void ShellSort(int *a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//当gap不等于1的时候进行的是预排序
		//gap = 1进行直接插入排序
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap;++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void Swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

//直接选择排序
void SelectSort(int *a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}

		Swap(&a[max], &a[end]);
		//如果min就是end，那么上次交换后最小元素就换到了之前最大元素的那个位置
		//这时需要调整min的位置
		if (min == end)
		{
			Swap(&max, &min);
		}
		Swap(&a[min], &a[begin]);
		begin++;
		end--;
	}
}

//堆排序
void HeapSort(int *a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;//记录未排序的最后一个元素
	int size = n;//未排序的元素的个数
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//交换堆顶的堆尾
		size--;
		AdjustDown(a, size, 0);//选最大的元素
		end--;
	}
}
//向下调整算法
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;

	while (child < n)
	{
		//找左右孩子中较大的
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		//孩子比双亲大交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		//双亲已经大于孩子，由于左右子树已经是大堆直接退出循环
		else
		{
			break;
		}
	}
}

//冒泡
void BubbleSort(int *a, int n)
{
	for (int j = 0; j < n - 1;j++)
	{
		int change = 0;
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				change = 1;
			}
		}
		if (change == 0)
		{
			break;
		}
	}
	
}
