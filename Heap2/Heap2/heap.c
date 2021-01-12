#include "heap.h"
//打印堆
void HeapPrint(Heap *php)
{
	assert(php);
	for (int i = 0; i < php->_size; i=2*i+1)
	{
		for (int j = i; j <= 2 * i && j < php->_size; j++)
		{
			printf("%3d", php->_data[j]);
		}
		printf("\n\n");
	}
	printf("\n");
}
//交换
void Swap(HPDataType *x, HPDataType *y)
{
	HPDataType temp = *x;
	*x = *y;
	*y = temp;
}
//创建小堆
void HeapInit(Heap *php, int *a, int asize)
{
	assert(php && a);
	php->_data = (HPDataType *)malloc(sizeof(HPDataType)*asize);
	if (php->_data == NULL)
	{
		printf("malloc error!\n");
		exit(0);
	}
	memcpy(php->_data, a, sizeof(HPDataType)*asize);//将数组元素拷贝到堆
	php->_size = asize;
	php->_capacity = asize;
	for (int i = (asize - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(php->_data, php->_size, i);
	}//从最后一个树根开始进行向下调整算法
}
void HeapCheckCapacity(Heap *php)
{
	assert(php);
	if (php->_size >= php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType *temp = (HPDataType*)realloc(php->_data, sizeof(HPDataType)*php->_capacity);
		if (temp == NULL)
		{
			printf("malloc error!\n");
			exit(-1);
		}
		php->_data = temp;
	}
}
//插入
void HeapPush(Heap *php, int x)
{
	assert(php);
	HeapCheckCapacity(php);
	php->_data[php->_size++] = x;
	AdjustUp(php->_data, php->_size, php->_size - 1);
}
//删除
void HeapPop(Heap *php)
{
	assert(php);
	if (HeapEmpty(php))
	{
		return;
	}
	Swap(&php->_data[0], &php->_data[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_data, php->_size, 0);
}
//取堆顶元素
HPDataType HeapTop(HPDataType *a)
{
	assert(a);
	return a[0];
}
//堆的元素个数
int Heapsize(Heap *php)
{
	assert(php);
	return php->_size;
}
//堆的判空
int HeapEmpty(Heap *php)
{
	assert(php);
	return !php->_size;
}
//堆排序
void HeapSort(int *a, int asize)
{
	assert(a);
	//数组元素建堆
	for (int i = (asize - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, asize, i);
	}
	
	//堆的头尾交换将不包括堆尾元素的数向下调整使之成为小堆
	int end = asize - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, --asize, 0);
		end--;
	}
}
//向下调整算法(前提：root的左右子树均为小堆)
void AdjustDown(int *a, int asize, int root)//root是要调整的数的树根
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < asize)//循环的最大次数是树的高度次时间复杂度是O(logN)
	{
		if (child +1 < asize && a[child + 1] < a[child])
		{
			child++;
		}//child是值较小的那个孩子
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}//若孩子比双亲小则交换孩子和双亲的值使之成为小堆
		else
		{
			break;
		}//若孩子比双亲小，由于双亲的左右子树已经小堆了所以无需再进行调整了
	}
}
//向上调整算法 前提：leaf一般是树的最后一个结点,树中不包含leaf结点的其余结点组成的树是小堆
void AdjustUp(int *a, int asize, int leaf)
{
	assert(a);
	int child = leaf;
	int parent = (child - 1) / 2;
	while (child > 0)//最多进行树的高度次循环时间复杂度logN
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}//若孩子比双亲小将孩子和双亲的值交换
		else
		{
			break;
		}
	}
}
//TopK问题
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	for (int i = (k - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(a, k, i);
	}//将数组a的前K个元素建成小堆
	printf("排序前：");
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = k; i < n;++i)
	{
		if (a[i] > a[0])
		{
			Swap(&a[i], &a[0]);
			AdjustDown(a, k, 0);
		}
	}
	printf("排序后:");
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}