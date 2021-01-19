#include "sort.h"

void PrintArray(int *a, int n)
{
	for (int i = 0; i < n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

//直接插入排序
//时间复杂度 O(N^2)    n个元素每次都要和已经排好序的元素进行比较然后插入
//数组已经有序或接近有序情况最好: O(N)
//数组是逆序或接近逆序情况最坏： O(N^2)
void InsertSort(int *a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1;++i)//每将 i+1 位置的元素插入到往已经排好序的元素当中插入
	{
		//单趟排序 
		int end = i; 
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])//
			{
				a[end + 1] = a[end];//后移一位
				--end;
			}
			else
			{
				break;
			}
		}
		//可能是tmp >= a[end] ，也可能是 end 走到了 -1,最终结果都是将tmp放到end+1位置处
		a[end + 1] = tmp;
	}
	
}

//希尔排序
void ShellSort(int *a, int n)
{
	assert(a);
	int gap = n;//每趟排序是间隔为gap的元素进行排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		
		//预排序：每次对间隔为gap的元素进行排序,使整体接近有序
		//最后一次gap = 1,相当于是进行直接插入排序,可以直接排好序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];//将end + gap 位置的元素插入已经排好序的元素序列中
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;  //
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

void SelectSort(int *a, int n)
{
	int begin = 0;
	int end = n - 1;
	int maxi = 0;
	int mini = 0;
	while (begin < end)
	{
		maxi = mini = begin;
		//找最大和最小的元素
		for (int i = begin+1; i <= end;i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			Swap(&mini, &maxi);
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}

}

void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n && a[child+1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}

void HeapSort(int *a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}