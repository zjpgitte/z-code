#include "heap.h"
//��ӡ��
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
//����
void Swap(HPDataType *x, HPDataType *y)
{
	HPDataType temp = *x;
	*x = *y;
	*y = temp;
}
//����С��
void HeapInit(Heap *php, int *a, int asize)
{
	assert(php && a);
	php->_data = (HPDataType *)malloc(sizeof(HPDataType)*asize);
	if (php->_data == NULL)
	{
		printf("malloc error!\n");
		exit(0);
	}
	memcpy(php->_data, a, sizeof(HPDataType)*asize);//������Ԫ�ؿ�������
	php->_size = asize;
	php->_capacity = asize;
	for (int i = (asize - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(php->_data, php->_size, i);
	}//�����һ��������ʼ�������µ����㷨
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
//����
void HeapPush(Heap *php, int x)
{
	assert(php);
	HeapCheckCapacity(php);
	php->_data[php->_size++] = x;
	AdjustUp(php->_data, php->_size, php->_size - 1);
}
//ɾ��
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
//ȡ�Ѷ�Ԫ��
HPDataType HeapTop(HPDataType *a)
{
	assert(a);
	return a[0];
}
//�ѵ�Ԫ�ظ���
int Heapsize(Heap *php)
{
	assert(php);
	return php->_size;
}
//�ѵ��п�
int HeapEmpty(Heap *php)
{
	assert(php);
	return !php->_size;
}
//������
void HeapSort(int *a, int asize)
{
	assert(a);
	//����Ԫ�ؽ���
	for (int i = (asize - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, asize, i);
	}
	
	//�ѵ�ͷβ��������������βԪ�ص������µ���ʹ֮��ΪС��
	int end = asize - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, --asize, 0);
		end--;
	}
}
//���µ����㷨(ǰ�᣺root������������ΪС��)
void AdjustDown(int *a, int asize, int root)//root��Ҫ��������������
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < asize)//ѭ���������������ĸ߶ȴ�ʱ�临�Ӷ���O(logN)
	{
		if (child +1 < asize && a[child + 1] < a[child])
		{
			child++;
		}//child��ֵ��С���Ǹ�����
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}//�����ӱ�˫��С�򽻻����Ӻ�˫�׵�ֵʹ֮��ΪС��
		else
		{
			break;
		}//�����ӱ�˫��С������˫�׵����������Ѿ�С�������������ٽ��е�����
	}
}
//���ϵ����㷨 ǰ�᣺leafһ�����������һ�����,���в�����leaf������������ɵ�����С��
void AdjustUp(int *a, int asize, int leaf)
{
	assert(a);
	int child = leaf;
	int parent = (child - 1) / 2;
	while (child > 0)//���������ĸ߶ȴ�ѭ��ʱ�临�Ӷ�logN
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}//�����ӱ�˫��С�����Ӻ�˫�׵�ֵ����
		else
		{
			break;
		}
	}
}
//TopK����
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	for (int i = (k - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(a, k, i);
	}//������a��ǰK��Ԫ�ؽ���С��
	printf("����ǰ��");
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
	printf("�����:");
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}