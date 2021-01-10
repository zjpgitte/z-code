#include "heap.h"
void HeapPrint(Heap *php)
{
	assert(php);
	for (int i = 0; i < php->_size; i++)
	{
		printf("%d ", php->_a[i]);
	}
	printf("\n");
}


void Swap(HPDataType *x, HPDataType *y)
{
	HPDataType temp = *x;
	*x = *y;
	*y = temp;
}

//对小堆使用向下调整算法(使用前提是根的左右子树均为小堆或者为叶子结点)
//时间复杂度为logN
void AdjustDown(HPDataType *a, int size, int root)//
{
	assert(a);
	int parent = root;//记录双亲结点位置
	int child = 2 * parent + 1;//记录值较小的孩子的位置
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child++;
		}//找到值较小的孩子的位置

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}//保证双亲的值比孩子小
		else
		{
			break;
		}
	}

}

//堆的创建(小堆)
//建堆的时间复杂度为O(N)不是O(NlogN)
//原因是每次向下调整的根位置不同则调整次数也不同
void HeapInit(Heap *php, int *a, int n)
{
	assert(php && a);
	//初始化堆中的元素
	php->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	if (php->_a == NULL)
	{
		printf("malloc error!\n");
		exit(0);
	}
	memcpy(php->_a, a, sizeof(HPDataType)*n);//将数组中的元素初始化到堆当中
	php->_size = n;
	php->_capacity = n;

	//创建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, n, i);
	}//将每个子树都调整为小堆
	
}

//堆的销毁
void HeapDestory(Heap *php)
{
	assert(php);
	free(php->_a);
	php->_size = 0;
}
void AdjustUp(int *a, int size, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)//child走到根结束
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//压入元素
void HeapPush(Heap *php, int x)
{
	assert(php);
	php->_a[php->_size++] = x;
	AdjustUp(php->_a, php->_size, php->_size - 1);
}
//弹出堆顶元素
void HeapPop(Heap *php)
{
	assert(php);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
//取堆顶元素
HPDataType HeapTop(Heap *php)
{
	assert(php);
	return php->_a[0];
}
//堆的数据个数
int Heapsize(Heap *php)
{
	return php->_size;
}
//堆的判空
int HeapEmpty(Heap *php)
{
	assert(php);
	return !php->_size;
}

//对含有n个元素的数组排序(堆排序)
void HeapSort(int *a, int n)
{
	assert(a);
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//排序的关键堆顶和堆尾交换后使用向下调整算法这样时间复杂度为O(NlogN)最小
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}//时间复杂度O(NlogN)
}