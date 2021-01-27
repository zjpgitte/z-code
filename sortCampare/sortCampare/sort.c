#include "sort.h"
#include "Stack.h"


//直接插入排序
void InsertSort(int *a, int n)
{
	//将下标为i的元素插入到已经拍好序的序列中
	for (int i = 1; i < n;i++)
	{
		//end记录已经排好序的并且未与temp比较元素的下标，初始值为 0
		int end = i - 1;

		//temp记录本趟排序要插入的元素的值为a[end+1],此时end+1位置空余出来
		int temp = a[end + 1];

		while (end >= 0)
		{
			//找比temp小的元素
			if (a[end] > temp)
			{
				//若a[end] > temp，将a[end]向后移到end+1位置处,此时end位置空余出来
				a[end + 1] = a[end];
				end--;
			}
			else//a[end] <= temp，说明找到了比temp小的元素,为a[end]
			{
				break;
			}
		}
		//temp插入到a[end]的后面end+1位置处; 若end = -1，同样插入到end+1位置处
		a[end + 1] = temp;
	}
}

//希尔排序
void ShellSort(int *a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//每次都把间隔为gap的元素进行排序
		gap = gap / 3 + 1;
		for (int i = gap; i < n; ++i)//i是每趟排序待插入元素的下标
		{
			int end = i - gap;//end是待比较元素
			int temp = a[end + gap];//将带插入元素用temp保存
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = temp;

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
	
	//从[begin,end]中选出最小的放到bengin位置处，选出最大的放到end位置处
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;//假设区间的第一个元素就是最大和最小的

		//从[begin,end]选出最大的用maxi记录下标,最小的用mini记录
		for (int i = begin; i <= end;i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		//把最大的放到end，最小的放到begin
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			Swap(&maxi, &mini);
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child+1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int *a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0;i--)
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

//冒泡排序
void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n - 1;i++)
	{
		int change = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				change = 1;
			}
		}
		if (change == 0)
		{
			break;
		}
	}
}
int GetMidIndex(int *a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[mid] < a[left])
	{
		if (a[mid] < a[right])
		{
			if (a[left] < a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (a[mid] >= a[right])
		{
			if (a[left] >= a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
		else
		{
			return mid;
		}
	}
}
//左右指针法
int PartSort1(int *a, int left, int right)
{
	//三数取中,保证right位置处的元素不是最大或最小的
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);

	int keyIndex = right;
	//从左往右找比key大的，从右往左找比key小的,交换两者位置
	while (left < right)
	{
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		Swap(&a[left], &a[right]);
	}

	//将key放到相遇位置
	Swap(&a[left], &a[keyIndex]);
	return left;
}
//挖坑法
int PartSort2(int *a, int left, int right)
{
	//三数取中,保证right位置处的元素不是最大或最小的
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	int key = a[right];//把最右边的元素保存这样最右边就是一个坑
	while (left < right)
	{
		//从左边开始找比key大的
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//找到后填到右边的坑,这样左边就形成了一个坑
		a[right] = a[left];

		//从右边往左找比key小的
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//找到后填到左边的坑，这样右边又形成了一个坑
		a[left] = a[right];
	}
	//key填到最后left和rigright相遇位置的坑
	a[left] = key;
	return left;
}
//前后指针法
int PartSort3(int *a, int left, int right)
{
	//三数取中,保证right位置处的元素不是最大或最小的
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	int keyIndex = right;
	int cur = left;
	int prev = left - 1;//prev是比key小的最后一个元素,prev+1是比key大的第一个元素
	//cur从第一个位置找比key小的放到prev+1的位置处
	while (cur < right)
	{
		if (a[cur] < a[keyIndex] &&  ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev + 1], &a[keyIndex]);
	return prev + 1;
}
void QSort(int *a, int left, int right)
{
	//递归出口,只剩一个元素不排序
	if (left >= right)
	{
		return;
	}
	int midIndex = PartSort3(a, left, right);
	QSort(a, left, midIndex - 1);
	QSort(a, midIndex + 1,right);
}
//快速排序
void QuickSort(int *a, int n)
{
	int left = 0;
	int right = n - 1;
	QSortNonR(a, left, right);
}
//快速排序非递归
//递归转化为非递归两种方式：1.循环（斐波那契） 2.用栈模拟
//非递归的好处：1.提高效率省去了开辟栈帧的时间(但是提高的比较少)
			//  2.内存中栈的空间是非常小的一般是M级别（8M），而堆空间是G级别的
			//  3.用栈模拟非递归消耗的是堆空间可以有效防止栈溢出。
void QSortNonR(int *a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		int midIndex = PartSort3(a, left, right);

		//满足[left,midIndex-1] [midIndex+1,right] 时将下层函数参数入栈
		//入栈的区间内的数在下次循环时会进行单趟排序
		//当区间不满足时(区间不存在或区间内只有一个元素)，则不进行入栈操作即下次循环不进行单趟排序
		if (midIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, midIndex+1);
		}
		if (midIndex - 1 > left )
		{
			StackPush(&st, midIndex-1);
			StackPush(&st, left);
		}


	}
}

void SortArray(int *a, int begin1, int end1, int begin2, int end2,int *temp)
{
	int left = begin1;
	int right = end2;
	//[begin1,end1] [begin2,end2] 是两个有序的区间
	//合并成一个有序区间
	int i = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}

	//将两个区间有剩余的数据放到temp数组的后面
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	//将temp数组的内容重新写到 a 数组中
	memcpy(a + left, temp, sizeof(int)*(right - left + 1));
}



void _MergeSort(int *a, int left, int right,int *temp)
{
	if (left >= right)
	{
		return;
	}
	//将整个数组分成两个区间[left,mid] [mid+1,right]
	int mid = (left + right) / 2;

	//对[left,mid]进行归并排序
	_MergeSort(a, left, mid, temp);
	//对[mid+1,right]进行归并排序
	_MergeSort(a, mid+1, right, temp);

	//当[left,mid]和[mid+1,right]两个区间的数分有序时需要借助辅助数组进行合并使得 [left,right] 整个区间的数都是有序的	
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	SortArray(a, begin1, end1, begin2, end2, temp);
}

//归并递归排序
//归并排序的时间复杂度：O(N*logN)
//可以认为最后一次合并的时间复杂度O(N),倒数第二三次的时间复杂度为O(N/2)，那么第二层的时间复杂的为O(N)
//递归树的层数为O(logN)，则总的时间复杂度为O(N*logN)

void MergeSort(int *a, int n)
{
	int *temp = malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1,temp);

}

//归并非递归排序
void MergeSortNonR(int *a, int n)
{
	int *temp = malloc(sizeof(int)*n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			
			//合并的时候是进行两个数组的合并，如果第二个数组的范围不存在(即第二个数组不存在)则不进行合并 
			//这种情况下第一个数组的范围的右区间end2可能存在也可能不存在
			//但是不论它是否存在，只要第二个数组不存在就不进行合并
			if (begin2 >= n)
			{
				break;
			}

			//走到这说明第二个数组的左区间存在右区间不存在,此时第二个数组存在仅仅是元素的个数与第一个数组不同
			//需要修正右区间的大小为n-1保证它不越界，然后再和第一个数组合并 。合并的时候两个数组元素的个数不一定相同
			if (end2 >= n)
			{
				end2 = n-1;
			}
			
			//两个区间进行合并排序
			SortArray(a, begin1, end1, begin2, end2, temp);
		}
		gap *= 2;
	}
	

}